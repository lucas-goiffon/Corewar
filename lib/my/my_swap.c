/*
** EPITECH PROJECT, 2018
** my_swap.c
** File description:
** Task01 of CPool Day04
*/

#include "mylib.h"

void my_swap(int *a, int *b)
{
    char stock = 0;

    stock = *a;
    *a = *b;
    *b = stock;
}
