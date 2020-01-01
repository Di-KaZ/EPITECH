/*
** EPITECH PROJECT, 2019
** jetpack2Tek3
** File description:
** initialize_client
*/


#include "client.h"

int check_host(char *ip, const char *port)
{
    struct addrinfo hints = { 0, 0, 0, 0, 0, 0, 0, 0 };
    struct addrinfo *addrs = { 0 };

    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_protocol = 0;
    int status = getaddrinfo(ip, port, &hints, &addrs);
    if (status != 0) {
        printf("No such hostname: '%s'\n", ip);
        return (-1);
    }
    return (0);
}

int initialize_client_param(client_parameters_t *client, int ac,
    const char **av)
{
    if (((ac-1) % 2) == 1)
        return (-1);
    client->sd = 0;
    for (int i = 0; av[i]; i++) {
        if (strcmp(av[i], "-h") == 0 && av[i + 1])
            client->ip = (char *)av[i + 1];
        if (strcmp(av[i], "-p") == 0 && av[i + 1])
            client->port = (char *)av[i + 1];
    }
    if (client->port != NULL) {
        if (client->ip && check_host
                        (client->ip, client->port) < 0)
                return (84);
        return (0);
    }
    return (-1);
}

int socket_and_connect(client_parameters_t *client)
{
    client->sd = socket(AF_INET, SOCK_STREAM, 0);
    if (client->sd < 0) {
        close(client->sd);
        return (-1);
    }
    memset(&client->socketServ, 0, sizeof(client->socketServ));
    client->socketServ.sin_family = AF_INET;
    client->socketServ.sin_port = htons(atoi(client->port));
    if (connect(client->sd, (struct sockaddr *)&client->socketServ,
                                sizeof(client->socketServ)) == -1) {
        close(client->sd);
        return (-1);
    }
    return (0);
}