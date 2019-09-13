/*
** EPITECH PROJECT, 2019
** CoreWar
** File description:
** insertion_ll
*/

#include "../include/asm.h"

void set_array_insert_two(element_t *new, char *str)
{
    int i = 0;

    for (i = 0; (str[i] == ' ' || str[i] == '\t') && str[i] != '\0'; i++);
    str = &str[i];
    for (i = 0; str[i] != ' ' && str[i] != '\t' && str[i] != '\0'; i = i + 1);
    new->array[0] = my_malloc(sizeof(char) * (i + 1));
    for (int j = 0; j < i; j = j + 1)
        new->array[0][j] = str[j];
    new->array[0][i] = '\0';
    str = &str[i];
    for (i = 0; (str[i] == ' ' || str[i] == '\t') && str[i] != '\0'; i++);
    str = &str[i];
    for (i = 0; str[i] != '\0'; i = i + 1);
    for (i = i; i > 0 && (str[i] == ' ' || str[i] == '\t'); i = i - 1);
    i = i + 1;
    new->array[1] = my_malloc(sizeof(char) * (i + 1));
    for (int j = 0; j < i; j = j + 1)
        new->array[1][j] = str[j];
    new->array[1][i] = '\0';
}

int set_array_insert(element_t *new, char *str)
{
    int i = 0;

    for (i = 0; (str[i] == ' ' || str[i] == '\t') && str[i] != '\0'; i++);
    if (str[i] != '.') {
        new->array = stwa_asm(str);
        if (new->array[0][0] == '\0' || new->array[0][0] == COMMENT_CHAR) {
            destroy_double_array(new->array);
            free(new);
            free(str);
            return (1);
        }
    } else {
        str = &str[i];
        new->array = my_malloc(sizeof(char *) * 3);
        new->array[2] = NULL;
        set_array_insert_two(new, str);
    }
    return (0);
}

element_t *insertion_end(list_t *list, char *str)
{
    element_t *new = my_malloc(sizeof(*new));

    if (set_array_insert(new, str) == 1)
        return (NULL);
    free(str);
    new->stock = NULL;
    if (list->first == NULL && list->last == NULL) {
        new->prev = NULL;
        list->first = new;
        list->last = new;
        new->next = NULL;
    } else {
        new->prev = list->last;
        list->last->next = new;
        new->next = NULL;
        list->last = new;
    } list->lenght = list->lenght + 1;
    return (new);
}