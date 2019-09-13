/*
** EPITECH PROJECT, 2019
** CoreWar
** File description:
** add
*/

#include "../../include/corewar.h"

int set_cycle_add(info_t *info, champ_t *ch, op_t op)
{
    if (ch->save_cycle == -666)
        ch->save_cycle = info->total_cycle;
    if (ch->save_cycle != -666 &&
    ch->save_cycle + op.nbr_cycles > info->total_cycle)
        return (1);
    ch->save_cycle = -666;
    return (0);
}

void add_operation(info_t *info, champ_t *ch, op_t op, int *params)
{
    int i = (ch->pc + 2) % MEM_SIZE;
    int one;
    int two;

    if (info->memory[i] < 1 || info->memory[i] > REG_NUMBER)
        return;
    one = register_to_int(info, ch->registers[info->memory[i] - 1]);
    i = (i + 1) % MEM_SIZE;
    if (info->memory[i] < 1 || info->memory[i] > REG_NUMBER)
        return;
    two = register_to_int(info, ch->registers[info->memory[i] - 1]);
    i = (i + 1) % MEM_SIZE;
    if (info->memory[i] < 1 || info->memory[i] > REG_NUMBER)
        return;
    ch->carry = 0;
    if ((one + two) == 0)
        ch->carry = 1;
    write_in_register(info, one + two, ch->registers[info->memory[i] - 1]);
}

int add_inst(info_t *info, champ_t *ch)
{
    op_t op = op_tab[3];
    int *params = NULL;
    int res = 0;

    if (info->memory[ch->pc] != op.code)
        return (0);
    if (set_cycle_ld(info, ch, op) == 1)
        return (1);
    params = take_parameters(info, ch, op);
    if (verify_parameters(info, ch, op, params) == 84)
        return (0);
    add_operation(info, ch, op, params);
    ch->pc += 5;
    free(params);
    return (1);
}