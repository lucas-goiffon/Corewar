/*
** EPITECH PROJECT, 2019
** CoreWar
** File description:
** sti
*/

#include "../../include/corewar.h"

int set_cycle_sti(info_t *info, champ_t *ch, op_t op)
{
    if (ch->save_cycle == -666)
        ch->save_cycle = info->total_cycle;
    if (ch->save_cycle != -666 &&
    ch->save_cycle + op.nbr_cycles > info->total_cycle)
        return (1);
    ch->save_cycle = -666;
    return (0);
}

void sti_change_pc(info_t *info, champ_t *ch, int *params, op_t op)
{
    ch->pc = ch->pc + 1;
    for (int i = 0; i < op.nbr_args; i += 1) {
        if (params[i] == 3)
            ch->pc += IND_SIZE;
        else if (params[i] == 2)
            ch->pc += IND_SIZE;
        else
            ch->pc += 1;
    }
    ch->pc += 1;
}

void sti_operation(info_t *info, champ_t *ch, op_t op, int *params)
{
    int res = 0;
    int i = (ch->pc + 3) % MEM_SIZE;
    if (params[1] == 1) {
        if (info->memory[i] < 1 || info->memory[i] > REG_NUMBER)
            return;
        res = register_to_int(info, ch->registers[info->memory[i] - 1]);
    } else {
        res = hex_to_short(info, ch, i);
        i += 1;
    } i += 1;
    if (params[2] == 1) {
        if (info->memory[i] < 1 || info->memory[i] > REG_NUMBER)
            return;
        res += register_to_int(info, ch->registers[info->memory[i] - 1]);
    } else
        res = res + hex_to_short(info, ch, i);
    i = (ch->pc + 2) % MEM_SIZE;
    if (info->memory[i] < 1 || info->memory[i] > REG_NUMBER)
            return;
    write_in_mem_regsize(info, ch->registers[info->memory[i] - 1],
    ch->pc + (res % IDX_MOD), ch);
}

int sti_inst(info_t *info, champ_t *ch)
{
    op_t op = op_tab[10];
    int *params = NULL;
    int res = 0;

    if (info->memory[ch->pc] != op.code)
        return (0);
    if (set_cycle_sti(info, ch, op) == 1)
        return (1);
    params = take_parameters(info, ch, op);
    if (verify_parameters(info, ch, op, params) == 84)
        return (0);
    sti_operation(info, ch, op, params);
    sti_change_pc(info, ch, params, op);
    free(params);
    return (1);
}