/*
** EPITECH PROJECT, 2018
** s_upp_call_flag.c
** File description:
** call s_upp_flag.c for %S of my_printf.c
*/

#include <stdarg.h>
#include "my_printf.h"

int s_upp_call_flag(char const *format, int *i, va_list ap)
{
    int a = *i;
    int count = 0;

    if (format[a] == 'S')
        count = s_upp_flag(va_arg(ap, char *));
    return (count);
}
