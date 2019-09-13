/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** online_multi
*/

#include "../../include/network.h"

void write_champ_in_file(unsigned char *prog, int fd)
{
    header_t h;
    void *hh = &h;
    unsigned char *head = hh;
    int size = (sizeof(header_t));

    for (int i = 0; i < (sizeof(header_t)); i += 1)
        head[i] = prog[i];
    size += SWAP_UINT32(h.prog_size);
    write(fd, prog, size);
}

void copy_champion(void *header, unsigned char *prog, network_t *net,
header_t head)
{
    unsigned char *h = header;
    int i = 0;
    int size = SWAP_UINT32(head.prog_size);

    for (i = 0; i < sizeof(header_t); i += 1)
        net->tmp_champ[i] = h[i];
    for (i = 0; i < size; i += 1)
        net->tmp_champ[i + sizeof(header_t)] = prog[i];
}

void read_tmp_champ(char **av, info_t *info, network_t *net)
{
    int fd = open(av[3], O_RDONLY);
    header_t h;
    unsigned char *inside = my_malloc(sizeof(unsigned char) * (R_SIZE + 1));

    net->tmp_champ = my_malloc(sizeof(unsigned char) * (R_SIZE + 1));
    if (fd < 0)
        my_exit(info, 84, "Unable to open champion\n");
    read(fd, &h, sizeof(header_t));
    if ((SWAP_UINT32(h.prog_size) + sizeof(header_t)) > R_SIZE)
        my_exit(info, 84, "Too big champion\n");
    read(fd, inside, SWAP_UINT32(h.prog_size));
    close(fd);
    copy_champion(&h, inside, net, h);
}

int online_multi(int ac, char **av, info_t *info)
{
    network_t *net = my_malloc(sizeof(network_t));
    char *tmp[] = {".champ1.cor", ".champ2.cor", ".champ3.cor", ".champ4.cor"};
    int r = 0;

    net->files = tmp;
    if (ac == 1)
        return (0);
    search_for_help_flag(ac, av, info);
    if (my_strcmp(av[1], "-S") == 0) {
        if (ac < 4)
            my_exit(info, 84, "Bad arguments, try '--help'\n");
        server_part(net, info, av);
        r = 1;
    } else if (my_strcmp(av[1], "-C") == 0) {
        if (ac < 4)
            my_exit(info, 84, "Bad arguments, try '--help'\n");
        client_part(net, info, ac, av);
        r = 1;
    }
    free(net);
    return (r);
}