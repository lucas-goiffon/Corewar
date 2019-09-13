/*
** EPITECH PROJECT, 2018
** concat_params.c
** File description:
** task02 of CPool Day08
*/

#include <stdlib.h>
#include "mylib.h"

char *concat_params(int argc, char **argv)
{
    char *str;
    int	i = 0;
    int size = 0;

    for (int j = 0; j < argc; j++) {
        size = size + my_strlen(argv[j]) + 1;
    }
    size--;
    str	= malloc(sizeof(char) * size);
    while (i < size) {
        if (argv[0][i] == '\0') {
            str[i] = '\n';
            i++;
        }
        str[i] = argv[0][i];
        i++;
    }
    str[i] = '\0';
    return (str);
}
