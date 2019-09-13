/*
** EPITECH PROJECT, 2019
** CoreWar
** File description:
** verify_pc
*/

#include "../include/corewar.h"

void verify_pc(champ_t *champ)
{
    while (champ->pc < 0)
        champ->pc = MEM_SIZE + champ->pc;
    champ->pc = champ->pc % MEM_SIZE;
}

int verify_pc_wc(int nb)
{
    while (nb < 0)
        nb = MEM_SIZE + nb;
    nb = nb % MEM_SIZE;
    return (nb);
}