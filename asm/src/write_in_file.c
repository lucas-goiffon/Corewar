/*
** EPITECH PROJECT, 2019
** CoreWar
** File description:
** write_in_file
*/

#include "../include/asm.h"

void write_in(info_t *info, element_t *a, int i, int fd)
{
    int nb = 0;

    if (a->stock->size[i] == 1)
        write(fd, &a->stock->to_write[i], 1);
    else if (a->stock->size[i] == 2) {
        nb = SWAP_UINT32(a->stock->to_write[i]);
        nb = (nb << 16) | (nb >> 16);
        write(fd, &nb, 2);
    } else {
        nb = SWAP_UINT32(a->stock->to_write[i]);
        write(fd, &nb, a->stock->size[i]);
    }
}

char *name_of_file(info_t *info)
{
    char *str = my_malloc(sizeof(char) *
    (my_strlen(info->list->file_name) + 1));
    int last_dot = 0;
    char *s = str;

    str = my_strcpy(str, info->list->file_name);
    for (int i = 0; str[i] != '\0'; i = i + 1) {
        if (str[i] == '/') {
            str = &str[i + 1];
            i = 0;
        }
    }
    for (int i = 0; str[i] != '\0'; i = i + 1) {
        if (str[i] == '.')
            last_dot = i;
    }
    str[last_dot] = '\0';
    str = my_strcat_two(str, ".cor");
    free(s);
    return (str);
}

void write_all(info_t *info)
{
    char *str = name_of_file(info);
    int fd = open(str, O_WRONLY | O_TRUNC | O_CREAT, 0666);
    element_t *a = info->list->first;

    if (fd < 0)
        my_exit(info, 84);
    write(fd, &info->header, sizeof(header_t));
    for (a = a; a != NULL; a = a->next) {
        for (int i = 0; a->stock->size[i] != -1; i = i + 1)
            write_in(info, a, i, fd);
    }
    close(fd);
    free(str);
}