/*
** EPITECH PROJECT, 2018
** my_strcat_two.c
** File description:
** Evolution of my_strcat.c
*/

#include "mylib.h"

char *my_strcat_two(char *dest, char const *src)
{
    int count = 0;
    int size_dest = my_strlen(dest);
    int size_src = my_strlen(src);
    char *str = malloc(sizeof(char) * (size_dest + size_src + 1));

    fill_str(str, (size_dest + size_src + 1));
    for (int i = 0; dest[i] != '\0'; i = i + 1) {
        str[i] = dest[i];
        count = count + 1;
    }
    for (int j = 0; src[j] != '\0'; j = j + 1) {
        str[count] = src[j];
        count = count + 1;
    }
    str[count] = '\0';
    return (str);
}
