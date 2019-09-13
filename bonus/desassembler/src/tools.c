/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** take_parameters
*/

#include "../include/desassembler.h"

int *take_parameters(unsigned char c)
{
    unsigned char tmp = c;
    int *params = my_malloc(sizeof(int) * 4);

    params[0] = (tmp >> 6);
    params[1] = (tmp >> 4) - (params[0] << 2);
    params[2] = ((tmp >> 2) - (params[0] << 4)) - (params[1] << 2);
    params[3] = 0;
    return (params);
}

short hex_to_short(desasm_t *des, int beg)
{
    short res = 0;

    res = res + des->bytes[beg];
    res = (res << 8);
    res = res + des->bytes[beg + 1];
    return (res);
}

int hex_to_int(desasm_t *des, int beg)
{
    int res = 0;

    res = res + des->bytes[beg];
    res = (res << 8);
    res = res + des->bytes[beg + 1];
    res = (res << 8);
    res = res + des->bytes[beg + 2];
    res = (res << 8);
    res = res + des->bytes[beg + 3];
    return (res);
}