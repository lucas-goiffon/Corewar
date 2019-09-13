/*
** EPITECH PROJECT, 2018
** my_isneg.c
** File description:
** Task03 of CPool Day03
*/

#include "mylib.h"

int my_isneg(int n)
{
    if (n >= 0) {
        my_putchar('P');
    } else {
        my_putchar('N');
    }
    return (0);
}
