/*
** EPITECH PROJECT, 2019
** SYN_jetpack2Tek3_2018
** File description:
** main
*/

#include "server.h"

void close_server(server_t *server)
{
    close(server->s_socket_fd);
    close(server->players[0].fd);
    close(server->players[1].fd);
}

int main (int ac, const char **av)
{
    if (ac == 2 && strcmp(av[1], "-h") == 0) {
        printf(HELP);
        return (0);
    }
    run(av);
    return (0);
}