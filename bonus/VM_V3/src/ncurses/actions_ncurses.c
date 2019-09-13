/*
** EPITECH PROJECT, 2019
** CoreWar
** File description:
** actions_ncurses
*/

#include "../../include/corewar.h"

void pause_and_quit_ncurses(info_t *info, WINDOW **w)
{
    char c = getch();

    if (c == ' ') {
        sfMusic_pause(info->music);
        for (int i = 0; i < 1000; i += 1);
        while ((c = getch()) != ' ' && c != 'q') {
            print_map_ncurses(info, w);
            print_infos_ncurses(info, w);
        }
        sfMusic_play(info->music);
    } if (c == 'q')
        info->cycle_to_die = 0;
}

void is_terminal_too_small(info_t *info)
{
    if (info->n_curses == 1 && (COLS <  96 * 3 + 3 || LINES < 76)) {
        endwin();
        my_exit(info, 84, "Terminal too small\n");
    }
}