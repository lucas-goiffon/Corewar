/*
** EPITECH PROJECT, 2019
** lib
** File description:
** my_put_nbr_error
*/

#include "mylib.h"
#include <unistd.h>

int my_put_nbr_error(int nb)
{
    int result;
    char res;

    if (nb < 0) {
        nb = nb - nb - nb;
        res = 45;
        write(2, &res, 1);
    }
    result = nb % 10;
    nb = nb / 10;
    if (nb == 0) {
        res = result + 48;
        write(2, &res, 1);
        return (0);
    }
    my_put_nbr_error(nb);
    res = result + 48;
    write(2, &res, 1);
    return (0);
}