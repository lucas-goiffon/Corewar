/*
** EPITECH PROJECT, 2019
** CoreWar
** File description:
** call_labels
*/

#include "../include/asm.h"

int is_index(info_t *info, char *str, int j, element_t *actual)
{
    int ok = 0;

    if (j < 1 || str == NULL || (actual->stock->is_label == 1 && j < 2))
        return (-1);
    for (int i = 0; str[i] != '\0'; i = i + 1) {
        if (str[i] == LABEL_CHAR)
            ok = 1;
    }
    if (ok == 0)
        return (-1);
    if (str[0] != LABEL_CHAR && str[1] != LABEL_CHAR)
        my_exit(info, 84);
    return (0);
}

char *remove_label_char(info_t *info, element_t *s, int i)
{
    char *str = "";
    int j = 0;

    for (j = 0; s->array[i][j] != '\0'; j = j + 1) {
        if (s->array[i][j] == LABEL_CHAR) {
            str = &s->array[i][j + 1];
            break;
        }
    }
    if (str[0] == '\0' || j > 1)
        my_exit(info, 84);
    return (str);
}

int cmp_label_and_index(info_t *info, element_t *a, char *str)
{
    int size = my_strlen(a->array[0]) - 1;

    if (a->array[0][size] == LABEL_CHAR)
        a->array[0][size] = '\0';
    if (my_strcmp(a->array[0], str) == 0)
        return (0);
    return (-1);
}

void find_corresponding_label(info_t *info, element_t *a, int i)
{
    int count = 0;
    element_t *save = a;
    char *str = remove_label_char(info, save, i);

    for (a = a; a != NULL; a = a->next) {
        if (a->stock->is_label == 1 &&
        cmp_label_and_index(info, a, str) == 0)
            break;
        else
            count = count + add_size_element(info, a);
    }
    if (a == NULL)
        find_corresponding_label_reverse(info, save, str, i);
    else
        stock_count_index(info, save, count, i);
}

void call_labels(info_t *info)
{
    element_t *actual = info->list->first;
    int i = 0;
    int j = 0;

    if (actual == NULL)
        my_exit(info, 84);
    while (actual != NULL) {
        for (i = 1; actual->array[i] != NULL &&
        i < op_tab[actual->op].nbr_args + actual->stock->is_label + 1 &&
        is_index(info, actual->array[i], i, actual) == -1; i = i + 1);
        if (actual->array[i] != NULL &&
        i < op_tab[actual->op].nbr_args + actual->stock->is_label + 1)
            find_corresponding_label(info, actual, i);
        actual = actual->next;
    }
}