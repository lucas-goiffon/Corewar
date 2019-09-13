/*
** EPITECH PROJECT, 2018
** c_flag.c
** File description:
** %c flag of my_printf.c
*/

#include <stdarg.h>
#include "my_printf.h"

int c_flag(char const *format, int *i, va_list ap)
{
    int a = *i;

    if (format[a] == 'c') {
        my_putchar(va_arg(ap, int));
        return (1);
    } else
        return (0);
}
