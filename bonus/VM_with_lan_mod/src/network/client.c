/*
** EPITECH PROJECT, 2019
** epitech
** File description:
** client
*/

#include "../../include/network.h"

void verify_ip(info_t *info, char *ip)
{
    for (int i = 0; ip[i] != '\0'; i += 1) {
        if ((ip[i] < 48 || ip[i] > 57) && ip[i] != '.')
            my_exit(info, 84, "Bad IP formating\n");
    }
}

void init_client(network_t *net, info_t *info, char *ip)
{
    net->c->client_socket = socket(AF_INET, SOCK_STREAM, 0);
    my_memset((char *)&net->c->server_addr, 0, sizeof(net->c->server_addr));
    net->c->server_addr.sin_family = AF_INET;
    net->c->server_addr.sin_port = htons(10000);
    net->c->ptrh = gethostbyname(ip);
    my_memcpy(&net->c->server_addr.sin_addr, net->c->ptrh->h_addr,
    net->c->ptrh->h_length);
    if ((connect(net->c->client_socket, (struct sockaddr *)&net->c->server_addr,
    sizeof(net->c->server_addr))) == -1)
        my_exit(info, 84, "Bad IP address\n");
}

void receive_champions(network_t *net, info_t *info, int nb_players)
{
    int fd = -1;

    for (int i = 0; i < nb_players; i += 1) {
        if ((fd = open(net->files[i], O_WRONLY | O_TRUNC | O_CREAT, 0666)) < 0)
            my_exit(info, 84, "Unable to open champion\n");
        for (int nbuffer = 0; nbuffer < R_SIZE; nbuffer +=
        recv(net->c->client_socket, &net->c->received[nbuffer], R_SIZE, 0));
        write_champ_in_file(net->c->received, fd);
        u_strcpy(net->c->message, "OK", 2);
        usleep(1000);
        for (int nbuffer = 0; nbuffer < R_SIZE; nbuffer +=
        send(net->c->client_socket, &net->c->message[nbuffer], R_OK, 0));
        close(fd);
    }
}

void send_client_champ(network_t *net, info_t *info, int *nb_players)
{
    int len = 0;

    recv(net->c->client_socket, net->c->received, 1, 0);
    u_strcpy(net->c->message, net->tmp_champ, R_SIZE);
    usleep(1000);
    for (int nbuffer = 0; nbuffer < R_SIZE; nbuffer += len)
        len = send(net->c->client_socket, &net->c->message[nbuffer],
        R_SIZE, 0);
    *nb_players = my_getnbr(net->c->received);
    my_printf("There are %d players\n", *nb_players);
}

void client_part(network_t *net, info_t *info, int ac, char **av)
{
    int nb_players = 0;

    read_tmp_champ(av, info, net);
    net->c = my_malloc(sizeof(client_t));
    net->c->is_client = 1;
    verify_ip(info, av[2]);
    init_client(net, info, av[2]);
    send_client_champ(net, info, &nb_players);
    receive_champions(net, info, nb_players);
    for (int i = 0; i < nb_players; i += 1) {
        info->champs[i]->s->file = net->files[i];
        info->champs[i]->s->prog_number = i + 1;
    }
    info->n_curses = 1;
    info->lan = 1;
    close(net->c->client_socket);
}