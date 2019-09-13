/*
** EPITECH PROJECT, 2019
** CoreWar
** File description:
** aff
*/

#include "../../include/corewar.h"

int set_cycle_aff(info_t *info, champ_t *ch, op_t op)
{
    if (ch->save_cycle == -666)
        ch->save_cycle = info->total_cycle;
    if (ch->save_cycle != -666 &&
    ch->save_cycle + op.nbr_cycles > info->total_cycle)
        return (1);
    ch->save_cycle = -666;
    return (0);
}

void aff_change_pc(info_t *info, champ_t *ch, int *params, op_t op)
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

void aff_operation(info_t *info, champ_t *ch, op_t op, int *params)
{
    int i = (ch->pc + 2) % MEM_SIZE;

    if (info->memory[i] < 1 || info->memory[i] > REG_NUMBER)
        return;
    my_putchar(register_to_int(info,
    ch->registers[info->memory[i] - 1]) % 256);
}

int aff_inst(info_t *info, champ_t *ch)
{
    op_t op = op_tab[15];
    int *params = NULL;
    int res = 0;

    if (info->memory[ch->pc] != op.code)
        return (0);
    if (set_cycle_aff(info, ch, op) == 1)
        return (1);
    params = take_parameters(info, ch, op);
    if (verify_parameters(info, ch, op, params) == 84)
        return (0);
    aff_operation(info, ch, op, params);
    aff_change_pc(info, ch, params, op);
    free(params);
    return (1);
}