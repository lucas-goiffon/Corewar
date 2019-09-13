/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** u_strcpy
*/

#include "../include/corewar.h"

unsigned char *u_strcpy(unsigned char *dest, unsigned char *src, int size)
{
    for (int i = 0; i < size; i += 1)
        dest[i] = src[i];
    return (dest);
}