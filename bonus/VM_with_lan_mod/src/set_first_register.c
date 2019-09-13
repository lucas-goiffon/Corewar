/*
** EPITECH PROJECT, 2019
** CoreWar
** File description:
** set_first_register
*/

#include "../include/corewar.h"

void set_first_register(info_t *info)
{
    champ_t **ch = info->champs;

    for (int i = 0; i < MAX_CHAMPS && ch[i]->s->file != NULL; i += 1)
        ch[i]->registers[0][REG_SIZE - 1] = ch[i]->s->prog_number;
}