/*
** EPITECH PROJECT, 2018
** s_low_flag.c
** File description:
** %s flag of my_printf.c
*/

#include <stdarg.h>
#include "my_printf.h"

int s_low_flag(char const *format, int *i, va_list ap)
{
    int a = *i;
    int count = 0;

    if (format[a] == 's')
        count = my_putstr(va_arg(ap, char *));
    return (count);
}
