/*
** EPITECH PROJECT, 2019
** CoreWar
** File description:
** get_parameters
*/

#include "../include/asm.h"

int get_param_type(char *str)
{
    if (str[0] == DIRECT_CHAR)
        return (T_DIR);
    if (str[0] == 'r')
        return (T_REG);
    return (T_IND);
}

int get_param_size(element_t *e, char *str)
{
    if (str[0] == DIRECT_CHAR && op_tab[e->op].code != 9 &&
    op_tab[e->op].code != 10 && op_tab[e->op].code != 11 &&
    op_tab[e->op].code != 12 && op_tab[e->op].code != 14 &&
    op_tab[e->op].code != 15)
        return (DIR_SIZE);
    if (str[0] == DIRECT_CHAR)
        return (IND_SIZE);
    if (str[0] == 'r')
        return (1);
    return (IND_SIZE);
}