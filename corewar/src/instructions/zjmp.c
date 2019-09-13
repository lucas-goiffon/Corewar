/*
** EPITECH PROJECT, 2019
** CoreWar
** File description:
** zjmp
*/

#include "../../include/corewar.h"

int zjmp_inst(info_t *info, champ_t *ch)
{
    op_t op = op_tab[8];

    if (info->memory[ch->pc] != op.code)
        return (0);
    if (ch->save_cycle == -666)
        ch->save_cycle = info->total_cycle;
    if (ch->save_cycle != -666 &&
    ch->save_cycle + op.nbr_cycles > info->total_cycle)
        return (1);
    ch->save_cycle = -666;
    if (ch->carry == 0) {
        ch->pc = ch->pc + hex_to_short(info, ch, ch->pc + 1);
        return (1);
    }
    ch->pc = (ch->pc + hex_to_short(info, ch, ch->pc + 1)) % MEM_SIZE;
    return (1);
}