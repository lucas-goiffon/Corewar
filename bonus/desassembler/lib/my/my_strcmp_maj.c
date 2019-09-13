/*
** EPITECH PROJECT, 2018
** my_strcmp_maj.c
** File description:
** Prototype_file
*/

#include "mylib.h"

void my_strcmp_maj_two(char const *s1, char const *s2, int *r, int i)
{
    if (s1[i] > s2[i] && s1[i] == (s2[i] + 32))
        *r = 0;
    else if (s2[i] > s1[i] && s2[i] == (s1[i] + 32))
        *r = 0;
    else
        *r = -1;
}

int my_strcmp_maj(char const *s1, char const *s2)
{
    int r = 0;
    int i = 0;

    while (s1[i] != '\0' && r == 0) {
        if (s1[i] != s2[i]) {
            my_strcmp_maj_two(s1, s2, &r, i);
        } else
            r = 0;
        i = i + 1;
    }
    if (s1[i] != s2[i])
        r = -1;
    return (r);
}
