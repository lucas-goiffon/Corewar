/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** read_create_file
*/

#include "../include/desassembler.h"

int open_and_read_file(desasm_t *des, char *file)
{
    int fd = open(file, O_RDONLY);

    if (fd < 0) {
        my_putstr_error("Unable to open file\n");
        return (84);
    }
    read(fd, &des->h, sizeof(header_t));
    des->h.prog_size = SWAP_UINT32(des->h.prog_size);
    des->bytes = my_malloc(sizeof(unsigned char) * (des->h.prog_size + 1));
    read(fd, des->bytes, (des->h.prog_size + 1));
    close(fd);
    return (0);
}

int create_file(desasm_t *des, char *old_file)
{
    int j = 0;

    for (int i = 0; old_file[i] != '\0'; i += 1) {
        if (old_file[i] == '/') {
            old_file = &old_file[i + 1];
            i = 0;
        }
        if (old_file[i] == '.')
            j = i;
    }
    if (my_strcmp(&old_file[j], ".cor") != 0)
        return (84);
    old_file[j + 1] = 's';
    old_file[j + 2] = '\0';
    if ((des->fd = open(old_file, O_WRONLY | O_TRUNC | O_CREAT, 0666)) < 0)
        return (84);
    return (0);
}