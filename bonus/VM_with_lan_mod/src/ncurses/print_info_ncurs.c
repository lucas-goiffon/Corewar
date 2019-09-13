/*
** EPITECH PROJECT, 2019
** CoreWar
** File description:
** print_info_ncurs
*/

#include "../../include/corewar.h"

void general_infos(info_t *info, WINDOW **w)
{
    mvwprintw(w[1], 3, 10, "Total cycles: %d ", info->total_cycle);
    mvwprintw(w[1], 5, 10, "Cycles / Cycle to die: [%d / %d]    ",
    info->current_cycle, info->cycle_to_die);
    mvwprintw(w[1], 3, 65, "Press SPACE to begin");
    mvwprintw(w[1], 4, 65, "Press SPACE to pause/start");
    mvwprintw(w[1], 5, 65, "Press Q to quit");
}

void champions_infos(info_t *info, WINDOW **w)
{
    champ_t *ch;

    mvwprintw(w[1], 2, 185, VM_CHAMP_INFO);
    for (int i = 0; i < MAX_CHAMPS && info->champs[i]->s->file != NULL; i++) {
        ch = info->champs[i];
        wattron(w[1], COLOR_PAIR(ch->s->prog_number));
        mvwprintw(w[1], 3 + i, 197, "(%d)%s", ch->s->prog_number,
        ch->s->h.prog_name);
        mvwprintw(w[1], 3 + i, 217, "%d", ch->s->last_live);
        mvwprintw(w[1], 3 + i, 233, "%d", ch->s->nb_live);
        mvwprintw(w[1], 3 + i, 249, "%d", ch->s->nb_fork);
        mvwprintw(w[1], 3 + i, 268, "%s", (ch->s->is_alive == 1)?"YES":"NO ");
        wattroff(w[1], COLOR_PAIR(ch->s->prog_number));
    }
}

void print_infos_ncurses(info_t *info, WINDOW **w)
{
    general_infos(info, w);
    champions_infos(info, w);
    if (info->last_alive != NULL)
        wattron(w[1], COLOR_PAIR(info->last_alive->s->prog_number));
    mvwprintw(w[1], 2, COLS / 2 - 50, WRITE_COREWAR_1);
    mvwprintw(w[1], 3, COLS / 2 - 50, WRITE_COREWAR_2);
    mvwprintw(w[1], 4, COLS / 2 - 50, WRITE_COREWAR_3);
    mvwprintw(w[1], 5, COLS / 2 - 50, WRITE_COREWAR_4);
    mvwprintw(w[1], 6, COLS / 2 - 50, WRITE_COREWAR_5);
    mvwprintw(w[1], 7, COLS / 2 - 50, WRITE_COREWAR_6);
    if (info->last_alive != NULL)
        wattroff(w[1], COLOR_PAIR(info->last_alive->s->prog_number));
    wrefresh(w[1]);
}