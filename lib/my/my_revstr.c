/*
** EPITECH PROJECT, 2018
** my_evil_str.c
** File description:
** Task04 of CPool Day04
*/

#include "mylib.h"

char *my_revstr(char *str)
{
    int	i = 0;
    int	y = my_strlen(str) - 1;
    char c;

    while (i < my_strlen(str) / 2) {
        c = str[i];
        str[i] = str[y];
        str[y] = c;
        i++;
        y--;
    }
    return (str);
}
