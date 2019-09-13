/*
** EPITECH PROJECT, 2019
** tetris
** File description:
** print_double_array
*/

#include "mylib.h"
#include <unistd.h>

void print_double_array(char **array)
{
    for (int i = 0; array[i] != NULL; i = i + 1) {
        my_putstr(array[i]);
        write(1, "\n", 1);
    }
}