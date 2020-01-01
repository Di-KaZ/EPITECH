/*
** EPITECH PROJECT, 2019
** NWP_myftp_2018
** File description:
** run
*/

#include "ftp.h"

int initialize_server_param(server_t *param, const char **av)
{
    for (int i = 0; av[i] && av[i + 1]; i += 1) {
        get_port(param, &av[i]);
        get_gravity(param, &av[i]);
        get_map(param,  &av[i]);
        if (strcmp(av[i], "-h") == 0) {
            printf(HELP);
            exit(0);
        }
    }
    return (param->gravity == -1 ||
            param->map == NULL || param->s_port == -1);
}

int initialize_socket(server_t *server)
{
    server->serv_conf.sin_port = htons(server->s_port);
    server->s_socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server->s_socket_fd < 0)
        return (quit_error(84, ERR_SOCK));
    if (bind(server->s_socket_fd,
        (struct sockaddr *)&server->serv_conf, server->cli_socket_size) < 0)
        return (quit_error(84, ERR_BIND));
    if (listen(server->s_socket_fd, 3) < 0)
        return (quit_error(84, ERR_LISTEN));
    server->last_fd = server->s_socket_fd;
    return (0);
}

int initialize_server(server_t *server, const char **av)
{
    server->serv_conf.sin_family = AF_INET;
    server->serv_conf.sin_addr.s_addr = INADDR_ANY;
    server->last_fd = server->s_socket_fd;
    server->map = NULL;
    server->gravity = -1;
    for (int i = 0; i < 2; i += 1) {
        server->players[i].fd = 0;
    }
    server->new_client_fd = -1;
    server->cli_socket_size = sizeof(server->cli_conf);
    if (initialize_server_param(server, av))
        return (84);
    return (initialize_socket(server));
}

void get_greater_fd(server_t *server)
{
    for (int i = 0; i < 2; i += 1) {
        if (server->players[i].fd != 0)
            FD_SET(server->players[i].fd, &server->readfds);
        if (server->players[i].fd > server->last_fd)
            server->last_fd = server->players[i].fd;
    }
}

int run(const char **av)
{
    server_t server;

    if (initialize_server(&server, av) == 84)
        return (84);
    while (1) {
        FD_ZERO(&server.readfds);
        FD_SET(server.s_socket_fd, &server.readfds);
        get_greater_fd(&server);
        if (select(server.last_fd + 1, &server.readfds,
                        NULL, NULL, NULL) < 0)
            return (quit_error(84, ERR_SELECT));
        if (FD_ISSET(server.s_socket_fd, &server.readfds))
            if (accept_new_client(&server) == 84)
                return (84);
        exec_recived_command(&server);
    }
    return (0);
}