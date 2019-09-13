/*
** EPITECH PROJECT, 2019
** epitech
** File description:
** server
*/

#include "../../include/network.h"

void wait_for_participant_server(network_t *net, info_t *info)
{
    my_printf("\nWaiting for players...\n");
    my_printf("Player 1(You): OK\n");
    for (int i = 1; i < net->s->nb_players; i += 1) {
        listen(net->s->server_socket, 5);
        net->s->p[i]->len = sizeof(struct sockaddr_in);
        net->s->p[i]->client_connected = accept(net->s->server_socket,
        (struct sockaddr *)&net->s->p[i]->client_addr, &net->s->p[i]->len);
        if (net->s->p[i]->client_connected == -1)
            my_exit(info, 84, "Connection refused\n");
        my_printf("Player %d: OK\n", i + 1);
    }
}

void get_champs(network_t *net, info_t *info)
{
    int fd = open(net->files[0], O_WRONLY | O_TRUNC | O_CREAT, 0666);

    if (fd < 0)
        my_exit(info, 84, "Unable to open file\n");
    write_champ_in_file(net->tmp_champ, fd);
    close(fd);
    for (int i = 1; i < net->s->nb_players; i += 1) {
        fd = open(net->files[i], O_WRONLY | O_TRUNC | O_CREAT, 0666);
        if (fd < 0)
            my_exit(info, 84, "Unable to open file\n");
        net->s->p[i]->message[0] = (net->s->nb_players + 48);
        usleep(1000);
        send(net->s->p[i]->client_connected, &net->s->p[i]->message[0], 1, 0);
        usleep(1000);
        for (int nbuffer = 0; nbuffer < R_SIZE; nbuffer +=
        recv(net->s->p[i]->client_connected, &net->s->p[i]->received[nbuffer],
        R_SIZE, 0));
        write_champ_in_file(net->s->p[i]->received, fd);
        close(fd);
    }
}

void send_champions(network_t *net, info_t *info)
{
    int fd = -1;

    for (int i = 1; i < net->s->nb_players; i += 1) {
        for (int j = 0; j < net->s->nb_players; j += 1) {
            if ((fd = open(net->files[j], O_RDONLY)) < 0)
                my_exit(info, 84, "Unable to open champion\n");
            read(fd, net->s->p[i]->message, R_SIZE);
            usleep(1000);
            for (int nbuffer = 0; nbuffer < R_SIZE; nbuffer +=
            send(net->s->p[i]->client_connected,
            &net->s->p[i]->message[nbuffer], R_SIZE, 0));
            usleep(1000);
            for (int nbuffer = 0; nbuffer < R_SIZE; nbuffer +=
            recv(net->s->p[i]->client_connected,
            &net->s->p[i]->received[nbuffer], R_SIZE, 0));
            close(fd);
        }
    }
}

void server_part(network_t *net, info_t *info, char **av)
{
    read_tmp_champ(av, info, net);
    net->s = my_malloc(sizeof(server_t));
    net->s->is_server = 1;
    net->s->nb_players = my_getnbr(av[2]);
    if (net->s->nb_players < 2 || net->s->nb_players > 4)
        my_exit(info, 84, "Bad nb_players\n");
    init_server(net, info);
    wait_for_participant_server(net, info);
    get_champs(net, info);
    send_champions(net, info);
    for (int i = 0; i < net->s->nb_players; i += 1) {
        info->champs[i]->s->file = net->files[i];
        info->champs[i]->s->prog_number = i + 1;
        close(net->s->p[i]->client_connected);
    }
    info->n_curses = 1;
    info->lan = 1;
    close(net->s->server_socket);
}