/*
** EPITECH PROJECT, 2019
** tetris
** File description:
** my_tablen
*/

#include "mylib.h"

int my_tablen(char **array)
{
    int i = 0;

    for (i = 0; array[i] != NULL; i = i + 1);
    return (i);
}