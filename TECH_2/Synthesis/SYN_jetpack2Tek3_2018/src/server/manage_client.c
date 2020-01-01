/*
** EPITECH PROJECT, 2019
** SYN_jetpack2Tek3_2018
** File description:
** manage_client
*/

#include "server.h"

static const command_pair_t command_pair_g[] =
{
    {"FIRE", &fire_cmd},
    {"READY", &ready_cmd},
    {"MAP", &map_cmd},
    {"ID", &id_cmd},
    {NULL, &none_cmd}
};

int exec_recived_command(server_t *server)
{
    char buf[1024];

    for (int i = 0; i < 2; i += 1) {
        memset(&buf , 0, 1024);
        if (server->players[i].fd == 0 ||
                !FD_ISSET(server->players[i].fd, &server->readfds))
            continue;
        if (recv(server->players[i].fd, &buf, 1024, 0) < 0)
            exit(0);
        printf("\x1b[36m[INFO]\x1b[0m\tPlayer ID : %d send \"%s\"\n",
                                        server->players[i].fd, clean_str(buf));
        for (int j = 0; command_pair_g[j].prompt != NULL; j += 1) {
            if (strstr(buf, command_pair_g[j].prompt)) {
                if (command_pair_g[j].handle_cmd_ptr
                    (&server->players[i], buf, &server->readfds,
                                            server->map) == 84) {
                        PRINT_ERROR_MSG_N_RETUN(ERR_EXEC_CMD, 84);
                    }
                break;
            }
        }
    }
    return (0);
}

int accept_new_client(server_t *server)
{
    server->new_client_fd = accept(server->s_socket_fd,
                    (struct sockaddr *)&server->cli_conf,
                    (socklen_t *)&server->cli_socket_size);
    if (server->new_client_fd < 0) {
        PRINT_ERROR_MSG_N_RETUN(ERR_ACCEPT, 84);
    }
    for (int i = 0; i < 2; i += 1) {
        if (server->players[i].fd == 0) {
            server->players[i].fd = server->new_client_fd;
            FD_SET(server->new_client_fd, &server->readfds);
            printf("\x1b[36m[INFO]\x1b[0m\tNew client connected with id %d\n",
                                                        server->new_client_fd);
            break;
        }
    }
    return (0);
}