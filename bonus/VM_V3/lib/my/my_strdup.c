/*
** EPITECH PROJECT, 2018
** my_strdup.c
** File description:
** Task01 of CPool Day08
*/

#include <stdlib.h>
#include "mylib.h"

char *my_strdup(char const *src)
{
    char *str;
    int i = 0;
    int size = my_strlen(src);

    str = malloc(sizeof(char) * (my_strlen(src) + 1));
    while (i < size) {
        str[i] = src[i];
        i++;
    }
    str[i] = '\0';
    return (str);
}
