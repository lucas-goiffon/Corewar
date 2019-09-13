/*
** EPITECH PROJECT, 2018
** x_low_flag.c
** File description:
** %x flag of my_printf.c
*/

#include <stdarg.h>
#include "my_printf.h"

int x_low_flag(char const *format, int *i, va_list ap)
{
    int a = *i;
    int count = 0;

    if (format[a] == 'x' && format[a - 1] != '#')
        count = hexa_conversion_low(va_arg(ap, unsigned long));
    else if (format[a] == 'x' && format[a - 1] == '#') {
        my_putstr("0x");
        count = hexa_conversion_low(va_arg(ap, unsigned long));
    }
    return (count);
}
