/*
** EPITECH PROJECT, 2019
** epitech
** File description:
** destroy_double_array
*/

#include "mylib.h"

void destroy_double_array(char **array)
{
    if (array[0] != NULL && array[0][0] == '\0') {
        free(array[0]);
        free(array);
        return;
    }
    for (int i = 0; array[i] != NULL; i = i + 1)
        free(array[i]);
    free(array);
}