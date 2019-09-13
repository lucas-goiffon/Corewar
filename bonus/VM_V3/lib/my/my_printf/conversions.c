/*
** EPITECH PROJECT, 2018
** conversions.c
** File description:
** Base conversion functions
*/

#include <stdlib.h>
#include "my_printf.h"
#include "conv.h"

int binary_conversion(unsigned long nb)
{
    conv;
    while (testsize > 0) {
        testsize = testsize / 2;
        char_size = char_size + 1;
    }
    str = malloc(sizeof(char) * (char_size + 1));
    str[char_size] = '\0';
    char_size = char_size - 1;
    if (nb == 0)
        str = "0\0";
    for (char_size = char_size; nb > 0; char_size = char_size - 1) {
        r = nb % 2;
        binary_conversion_two(r, str, char_size);
        nb = nb / 2;
    }
    my_putstr(str);
    count = my_strlen(str) - 2;
    free(str);
    return (count);
}

void binary_conversion_two(int r, char *str, int char_size)
{
    if (r == 0)
        str[char_size] = '0';
    else
        str[char_size] = '1';
}

int hexa_conversion_upp(unsigned long nb)
{
    conv;
    while (testsize > 0) {
        testsize = testsize / 16;
        char_size = char_size + 1;
    } str = malloc(sizeof(char) * (char_size + 1));
    str[char_size] = '\0';
    char_size = char_size - 1;
    if (nb == 0) {
        my_putstr("0");
        free(str);
        return (1);
    } for (char_size = char_size; nb > 0; char_size = char_size - 1) {
        r = nb % 16;
        hexa_conversion_upp_two(r, str, char_size);
        nb = nb / 16;
    } my_putstr(str);
    count = my_strlen(str) - 2;
    free(str);
    return (count);
}

void hexa_conversion_upp_two(int r, char *str, int char_size)
{
    char *base = "0123456789ABCDEF";

    str[char_size] = base[r];
}
