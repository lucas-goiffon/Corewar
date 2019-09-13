/*
** EPITECH PROJECT, 2019
** CoreWar
** File description:
** lld
*/

#include "../../include/corewar.h"

int set_cycle_lld(info_t *info, champ_t *ch, op_t op)
{
    if (ch->save_cycle == -666)
        ch->save_cycle = info->total_cycle;
    if (ch->save_cycle != -666 &&
    ch->save_cycle + op.nbr_cycles > info->total_cycle)
        return (1);
    ch->save_cycle = -666;
    return (0);
}

void lld_change_pc(info_t *info, champ_t *ch, int *params, op_t op)
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

void lld_operation_ind(info_t *info, champ_t *ch)
{
    int i = (ch->pc + 2) % MEM_SIZE;
    int value = 0;

    value = (int)hex_to_short(info, ch, i);
    i = (i + 2) % MEM_SIZE;
    if (info->memory[i] < 1 || info->memory[i] > REG_NUMBER)
        return;
    value = (ch->pc + (value)) % MEM_SIZE;
    for (int j = 0; j < REG_SIZE; j += 1) {
        ch->registers[info->memory[i] - 1][j] = info->memory[value];
        value = (value + 1) % MEM_SIZE;
    }
    ch->carry = 0;
    if (register_to_int(info, ch->registers[info->memory[i] - 1]) == 0)
        ch->carry = 1;
}

void lld_operation(info_t *info, champ_t *ch, op_t op, int *params)
{
    int i = (ch->pc + 2) % MEM_SIZE;
    int value = 0;

    if (params[0] == 2) {
        if (info->memory[(i + REG_SIZE) % MEM_SIZE] < 1 ||
        info->memory[(i + REG_SIZE) % MEM_SIZE] > REG_NUMBER)
            return;
        for (int j = 0; j < REG_SIZE; j += 1) {
            ch->registers[info->memory[(i + REG_SIZE - j) % MEM_SIZE] - 1][j] =
            info->memory[i % MEM_SIZE];
            i += 1;
        }
        ch->carry = 0;
        i = i % MEM_SIZE;
        if (register_to_int(info, ch->registers[info->memory[i] - 1]) == 0)
            ch->carry = 1;
    } else
        lld_operation_ind(info, ch);
}

int lld_inst(info_t *info, champ_t *ch)
{
    op_t op = op_tab[12];
    int *params = NULL;
    int res = 0;

    if (info->memory[ch->pc] != op.code)
        return (0);
    if (set_cycle_lld(info, ch, op) == 1)
        return (1);
    params = take_parameters(info, ch, op);
    if (verify_parameters(info, ch, op, params) == 84)
        return (0);
    lld_operation(info, ch, op, params);
    lld_change_pc(info, ch, params, op);
    free(params);
    return (1);
}