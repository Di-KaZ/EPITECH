/*
** EPITECH PROJECT, 2019
** SYN_jetpack2Tek3_2018
** File description:
** main_plus
*/

#include "server.h"

void register_new_clients(server_t *server)
{
    if (FD_ISSET(server->s_socket_fd, &server->readfds))
            if (accept_new_client(server) == 84) {
                close_server(server);
                exit (84);
            }
        exec_recived_command(server);
}