/*
** EPITECH PROJECT, 2019
** CoreWar
** File description:
** print_dump
*/

#include "../include/corewar.h"

void color_print_dump(info_t *info, char *str, char color)
{
    if (color == 0)
        my_printf("%s%s%s", NORMAL, str, NORMAL);
    else {
        color = color / 10 - 1;
        if (color < 0 || color >= MAX_CHAMPS)
            my_printf("%s%s%s", NORMAL, str, NORMAL);
        else
            my_printf("%s%s%s", info->w_color[color], str, NORMAL);
    }
}

void print_hexa_values(info_t *info, unsigned char nb, char color)
{
    char str[3];
    int r;
    char *base = "0123456789ABCDEF";

    str[0] = '0';
    str[1] = '0';
    str[2] = 0;
    if (nb == 0) {
        color_print_dump(info, str, color);
        return;
    }
    for (int i = 1; i >= 0 && nb > 0; i = i - 1) {
        r = nb % 16;
        str[i] = base[r];
        nb = nb / 16;
    }
    color_print_dump(info, str, color);
}

void print_dump(info_t *info)
{
    int j = 0;

    for (int i = 0; i < 192; i = i + 1) {
        my_printf("%X\t: ", i * 32);
        print_hexa_values(info, info->memory[0 + j], info->colors[0 + j]);
        for (int k = 1; k < 32; k = k + 1) {
            my_putchar(' ');
            print_hexa_values(info, info->memory[k + j], info->colors[k + j]);
        }
        my_putchar('\n');
        j = j + 32;
    }
}