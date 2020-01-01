/*
** EPITECH PROJECT, 2019
** SYN_jetpack2Tek3_2018
** File description:
** run
*/

#include "server.h"

int initialize_server_param(server_t *param, const char **av)
{
    for (int i = 0; av[i] && av[i + 1]; i += 1) {
        get_port(param, &av[i]);
        get_gravity(param, &av[i]);
        get_map(param,  &av[i]);
    }
    return (param->gravity == -1 ||
            param->map == NULL || param->s_port == -1);
}

int initialize_socket(server_t *server)
{
    server->serv_conf.sin_port = htons(server->s_port);
    server->s_socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server->s_socket_fd < 0) {
        PRINT_ERROR_MSG_N_RETUN(ERR_SOCK, 84);
    }
    if (bind(server->s_socket_fd,
        (struct sockaddr *)&server->serv_conf, server->cli_socket_size) < 0) {
            PRINT_ERROR_MSG_N_RETUN(ERR_BIND, 84);
        }
    if (listen(server->s_socket_fd, 3) < 0) {
        PRINT_ERROR_MSG_N_RETUN(ERR_LISTEN, 84);
    }
    printf("\x1b[36m[INFO]\x1b[0m\tstarted server on port : %d\n",
                                                server->s_port);
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
    server->game_started = 0;
    for (int i = 0; i < 2; i += 1) {
        server->players[i].fd = 0;
        server->players[i].jetpack_status = 0;
        server->players[i].is_ready = 0;
        server->players[i].score = 0;
        server->players[i].x = 0;
    }
    server->new_client_fd = -1;
    server->cli_socket_size = sizeof(server->cli_conf);
    if (initialize_server_param(server, av))
        return (84);
    return (initialize_socket(server));
}

void get_greater_fd(server_t *server)
{
    FD_ZERO(&server->readfds);
    FD_SET(server->s_socket_fd, &server->readfds);
    for (int i = 0; i < 2; i += 1) {
        if (server->players[i].fd != 0)
            FD_SET(server->players[i].fd, &server->readfds);
        if (server->players[i].fd > server->last_fd)
            server->last_fd = server->players[i].fd;
    }
    server->timeout.tv_sec = 0;
    server->timeout.tv_usec = 62500;
}

int run(const char **av)
{
    server_t server;
    int return_val = 0;

    if (initialize_server(&server, av) == 84)
        return (84);
    while (1) {
        get_greater_fd(&server);
        if (select(server.last_fd + 1, &server.readfds,
                        NULL, NULL, &server.timeout) < 0) {
            PRINT_ERROR_MSG_N_RETUN(ERR_SELECT, 84);
        }
        register_new_clients(&server);
        return_val = game_algorithm(&server);
        if (return_val != 0)
            return (return_val);
    }
    close_server(&server);
    return (0);
}