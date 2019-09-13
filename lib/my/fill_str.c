/*
** EPITECH PROJECT, 2018
** fill_str.c
** File description:
** my_memset
*/

#include "mylib.h"

void fill_str(char *str, int size)
{
    for (int i = 0; i < size; i = i + 1)
        str[i] = '\0';
}
