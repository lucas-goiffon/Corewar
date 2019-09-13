/*
** EPITECH PROJECT, 2019
** CoreWar
** File description:
** badchars_labels
*/

#include "../include/asm.h"

int verify_badchars(element_t *actual)
{
    int j = 0;
    int i = 0;

    for (i = 0; actual->array[0][i] != '\0' &&
    actual->array[0][i] != LABEL_CHAR; i = i + 1) {
        for (j = 0; LABEL_CHARS[j] != '\0' &&
        actual->array[0][i] != LABEL_CHARS[j]; j = j + 1);
        if (LABEL_CHARS[j] == '\0')
            return (84);
    }
    return (0);
}

int badchars_labels(info_t *info)
{
    element_t *actual = info->list->first;

    while (actual != NULL) {
        if (actual->stock->is_label == 1 && verify_badchars(actual) == 84)
            return (84);
        actual = actual->next;
    }
    return (0);
}