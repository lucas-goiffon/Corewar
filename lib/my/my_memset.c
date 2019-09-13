/*
** EPITECH PROJECT, 2019
** CoreWar
** File description:
** my_memset
*/

#include "mylib.h"

void *my_memset(void *dest, int c, size_t n)
{
    char *d = dest;

    if (n > 0) {
        for (int i = 0; i < n; i = i + 1)
            d[i] = c;
    }
    return (dest);
}