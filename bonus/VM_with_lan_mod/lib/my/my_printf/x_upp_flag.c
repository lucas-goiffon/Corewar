/*
** EPITECH PROJECT, 2018
** x_upp_flag.c
** File description:
** %X flag of my_printf.c
*/

#include <stdarg.h>
#include "my_printf.h"

int x_upp_flag(char const *format, int *i, va_list ap)
{
    int a = *i;
    int count = 0;

    if (format[a] == 'X' && format[a - 1] != '#')
        count = hexa_conversion_upp(va_arg(ap, unsigned long));
    else if (format[a] == 'X' && format[a - 1] == '#') {
        my_putstr("0x");
        count = hexa_conversion_upp(va_arg(ap, unsigned long));
    }
    return (count);
}
