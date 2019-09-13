/*
** EPITECH PROJECT, 2019
** CoreWar
** File description:
** st
*/

#include "../../include/corewar.h"

int set_cycle_st(info_t *info, champ_t *ch, op_t op)
{
    if (ch->save_cycle == -666)
        ch->save_cycle = info->total_cycle;
    if (ch->save_cycle != -666 &&
    ch->save_cycle + op.nbr_cycles > info->total_cycle)
        return (1);
    ch->save_cycle = -666;
    return (0);
}

void st_change_pc(info_t *info, champ_t *ch, int *params, op_t op)
{
    ch->pc = ch->pc + 1;
    for (int i = 0; i < op.nbr_args; i += 1) {
        if (params[i] == 3)
            ch->pc += IND_SIZE;
        else if (params[i] == 2)
            ch->pc += DIR_SIZE;
        else
            ch->pc += 1;
    }
    ch->pc += 1;
}

void st_operation(info_t *info, champ_t *ch, op_t op, int *params)
{
    int i = (ch->pc + 2) % MEM_SIZE;

    if (info->memory[i] < 1 || info->memory[i] > REG_NUMBER)
        return;
    i = (i + 1) % MEM_SIZE;
    if (params[1] == 1) {
        if (info->memory[i] < 1 || info->memory[i] > REG_NUMBER)
            return;
        my_strcpy(ch->registers[info->memory[i] - 1],
        ch->registers[info->memory[(i - 1) % MEM_SIZE] - 1]);
    } else {
        i -= 1;
        while (i < 0)
            i = MEM_SIZE + i;
        write_in_mem_regsize(info, ch->registers[info->memory[i] - 1],
        (ch->pc + (hex_to_short(info, ch, i + 1) % IDX_MOD)) % MEM_SIZE, ch);
    }
}

int st_inst(info_t *info, champ_t *ch)
{
    op_t op = op_tab[2];
    int *params = NULL;
    int res = 0;

    if (info->memory[ch->pc] != op.code)
        return (0);
    if (set_cycle_st(info, ch, op) == 1)
        return (1);
    params = take_parameters(info, ch, op);
    if (verify_parameters(info, ch, op, params) == 84)
        return (0);
    st_operation(info, ch, op, params);
    st_change_pc(info, ch, params, op);
    free(params);
    return (1);
}