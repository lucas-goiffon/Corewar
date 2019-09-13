/*
** EPITECH PROJECT, 2019
** CoreWar
** File description:
** stock
*/

#include "../include/asm.h"

int understanding_file(info_t *info)
{
    int k = 0;
    element_t *actual = info->list->first;
    int res = 84;

    while (actual != NULL) {
        res = find_mnemonics(actual, info, k);
        k = k + 1;
        actual = actual->next;
    }
    return (0);
}

void init_stock(info_t *info)
{
    info->stock = my_malloc(sizeof(stock_t *) * (info->list->lenght + 1));
    info->stock[info->list->lenght] = NULL;
    for (int i = 0; i < info->list->lenght; i = i + 1) {
        info->stock[i] = my_malloc(sizeof(stock_t));
        info->stock[i]->is_label = 0;
        info->stock[i]->size = my_malloc(sizeof(short int) * (6));
        info->stock[i]->to_write = my_malloc(sizeof(int) * (6));
        for (int j = 0; j < 6; j = j + 1) {
            info->stock[i]->size[j] = -1;
            info->stock[i]->to_write[j] = -1;
        }
    }
}

void calcul_prog_size(info_t *info)
{
    element_t *actual = info->list->first;
    int size = 0;

    while (actual != NULL) {
        for (int i = 0; actual->stock->size[i] != -1; i = i + 1) {
            size = size + actual->stock->size[i];
        }
        actual = actual->next;
    }
    info->header.prog_size = SWAP_UINT32(size);
}

void destroy_stock(info_t *info)
{
    for (int i = 0; info->stock[i] != NULL; i = i + 1) {
        free(info->stock[i]->size);
        free(info->stock[i]->to_write);
        free(info->stock[i]);
    }
    free(info->stock);
}