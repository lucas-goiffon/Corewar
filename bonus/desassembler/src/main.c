/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** main
*/

#include "../include/desassembler.h"

void set_header(desasm_t *des)
{
    write(des->fd, ".name \"", 7);
    write(des->fd, des->h.prog_name, my_strlen(des->h.prog_name));
    write(des->fd, "\"\n", 2);
    write(des->fd, ".comment \"", 10);
    write(des->fd, des->h.comment, my_strlen(des->h.comment));
    write(des->fd, "\"\n\n", 3);
}

int main(int ac, char **av)
{
    desasm_t *des = my_malloc(sizeof(desasm_t));

    if (ac != 2)
        return (84);
    if (open_and_read_file(des, av[1]) == 84 || create_file(des, av[1]) == 84)
        return (84);
    set_header(des);
    write_instructions(des);
    close(des->fd);
    free(des->bytes);
    free(des);
    return (0);
}