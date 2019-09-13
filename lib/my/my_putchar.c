/*
** EPITECH PROJECT, 2018
** my_putchar.c
** File description:
** File for tests
*/

#include <unistd.h>
#include "mylib.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}
