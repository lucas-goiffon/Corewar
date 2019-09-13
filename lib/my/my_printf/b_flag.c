/*
** EPITECH PROJECT, 2018
** b_flag.c
** File description:
** %b flag of my_printf.c
*/

#include <stdarg.h>
#include "my_printf.h"

int b_flag(char const *format, int *i, va_list ap)
{
    int a = *i;
    int count = 0;

    if (format[a] == 'b')
        count = binary_conversion(va_arg(ap, unsigned long));
    return (count);
}