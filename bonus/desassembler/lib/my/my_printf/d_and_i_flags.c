/*
** EPITECH PROJECT, 2018
** d_and_i_flag.c
** File description:
** %d and %i flags of my_printf.c
*/

#include <stdarg.h>
#include "my_printf.h"

int d_and_i_flags(char const *format, int *i, va_list ap)
{
    int a = *i;
    int count = 0;

    if (format[a] == 'd' || format[a] == 'i')
        count = my_put_nbr(va_arg(ap, int));
    return (count);
}
