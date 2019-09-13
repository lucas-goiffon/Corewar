/*
** EPITECH PROJECT, 2018
** my_put_nbr.c
** File description:
** Task07 of CPool Day03
*/

#include "mylib.h"

int my_put_nbr(int nb)
{
    int result;

    if (nb < 0) {
        nb = nb - nb - nb;
        my_putchar(45);
    }
    result = nb % 10;
    nb = nb / 10;
    if (nb == 0) {
        my_putchar(result + 48);
        return (0);
    }
    my_put_nbr(nb);
    my_putchar(result + 48);
    return (0);
}
