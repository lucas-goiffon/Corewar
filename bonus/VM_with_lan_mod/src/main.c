/*
** EPITECH PROJECT, 2019
** CoreWar
** File description:
** main
*/

#include "../include/corewar.h"
#include "../include/network.h"

void vm_initialization(info_t *info)
{
    set_load_address(info);
    open_programs(info);
    set_first_register(info);
    info->cycle_to_die = CYCLE_TO_DIE;
    info->total_cycle = 0;
    info->current_cycle = 0;
}

int main(int ac, char **av)
{
    info_t *info = init_info();

    if (online_multi(ac, av, info) != 1) {
        if (find_flags(ac, av, info) == 84)
            return (84);
    }
    vm_initialization(info);
    game(info);
    if (info->n_curses == 1)
        endwin();
    if (info->dump != -666)
        print_dump(info);
    if (info->last_alive != NULL)
        my_printf("The player %d(%s) has won.\n",
        info->last_alive->s->prog_number, info->last_alive->s->h.prog_name);
    destroy_info(info);
    return (0);
}