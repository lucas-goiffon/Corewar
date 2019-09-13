/*
** EPITECH PROJECT, 2018
** my_strcat.c
** File description:
** Task02 of CPool Day07
*/

#include "mylib.h"

char *my_strcat(char *dest, char const *src)
{
    int size = my_strlen(dest);

    for (int i = 0; src[i] != '\0'; i++) {
        dest[size] = src[i];
        size++;
    }
    dest[size] = '\0';
    return (dest);
}
