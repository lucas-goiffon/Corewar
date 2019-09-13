/*
** EPITECH PROJECT, 2019
** CoreWar
** File description:
** main
*/

#include "../include/asm.h"

int error_management(int ac, char **av)
{
    if (ac < 2)
        return (84);
    return (0);
}

int read_file(char *av, list_t *list)
{
    int fd = open(av, O_RDONLY);
    char *str;

    if (fd < 0) {
        my_putstr_error("Failed to open\n");
        return (84);
    }
    list->file_name = av;
    while ((str = get_next_line(fd)) != NULL)
        insertion_end(list, str);
    close(fd);
    return (0);
}

void destroy_all(info_t *info)
{
    destroy_ll(info->list);
    if (info->stock != NULL)
        destroy_stock(info);
    free(info);
}

int loop(char *av)
{
    info_t *info = my_malloc(sizeof(info_t));

    info->list = initialisation_empty();
    info->stock = NULL;
    my_memset(&info->header, 0, sizeof(header_t));
    if (read_file(av, info->list) == 84)
        return (84);
    if (set_header(info, &info->header) == 84)
        return (84);
    if (info->list->first != NULL) {
        init_stock(info);
        if (understanding_file(info) == 84 || badchars_labels(info) == 84 ||
        is_same_labels(info) == 84)
            return (84);
        calcul_prog_size(info);
        call_labels(info);
    }
    write_all(info);
    destroy_all(info);
    return (0);
}

int main(int ac, char **av)
{
    int r = 0;

    if (error_management(ac, av) == 84)
        return (84);
    for (int i = 1; i < ac; i = i + 1) {
        if (loop(av[i]) == 84)
            r = 84;
    }
    if (r == 84)
        my_putstr_error("Error\n");
    return (r);
}