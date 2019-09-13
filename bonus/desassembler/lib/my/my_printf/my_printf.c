/*
** EPITECH PROJECT, 2018
** my_printf.c
** File description:
** Main file of my_printf function
*/

#include <stdio.h>
#include <stdarg.h>
#include "my_printf.h"
#include "pointerarray.h"

int option_printf(char const *format, int *z, va_list ap, ...)
{
    int count = 0;
    int i = *z;

    array;
    if (format[i] == '%') {
        i = i + 1;
        for (int a = 0; a <= 14; a = a + 1)
            count = (*pointer_on_function[a])(format, &i, ap);
        if (format[i] == '%' && format[i] != '%')
            i = option_printf(format, &i, ap);
    }
    *z = i;
    return (0);
}

int my_printf(char const *format, ...)
{
    int i = 0;
    int count = 0;
    va_list ap;

    va_start(ap, format);
    while (format[i] != '\0') {
        if (format[i] == '%')
            option_printf(format, &i, ap);
        else
            my_putchar(format[i]);
        i = i + 1;
    }
    va_end(ap);
    return (i);
}
