/*
** EPITECH PROJECT, 2019
** CoreWar
** File description:
** my_realloc
*/

#include "mylib.h"

void *my_realloc(void *old, size_t n)
{
    char *d = old;
    void *new = malloc(n);
    char *new_n = new;

    if (new == NULL)
        return (NULL);
    my_memset(new, 0, n);
    for (int i = 0; d[i] != 0; i = i + 1)
        new_n[i] = d[i];
    free(old);
    return (new);
}