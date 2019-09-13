/*
** EPITECH PROJECT, 2019
** epitech
** File description:
** fill_str_two
*/

#include "mylib.h"

void fill_str_two(char *str, int size, char to_replace)
{
    for (int i = 0; i < size; i = i + 1)
        str[i] = to_replace;
}