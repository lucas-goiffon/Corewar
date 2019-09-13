/*
** EPITECH PROJECT, 2018
** my_putstr.c
** File description:
** file for tests
*/

#include <unistd.h>
#include "mylib.h"

int my_putstr(char const *str)
{
    if (str == NULL) {
        my_putstr("(null)");
        return (0);
    } else {
        write(1, str, my_strlen(str));
        return (my_strlen(str));
    }
}
