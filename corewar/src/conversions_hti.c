/*
** EPITECH PROJECT, 2019
** CoreWar
** File description:
** conversions_hti
*/

#include "../include/corewar.h"

short hex_to_short(info_t *info, champ_t *ch, int beg)
{
    short res = 0;

    while (beg < 0)
        beg = MEM_SIZE - beg;
    res = res + info->memory[beg % MEM_SIZE];
    res = (res << 8);
    res = res + info->memory[(beg + 1) % MEM_SIZE];
    return (res);
}

int hex_to_int(info_t *info, champ_t *ch, int beg)
{
    int res = 0;

    while (beg < 0)
        beg = MEM_SIZE - beg;
    res = res + info->memory[beg % MEM_SIZE];
    res = (res << 8);
    res = res + info->memory[(beg + 1) % MEM_SIZE];
    res = (res << 8);
    res = res + info->memory[(beg + 2) % MEM_SIZE];
    res = (res << 8);
    res = res + info->memory[(beg + 3) % MEM_SIZE];
    return (res);
}

int register_to_int(info_t *info, unsigned char *reg)
{
    int result = 0;

    if (reg == NULL)
        return (0);
    result += reg[0];
    for (int i = 1; i < 4; i += 1) {
        result = (result << 8);
        result += reg[i];
    }
    return (result);
}