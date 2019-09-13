/*
** EPITECH PROJECT, 2019
** CoreWar
** File description:
** my_memcpy
*/

#include "mylib.h"

void *my_memcpy(void *dest, void *src, size_t n)
{
    char *d = dest;
    char *s = src;

    if (n > 0) {
        for (int i = 0; i < n; i = i + 1)
            d[i] = s[i];
    }
    return (dest);
}