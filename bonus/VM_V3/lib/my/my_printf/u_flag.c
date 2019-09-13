/*
** EPITECH PROJECT, 2018
** u_flag.c
** File description:
** %u flag of my_printf.c
*/

#include <stdarg.h>
#include "my_printf.h"

int u_flag(char const *format, int *i, va_list ap)
{
    int a = *i;
    int count = 0;

    if (format[a] == 'u')
        count = my_put_unsigned_nbr(va_arg(ap, unsigned int));
    return (count);
}
