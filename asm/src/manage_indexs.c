/*
** EPITECH PROJECT, 2019
** CoreWar
** File description:
** manage_indexs
*/

#include "../include/asm.h"

int add_size_element(info_t *info, element_t *a)
{
    int count = 0;

    for (int i = 0; a->stock->size[i] != -1; i = i + 1)
        count = count + a->stock->size[i];
    return (count);
}

void stock_count_index(info_t *info, element_t *s, int count, int i)
{
    i = i - s->stock->is_label;
    if (s->op != 0 && s->op != 8 && s->op != 11 && s->op != 14)
        i = i + 1;
    s->stock->to_write[i] = count;
}

void find_corresponding_label_reverse(info_t *info, element_t *s, char *str,
int i)
{
    int count = 0;
    element_t *a = s;

    a = a->prev;
    for (a = a; a != NULL; a = a->prev) {
        count = count - add_size_element(info, a);
        if (a->stock->is_label == 1 &&
        cmp_label_and_index(info, a, str) == 0)
            break;
    }
    if (a == NULL)
        my_exit(info, 84);
    stock_count_index(info, s, count, i);
}