/*
** EPITECH PROJECT, 2019
** CoreWar
** File description:
** init_info
*/

#include "../include/corewar.h"

void init_champs(champ_t *ch)
{
    ch->s->load_address = -666;
    ch->save_cycle = -666;
    ch->carry = 0;
    ch->s->is_alive = 1;
    ch->next = NULL;
    ch->s->nb_fork = 0;
    ch->registers = my_malloc(sizeof(unsigned char *) * (REG_NUMBER + 1));
    for (int j = 0; j < REG_NUMBER; j += 1)
        ch->registers[j] = my_malloc(sizeof(unsigned char) * (REG_SIZE + 1));
}

info_t *init_info(void)
{
    info_t *info = my_malloc(sizeof(info_t));

    info->dump = -666;
    info->colors = my_malloc(sizeof(char) * MEM_SIZE + 1);
    info->w_color[0] = RED;
    info->w_color[1] = BLUE;
    info->w_color[2] = GREEN;
    info->w_color[3] = YELLOW;
    info->champs = my_malloc(sizeof(champ_t *) * (MAX_CHAMPS + 1));
    for (int i = 0; i < MAX_CHAMPS; i = i + 1) {
        info->champs[i] = my_malloc(sizeof(champ_t));
        info->champs[i]->s = my_malloc(sizeof(stat_champ_t));
        init_champs(info->champs[i]);
    }
    info->champs[MAX_CHAMPS] = NULL;
    info->memory = my_malloc(sizeof(unsigned char) * (MEM_SIZE + 1));
    return (info);
}

void destroy_info(info_t *info)
{
    champ_t *ch;
    champ_t *old;

    for (int i = 0; info->champs[i] != NULL; i = i + 1) {
        ch = info->champs[i];
        free(ch->s);
        while (ch != NULL) {
            old = ch;
            for (int j = 0; j < REG_NUMBER; j += 1)
                free(ch->registers[j]);
            free(ch->registers);
            ch = ch->next;
            free(old);
        }
    }
    free(info->champs);
    free(info->memory);
    free(info->colors);
    sfMusic_destroy(info->music);
    sfMusic_destroy(info->die_sound);
    free(info);
}