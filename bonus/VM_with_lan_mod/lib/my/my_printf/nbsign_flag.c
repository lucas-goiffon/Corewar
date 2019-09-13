/*
** EPITECH PROJECT, 2018
** nbsign_flag.c
** File description:
** %# flag of my_printf.c
*/

#include <stdarg.h>
#include "my_printf.h"

int nbsign_flag(char const *format, int *i, va_list ap)
{
    int a = *i;

    while (format[a] == '#') {
        a = a + 1;
        *i = a;
    }
    return (a);
}
