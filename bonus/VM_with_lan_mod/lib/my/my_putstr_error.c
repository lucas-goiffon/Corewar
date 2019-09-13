/*
** EPITECH PROJECT, 2019
** lib
** File description:
** my_putstr_error
*/

#include <unistd.h>
#include "mylib.h"

int my_putstr_error(char const *str)
{
    if (str == 0) {
        my_putstr_error("(null)");
        return (0);
    } else {
        write(2, str, my_strlen(str));
        return (my_strlen(str));
    }
}