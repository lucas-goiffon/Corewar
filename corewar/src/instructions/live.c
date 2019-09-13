/*
** EPITECH PROJECT, 2019
** CoreWar
** File description:
** live
*/

#include "../../include/corewar.h"

int live_set_cycle(info_t *info, champ_t *ch, op_t op)
{
    if (ch->save_cycle == -666)
        ch->save_cycle = info->total_cycle;
    if (ch->save_cycle != -666 &&
    ch->save_cycle + op.nbr_cycles > info->total_cycle)
        return (1);
    ch->save_cycle = -666;
    if (ch->s->is_alive == 0)
        return (1);
    return (0);
}

void live_operation(info_t *info, champ_t *ch, int i)
{
    info->last_alive = info->champs[i];
    if (info->n_curses == 0) {
        my_printf("The player %d(%s) is alive.\n",
        info->memory[(ch->pc + DIR_SIZE) % MEM_SIZE],
        info->champs[i]->s->h.prog_name);
    }
    ch->pc = ch->pc + DIR_SIZE + 1;
    ch->s->last_live = info->total_cycle;
    ch->s->nb_live += 1;
    info->total_nb_live += 1;
}

int live_inst(info_t *info, champ_t *ch)
{
    op_t op = op_tab[0];
    int i = 0;

    if (info->memory[ch->pc] != op.code)
        return (0);
    if (live_set_cycle(info, ch, op) == 1)
        return (1);
    for (i = 0; i < MAX_CHAMPS && info->champs[i]->s->file != NULL &&
    info->memory[(ch->pc + DIR_SIZE) % MEM_SIZE] !=
    info->champs[i]->s->prog_number; i += 1);
    if (i < MAX_CHAMPS && info->champs[i]->s->file != NULL) {
        live_operation(info, ch, i);
        return (1);
    }
    return (0);
}