/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** init_server
*/

#include "../../include/network.h"

void init_server_following(network_t *net, info_t *info)
{
    int one = 1;

    net->s->server_socket = socket(AF_INET, SOCK_STREAM, 0);
    setsockopt(net->s->server_socket, SOL_SOCKET, SO_REUSEADDR, &one,
    sizeof(one));
    my_memset((char *)&net->s->server_addr, 0, sizeof(net->s->server_addr));
    net->s->server_addr.sin_family = AF_INET;
    net->s->server_addr.sin_port = htons(10000);
    net->s->server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
}

void init_server(network_t *net, info_t *info)
{
    init_server_following(net, info);
    if (bind(net->s->server_socket, (struct sockaddr *)&net->s->server_addr,
    sizeof(net->s->server_addr)) == -1)
        my_exit(info, 84, "Bind Failure\n");
    else
        my_printf("Bind Success:<%u>\n", net->s->server_socket);
    net->s->hostname = gethostname(net->s->hostbuffer,
    sizeof(net->s->hostbuffer));
    net->s->host_entry = gethostbyname(net->s->hostbuffer);
    net->s->ip_buffer = inet_ntoa(*((struct in_addr*)
    net->s->host_entry->h_addr_list[0]));
    my_printf("Hostname: %s\n", net->s->hostbuffer);
    my_printf("Host IP: %s\n", net->s->ip_buffer);
    net->s->p = my_malloc(sizeof(players_t *) * 5);
    for (int i = 0; i < net->s->nb_players; i += 1)
        net->s->p[i] = my_malloc(sizeof(players_t));
}