/*
** EPITECH PROJECT, 2018
** get_next_line.c
** File description:
** main file of Get_Next_Line Project
*/

#include <stdlib.h>
#include <unistd.h>
#include "mylib.h"

void fill_str_gnl(char *str, int size, char to_replace)
{
    for (int i = 0; i < size; i = i + 1)
        str[i] = to_replace;
}

int my_strlen_for_gnl(char const *str)
{
    int count = 0;

    while (str[count] != '\0')
        count++;
    return (count);
}

char *my_strcat_for_gnl(char *dest, char const *src)
{
    int count = 0;
    int size_dest = my_strlen_for_gnl(dest);
    int size_src = my_strlen_for_gnl(src);
    char *str = malloc(sizeof(char) * (size_dest + size_src + 1));

    if (str == NULL)
        return (NULL);
    for (int w = 0; w < (size_dest + size_src + 1); w = w + 1)
        str[w] = '\0';
    for (int i = 0; dest[i] != '\0'; i = i + 1) {
        str[i] = dest[i];
        count = count + 1;
    }
    free(dest);
    for (int j = 0; src[j] != '\0'; j = j + 1) {
        str[count] = src[j];
        count = count + 1;
    }
    str[count] = '\0';
    return (str);
}

char *get_next_line(int fd)
{
    char *str = malloc(sizeof(char) * 2);
    char *buff = malloc(sizeof(char) * 2);
    int r = 0;

    if (str == NULL || buff == NULL)
        return (NULL);
    fill_str_gnl(str, 2, '\0');
    fill_str_gnl(buff, 2, '\0');
    if (fd != -1) {
        while ((r = (read(fd, buff, 1))) == 1 && buff[0] != '\n'
        && str != NULL)
            str = my_strcat_for_gnl(str, buff);
        if (r == 0 && str[0] == '\0') {
            free(str);
            free(buff);
            return (NULL);
        }
    }
    free(buff);
    return (str);
}