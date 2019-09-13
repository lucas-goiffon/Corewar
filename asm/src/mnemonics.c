/*
** EPITECH PROJECT, 2019
** CoreWar
** File description:
** mnemonics
*/

#include "../include/asm.h"

void verify_parameters(element_t *e, info_t *info, stock_t *stock, int op)
{
    int par_type = 0;

    for (int i = 1; i <= op_tab[op].nbr_args; i = i + 1) {
        if ((get_param_type(e->array[i + stock->is_label])
        & op_tab[op].type[i - 1]) == 0)
            my_exit(info, 84);
        if (get_param_type(e->array[i + stock->is_label]) == 4)
            par_type = par_type + 3;
        else {
            par_type = par_type +
            get_param_type(e->array[i + stock->is_label]);
        } par_type = (par_type << 2);
    } for (int i = op_tab[op].nbr_args + 1; i < 4; i = i + 1)
        par_type = (par_type << 2);
    stock->size[0] = 1;
    stock->to_write[0] = op_tab[op].code;
    if (op != 0 && op != 8 && op != 11 && op != 14) {
        stock->size[1] = 1;
        stock->to_write[1] = par_type;
    } e->stock = stock;
    e->op = op;
}

int get_inside_parameter(char *str, info_t *info)
{
    int i = 0;
    char *tests = str;
    int nb = 0;

    if (str[0] == 'r' && str[1] == LABEL_CHAR)
        my_exit(info, 84);
    if (str[i] == DIRECT_CHAR || str[i] == 'r')
        i = i + 1;
    if (i > 0 && (str[i] == DIRECT_CHAR || str[i] == 'r'))
        my_exit(info, 84);
    if (str[i] == LABEL_CHAR)
        return (0);
    str = &str[i];
    if (is_digits(str) != 0)
        my_exit(info, 84);
    nb = my_getnbr(str);
    if (tests[0] == 'r' && (nb < 1 || nb > REG_NUMBER))
        my_exit(info, 84);
    return (nb);
}

void stock_parameters(element_t *e, info_t *info)
{
    int i = 1;

    if (e->op != 0 && e->op != 8 && e->op != 11 && e->op != 14)
        i = i + 1;
    for (int j = 1; j <= op_tab[e->op].nbr_args; j = j + 1) {
        e->stock->size[i] =
        get_param_size(e, e->array[j + e->stock->is_label]);
        e->stock->to_write[i] =
        get_inside_parameter(e->array[j + e->stock->is_label], info);
        i = i + 1;
    }
    e->stock->size[i] = -1;
}

int find_mnemonics(element_t *e, info_t *info, int k)
{
    stock_t *stock = info->stock[k];
    int op = 0;
    if (e->array[0][my_strlen(e->array[0]) - 1] == LABEL_CHAR) {
        stock->is_label = 1;
        if (e->array[1] == NULL || (e->array[1] != NULL &&
        e->array[1][0] == COMMENT_CHAR)) {
            e->stock = stock;
            e->op = op;
            return (-1);
        }
    } for (op = 0; op < 16 &&
    my_strcmp(e->array[stock->is_label], op_tab[op].mnemonique) != 0;
    op = op + 1);
    (op == 16) ? my_exit(info, 84) : 0;
    if (my_tablen(&e->array[stock->is_label]) < op_tab[op].nbr_args + 1 ||
    (e->array[stock->is_label + op_tab[op].nbr_args + 1] != NULL &&
    e->array[stock->is_label + op_tab[op].nbr_args + 1][0] != COMMENT_CHAR))
        my_exit(info, 84);
    verify_parameters(e, info, stock, op);
    stock_parameters(e, info);
    return (0);
}