/*
** EPITECH PROJECT, 2018
** my_strcmp.c
** File description:
** Prototype_file
*/

#include "mylib.h"

int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;

    while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
        i = i + 1;
    return (s1[i] - s2[i]);
}