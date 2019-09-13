/*
** EPITECH PROJECT, 2019
** CoreWar
** File description:
** is_same_labels
*/

#include "../include/asm.h"

int is_same_labels(info_t *info)
{
    element_t *a = info->list->first;
    element_t *test = info->list->first;

    for (a = a; a != NULL; a = a->next) {
        for (test = info->list->first; test != NULL; test = test->next) {
            if (test->stock->is_label == 1 && a->stock->is_label == 1 &&
            my_strcmp(a->array[0], test->array[0]) == 0 && a != test)
                return (84);
        }
    }
    return (0);
}