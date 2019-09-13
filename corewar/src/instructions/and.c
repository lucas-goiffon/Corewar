/*
** EPITECH PROJECT, 2019
** CoreWar
** File description:
** and
*/

#include "../../include/corewar.h"

int set_cycle_and(info_t *info, champ_t *ch, op_t op)
{
    if (ch->save_cycle == -666)
        ch->save_cycle = info->total_cycle;
    if (ch->save_cycle != -666 &&
    ch->save_cycle + op.nbr_cycles > info->total_cycle)
        return (1);
    ch->save_cycle = -666;
    return (0);
}

void and_change_pc(info_t *info, champ_t *ch, int *params, op_t op)
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

int set_str_and_operation(info_t *info, unsigned char *str, int param, int j)
{
    if (param == 3) {
        str[0] = 0;
        str[1] = 0;
        str[2] = info->memory[j];
        j = j + 1;
        str[3] = info->memory[j % MEM_SIZE];
    } else if (param == 2) {
        for (int i = j; i < 4 + j; i += 1)
            str[i - j] = info->memory[i % MEM_SIZE];
        j = j + 3;
    }
    return (j + 1);
}

void and_operation(info_t *info, champ_t *ch, op_t op, int *params)
{
    unsigned char one[5];
    unsigned char two[5];
    int i = (ch->pc + 2) % MEM_SIZE;

    if (params[0] == 1)
        u_strcpy(one, ch->registers[info->memory[i] - 1], 4);
    i = set_str_and_operation(info, one, params[0], i) % MEM_SIZE;
    if (params[1] == 1)
        u_strcpy(two, ch->registers[info->memory[i + 1] - 1], 4);
    i = set_str_and_operation(info, two, params[1], i + 1) % MEM_SIZE;
    if (info->memory[i] - 1 < 0 || info->memory[i] - 1 >= REG_NUMBER)
        return;
    for (int j = 0; j < 4; j += 1)
        ch->registers[info->memory[i] - 1][j] = (one[j] & two[j]);
    ch->carry = 0;
    if (register_to_int(info, ch->registers[info->memory[i] - 1]) == 0)
        ch->carry = 1;
}

int and_inst(info_t *info, champ_t *ch)
{
    op_t op = op_tab[5];
    int *params = NULL;
    int res = 0;

    if (info->memory[ch->pc] != op.code)
        return (0);
    if (set_cycle_and(info, ch, op) == 1)
        return (1);
    params = take_parameters(info, ch, op);
    if (verify_parameters(info, ch, op, params) == 84)
        return (0);
    and_operation(info, ch, op, params);
    and_change_pc(info, ch, params, op);
    free(params);
    return (1);
}