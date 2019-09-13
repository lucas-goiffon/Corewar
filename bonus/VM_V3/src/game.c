/*
** EPITECH PROJECT, 2019
** CoreWar
** File description:
** game
*/

#include "../include/corewar.h"

int verify_cycles(info_t *info)
{
    if (info->current_cycle >= CYCLE_TO_DIE) {
        info->current_cycle = 0;
        if (info->total_nb_live - info->last_nb_live >= NBR_LIVE)
            info->cycle_to_die -= CYCLE_DELTA;
        for (int i = 0; i < MAX_CHAMPS &&
        info->champs[i]->s->file != NULL; i += 1) {
            if (info->champs[i]->s->last_live <
            (info->total_cycle - info->cycle_to_die) &&
            info->champs[i]->s->is_alive != 0)
                sfMusic_play(info->die_sound);
            if (info->champs[i]->s->last_live <
            (info->total_cycle - info->cycle_to_die))
                info->champs[i]->s->is_alive = 0;
        }
    }
}

void try_instructions(info_t *info, WINDOW **w)
{
    int (*instructions[16])(info_t *info, champ_t *ch) = {live_inst,
    zjmp_inst, sti_inst, and_inst, ld_inst, add_inst, fork_inst, sub_inst,
    st_inst, aff_inst, or_inst, xor_inst, lfork_inst, lld_inst, ldi_inst,
    lldi_inst};
    int i = 0;
    champ_t *ch;

    for (int k = 0; k < MAX_CHAMPS &&
    info->champs[k]->s->file != NULL; k += 1) {
        ch = info->champs[k];
        while (ch != NULL) {
            verify_pc(ch);
            for (i = 0; i < 16 && (*instructions[i])(info, ch) != 1; i += 1);
            if (i == 16)
                ch->pc += 1;
            ch = ch->next;
        }
    } info->current_cycle += 1;
    info->total_cycle += 1;
    print_all_ncurses(info, w);
    verify_cycles(info);
}

void game(info_t *info)
{
    WINDOW *w[2];

    init_ncurses(info, w);
    if (info->dump == -666) {
        while (info->cycle_to_die > 0)
            try_instructions(info, w);
    } else {
        while (info->cycle_to_die > 0 && info->total_cycle < info->dump)
            try_instructions(info, w);
    }
}