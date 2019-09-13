/*
** EPITECH PROJECT, 2019
** CoreWar
** File description:
** ldi
*/

#include "../../include/corewar.h"

int set_cycle_ldi(info_t *info, champ_t *ch, op_t op)
{
    if (ch->save_cycle == -666)
        ch->save_cycle = info->total_cycle;
    if (ch->save_cycle != -666 &&
    ch->save_cycle + op.nbr_cycles > info->total_cycle)
        return (1);
    ch->save_cycle = -666;
    return (0);
}

void ldi_change_pc(info_t *info, champ_t *ch, int *params, op_t op)
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

int take_param_ldi(info_t *info, champ_t *ch, int params, int *i)
{
    int seum = 0;

    if (params == 1) {
        if (info->memory[*i] < 1 || info->memory[*i] > 16) {
            ch->carry = -1;
            return (0);
        }
        seum = register_to_int(info, ch->registers[info->memory[*i] - 1]);
        *i += 1;
    } else {
        seum = (int)hex_to_short(info, ch, *i);
        i += 2;
    }
    return (seum);
}

void ldi_operation(info_t *info, champ_t *ch, op_t op, int *params)
{
    int i = (ch->pc + 2) % MEM_SIZE;
    int sum = 0;
    int j = 0;
    int s_j = 0;
    int pc_sum = 0;

    ch->carry = 0;
    sum = take_param_ldi(info, ch, params[0], &i);
    i = verify_pc_wc(i);
    sum += take_param_ldi(info, ch, params[1], &i);
    i = verify_pc_wc(i);
    if (info->memory[i] < 1 || info->memory[i] > REG_NUMBER)
        return;
    j = (ch->pc + sum % IDX_MOD) % MEM_SIZE;
    pc_sum = verify_pc_wc(ch->pc + sum % IDX_MOD);
    for (s_j = j; j < 4 + s_j; j = (j + 1) % MEM_SIZE)
        ch->registers[info->memory[i] - 1][j - pc_sum] = info->memory[j];
    if (register_to_int(info, ch->registers[info->memory[i] - 1]) == 0)
        ch->carry += 1;
}

int ldi_inst(info_t *info, champ_t *ch)
{
    op_t op = op_tab[9];
    int *params = NULL;
    int res = 0;

    if (info->memory[ch->pc] != op.code)
        return (0);
    if (set_cycle_ldi(info, ch, op) == 1)
        return (1);
    params = take_parameters(info, ch, op);
    if (verify_parameters(info, ch, op, params) == 84)
        return (0);
    ldi_operation(info, ch, op, params);
    ldi_change_pc(info, ch, params, op);
    free(params);
    return (1);
}