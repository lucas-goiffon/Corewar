/*
** EPITECH PROJECT, 2018
** my_int_to_str.c
** File description:
** Put an int into an str
*/

#include "mylib.h"

char *my_int_to_str(int nb)
{
    int count = 0;
    int test = nb;
    char *str;

    while (test > 0) {
        count++;
        test = test/10;
    }
    str = malloc(sizeof(char) * (count + 1));
    str[count] = '\0';
    count--;
    while (count >= 0) {
        test = nb % 10;
        str[count] = test + 48;
        nb = nb / 10;
        count--;
    }
    return (str);
}
