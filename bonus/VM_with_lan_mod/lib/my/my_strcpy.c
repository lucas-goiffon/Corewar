/*
** EPITECH PROJECT, 2018
** my_strcpy.c
** File description:
** Task01 of CPool Day06
*/

#include "mylib.h"

char *my_strcpy(char *dest, char const *src)
{
    int j;

    for (j = 0; src[j] != '\0'; j++)
        dest[j] = src[j];
    dest[j] = '\0';
    return (dest);
}
