/*
** EPITECH PROJECT, 2018
** hd_flag.c
** File description:
** %hd flag of my_printf.c
*/

#include <stdarg.h>
#include "my_printf.h"

int hd_flag(char const *format, int *i, va_list ap)
{
    int a = *i;
    int count = 0;

    if (format[a] == 'h' && (format[a + 1] == 'd' || format[a + 1] == 'i')) {
        count = my_put_short_nbr(va_arg(ap, int));
        *i = a + 1;
    }
    return (count);
}
