/*
** EPITECH PROJECT, 2019
** epitech
** File description:
** is_alpha
*/

#include "mylib.h"

int is_alpha(char *str)
{
    int r = 0;

    for (int i = 0; str[i] != '\0'; i = i + 1) {
        if ((str[i] < 65 || str[i] > 90) &&
        (str[i] < 95 || str[i] > 122))
            return (84);
    }
    return (0);
}