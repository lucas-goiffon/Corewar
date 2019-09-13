/*
** EPITECH PROJECT, 2018
** p_flag.c
** File description:
** %p flag of my_printf.c
*/

#include <stdarg.h>
#include "my_printf.h"

int p_flag(char const *format, int *i, va_list ap)
{
    int a = *i;
    int count = 0;

    if (format[a] == 'p')
        count = my_put_pointer(va_arg(ap, void *));
    return (count);
}
