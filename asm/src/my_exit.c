/*
** EPITECH PROJECT, 2019
** CoreWar
** File description:
** my_exit
*/

#include "../include/asm.h"

void my_exit(info_t *info, int exit_status)
{
    destroy_all(info);
    my_putstr_error("Error\n");
    exit(exit_status);
}