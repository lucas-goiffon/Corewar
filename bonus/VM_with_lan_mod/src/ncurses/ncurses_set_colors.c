/*
** EPITECH PROJECT, 2019
** CoreWar
** File description:
** ncurses_set_colors
*/

#include "../../include/corewar.h"

void init_ncurs_colors(info_t *info)
{
    start_color();
    init_pair(0, COLOR_WHITE, COLOR_BLACK);
    init_pair(1, COLOR_RED, COLOR_BLACK);
    init_pair(2, COLOR_CYAN, COLOR_BLACK);
    init_pair(3, COLOR_GREEN, COLOR_BLACK);
    init_pair(4, COLOR_YELLOW, COLOR_BLACK);
    init_pair(6, COLOR_BLACK, COLOR_RED);
    init_pair(7, COLOR_BLACK, COLOR_CYAN);
    init_pair(8, COLOR_BLACK, COLOR_GREEN);
    init_pair(9, COLOR_BLACK, COLOR_YELLOW);

}

void set_color(info_t *info, int i, WINDOW *w)
{
    if (info->colors[i] == 0)
        wattron(w, COLOR_PAIR(0));
    else if (info->colors[i] == 11 || info->colors[i] == 21 ||
    info->colors[i] == 31 || info->colors[i] == 41) {
        wattron(w, COLOR_PAIR(info->colors[i] / 10 + 5));
    } else
        wattron(w, COLOR_PAIR(info->colors[i] / 10));
}

void my_attroff(info_t *info, int i, WINDOW *w)
{
    if (info->colors[i] == 0)
        wattroff(w, COLOR_PAIR(0));
    else if (info->colors[i] == 11 || info->colors[i] == 21 ||
    info->colors[i] == 31 || info->colors[i] == 41) {
        wattroff(w, COLOR_PAIR(info->colors[i] / 10 + 5));
        info->colors[i] = (info->colors[i] - 1);
    } else
        wattroff(w, COLOR_PAIR(info->colors[i] / 10));
}