/*
** EPITECH PROJECT, 2019
** CoreWar
** File description:
** my_exit
*/

#include "../include/corewar.h"

void my_exit(info_t *info, int exit_status, char *message)
{
    destroy_info(info);
    my_putstr_error(message);
    exit(exit_status);
}