/*
** EPITECH PROJECT, 2018
** linked_lists.c
** File description:
** basics functions for linked_lists
*/

#include "../include/asm.h"

void print_list(list_t *list)
{
    element_t *actual;

    actual = list->first;
    while (actual != NULL) {
        for (int i = 0; actual->array[i] != NULL; i = i + 1)
            my_printf("%s ", actual->array[i]);
        my_putchar('\n');
        actual = actual->next;
    }
}

void destroy_ll(list_t *list)
{
    element_t *actual;
    element_t *next;

    actual = list->first;
    while (actual != NULL) {
        next = actual->next;
        if (actual->array != NULL)
            destroy_double_array(actual->array);
        free(actual);
        actual = next;
    }
    free(list);
}

list_t *initialisation_empty(void)
{
    list_t *list = my_malloc(sizeof(*list));

    if (list == NULL)
        return (NULL);
    list->first = NULL;
    list->last = NULL;
    list->lenght = 0;
    list->file_name = NULL;
    return (list);
}

void delete_middle(list_t *list, element_t *to_delete)
{
    if (list->lenght == 1) {
        free(to_delete);
        list->first = NULL;
        return;
    }
    if (to_delete == list->first) {
        to_delete->next->prev = NULL;
        list->first = to_delete->next;
    } else if (to_delete == list->last) {
        to_delete = list->last;
        to_delete->prev->next = NULL;
        list->last = to_delete->prev;
    } else {
        to_delete->next->prev = to_delete->prev;
        to_delete->prev->next = to_delete->next;
    }
    list->lenght = list->lenght - 1;
    if (to_delete->array != NULL)
        destroy_double_array(to_delete->array);
    free(to_delete);
}