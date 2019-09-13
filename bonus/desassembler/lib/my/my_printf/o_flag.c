/*
** EPITECH PROJECT, 2018
** o_flag.c
** File description:
** %o flag of my_printf.c
*/

#include <stdarg.h>
#include "my_printf.h"

int o_flag(char const *format, int *i, va_list ap)
{
    int a = *i;
    int count = 0;

    if (format[a] == 'o' && format[a - 1] != '#')
        count = octal_conversion(va_arg(ap, unsigned long));
    else if (format[a] == 'o' && format[a - 1] == '#') {
        my_putchar('0');
        count = octal_conversion(va_arg(ap, unsigned long));
    }
    return (count);
}
