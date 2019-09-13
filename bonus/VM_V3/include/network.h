/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** network
*/

#ifndef NETWORK_H_
#define NETWORK_H_

#include "../lib/my/mylib.h"
#include "corewar.h"

#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <arpa/inet.h>

#define R_SIZE 4192

typedef struct players_s players_t;
struct players_s {
    struct sockaddr_in client_addr;
    int client_connected;
    socklen_t len;
    unsigned char message[R_SIZE];
    unsigned char received[R_SIZE];
};

typedef struct server_s server_t;
struct server_s {
    int is_server;

    int hostname;
    struct hostent *host_entry;
    struct hostent *ptrh;
    char hostbuffer[256];
    struct sockaddr_in server_addr;
    int server_socket;
    char *ip_buffer;

    players_t **p;
    int nb_players;
};

typedef struct client_s client_t;
struct client_s {
    int is_client;

    struct hostent *ptrh;
    struct sockaddr_in server_addr;

    int client_socket;
    unsigned char message[R_SIZE];
    unsigned char received[R_SIZE];
};

typedef struct network_s network_t;
struct network_s {
    server_t *s;
    client_t *c;
    unsigned char *tmp_champ;
    char **files;
};

/* src/network/online_multi.c */
void copy_champion(void *header, unsigned char *prog, network_t *net,
header_t head);
void write_champ_in_file(unsigned char *prog, int fd);
void read_tmp_champ(char **av, info_t *info, network_t *net);
int online_multi(int ac, char **av, info_t *info);

/* src/network/init_server.c */
void init_server_following(network_t *net, info_t *info);
void init_server(network_t *net, info_t *info);

/* src/network/server.c */
void wait_for_participant_server(network_t *net, info_t *info);
void get_champs(network_t *net, info_t *info);
void send_champions(network_t *net, info_t *info);
void server_part(network_t *net, info_t *info, char **av);

/* src/network/client.c */
void verify_ip(info_t *info, char *ip);
void init_client(network_t *net, info_t *info, char *ip);
void receive_champions(network_t *net, info_t *info, int nb_players);
void client_part(network_t *net, info_t *info, int ac, char **av);

#endif /* !NETWORK_H_ */