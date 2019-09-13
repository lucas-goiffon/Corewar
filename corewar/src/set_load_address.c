/*
** EPITECH PROJECT, 2019
** CoreWar
** File description:
** set_load_address
*/

#include "../include/corewar.h"

void set_load_address(info_t *info)
{
    int nb_champs = 0;

    for (nb_champs = 0; nb_champs < MAX_CHAMPS &&
    info->champs[nb_champs]->s->file != NULL; nb_champs += 1);
    for (int i = 0; i < MAX_CHAMPS &&
    info->champs[i]->s->file != NULL; i = i + 1) {
        if (info->champs[i]->s->load_address < 0) {
            info->champs[i]->s->load_address = i * (MEM_SIZE / nb_champs);
            info->champs[i]->pc = info->champs[i]->s->load_address;
        }
    }
}