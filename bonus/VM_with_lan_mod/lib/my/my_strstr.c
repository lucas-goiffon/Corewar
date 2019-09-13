/*
** EPITECH PROJECT, 2018
** my_strstr.c
** File description:
** Prototype_file
*/

#include "mylib.h"

char *my_strstr(char *str, char const *to_find)
{
    int j = 0;
    int begin = -1;
    int count = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == to_find[j] && to_find[j] != '\0' && begin == -1)
            begin = i;
        if (str[i] == to_find[j] && to_find[j] != '\0') {
            count++;
            j++;
        }
    }
    if (count == my_strlen(to_find))
        return (str);
    else
        return (0);
}
