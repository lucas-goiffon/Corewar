/*
** EPITECH PROJECT, 2019
** CoreWar
** File description:
** take_params
*/

#include "../include/corewar.h"

int *take_parameters(info_t *info, champ_t *ch, op_t op)
{
    int tmp = info->memory[(ch->pc + 1) % MEM_SIZE];
    int *params = my_malloc(sizeof(int) * 4);

    params[0] = (tmp >> 6);
    params[1] = (tmp >> 4) - (params[0] << 2);
    params[2] = ((tmp >> 2) - (params[0] << 4)) - (params[1] << 2);
    params[3] = 0;
    return (params);
}

int verify_parameters(info_t *info, champ_t *ch, op_t op, int *params)
{
    for (int i = 0; i < op.nbr_args; i = i + 1) {
        if (params[i] == 3 && (T_IND & op.type[i]) == 0)
            return (84);
        else if ((params[i] & op.type[i]) == 0)
            return (84);
    }
    for (int i = op.nbr_args; i < 4; i += 1) {
        if (params[i] != 0)
            return (84);
    }
    return (0);
}