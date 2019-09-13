/*
** EPITECH PROJECT, 2018
** my_compute_power_rec.c
** File description:
** Task04 of CPool Day05
*/

#include "mylib.h"

int my_compute_power_rec(int nb, int p)
{
    int result;

    if (p < 0)
        return (0);
    if (p == 0)
        return (1);
    result = nb * my_compute_power_rec(nb, p - 1);
    if (result > 2147483647 || result < -214748647)
        return (0);
    return (result);
}
