/*
** EPITECH PROJECT, 2018
** my_compute_square_root.c
** File description:
** Task05 of CPool Day05
*/

#include "mylib.h"

int my_compute_square_root(int nb)
{
    int result = 1;
    int div = 1;

    if (nb <= 0)
        return (0);
    div = nb / result;
    while (div != nb)
        result++;
    return (result);
}
