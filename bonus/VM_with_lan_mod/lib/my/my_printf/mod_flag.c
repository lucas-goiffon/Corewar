/*
** EPITECH PROJECT, 2018
** mod_flag.c
** File description:
** %% flag of my_printf.c
*/

#include <stdarg.h>
#include "my_printf.h"

int mod_flag(char const *format, int *i, va_list ap)
{
    int a = *i;

    if (format[a] == '%') {
        my_putchar('%');
    }
    return (a);
}
