/*
** EPITECH PROJECT, 2019
** CoreWar
** File description:
** graphic_ncurses
*/

#include "../../include/corewar.h"

char *get_hexa_values_ncurs(unsigned char nb, char *str)
{
    int r;
    char *base = "0123456789ABCDEF";

    str[0] = '0';
    str[1] = '0';
    str[2] = 0;
    if (nb == 0)
        return (str);
    for (int i = 1; i >= 0 && nb > 0; i = i - 1) {
        r = nb % 16;
        str[i] = base[r];
        nb = nb / 16;
    }
    return (str);
}

void init_ncurses(info_t *info, WINDOW **w)
{
    if (info->n_curses == 1) {
        initscr();
        init_ncurs_colors(info);
        w[0] = newwin(66, 96 * 3 + 3, 0, COLS / 2 - (96 * 3 + 3) / 2);
        box(w[0], ACS_VLINE, ACS_HLINE);
        w[1] = newwin(10, 96 * 3 + 3, 66, COLS / 2 - (96 * 3 + 3) / 2);
        box(w[1], ACS_VLINE, ACS_HLINE);
        cbreak();
        noecho();
        timeout(1);
        curs_set(0);
        clear();
        if (has_colors() == FALSE) {
            endwin();
            my_exit(info, 84, "Your terminal does not support color\n");
        }
        is_terminal_too_small(info);
    }
}

void print_map_ncurses(info_t *info, WINDOW **w)
{
    int j = 0;
    char hex[3];

    for (int y = 1; y <= 64; y += 1) {
        set_color(info, j, w[0]);
        mvwprintw(w[0], y, 2, get_hexa_values_ncurs(info->memory[j], hex));
        my_attroff(info, j, w[0]);
        j += 1;
        for (int x = 4; x < 96 * 2 + 95; x += 1) {
            x += 1;
            set_color(info, j, w[0]);
            mvwprintw(w[0], y, x, get_hexa_values_ncurs(info->memory[j], hex));
            my_attroff(info, j, w[0]);
            x += 1;
            j += 1;
        }
    }
    wrefresh(w[0]);
}

void print_all_ncurses(info_t *info, WINDOW **w)
{
    if (info->n_curses == 0)
        return;
    while (info->total_cycle <= 1 && getch() != ' ') {
        print_map_ncurses(info, w);
        print_infos_ncurses(info, w);
        if (info->lan == 1)
            break;
    }
    print_map_ncurses(info, w);
    print_infos_ncurses(info, w);
    pause_and_quit_ncurses(info, w);
}