/*
** EPITECH PROJECT, 2018
** spaces_delete_printf.c
** File description:
** %% flag of my_printf.c
*/

#include <stdarg.h>
#include "my_printf.h"

int spaces_delete_printf(char const *format, int *i, va_list ap)
{
    int a = *i;

    while (format[a] == ' ') {
        a = a + 1;
        *i = a;
    }
    return (a);
}
