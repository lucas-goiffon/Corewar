/*
** EPITECH PROJECT, 2018
** ld_flag.c
** File description:
** %ld flag of my_printf.c
*/

#include <stdarg.h>
#include "my_printf.h"

int ld_flag(char const *format, int *i, va_list ap)
{
    int a = *i;
    int count = 0;

    if (format[a] == 'l' && (format[a + 1] == 'd' || format[a + 1] == 'i')) {
        count = my_put_long_nbr(va_arg(ap, long int));
        *i = a + 1;
    }
    return (count);
}
