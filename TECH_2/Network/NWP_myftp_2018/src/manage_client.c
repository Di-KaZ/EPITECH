/*
** EPITECH PROJECT, 2019
** NWP_myftp_2018
** File description:
** manage_client
*/

#include "ftp.h"

static const command_pair_t command_pair_g[] =
{
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
            return (84);
        printf("recived = %s", buf);
        for (int j = 0; command_pair_g[j].prompt != NULL; j += 1) {
            if (strstr(buf, command_pair_g[j].prompt)) {
                if (command_pair_g[j].handle_cmd_ptr
                    (&server->players[i], buf, &server->readfds) == 84)
                    return (quit_error(84, ERR_EXEC_CMD));
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
    if (server->new_client_fd < 0)
        return (quit_error(84, ERR_ACCEPT));
    printf(INFO_CON_CLI, inet_ntoa(server->serv_conf.sin_addr),
                            ntohs(server->serv_conf.sin_port));
    for (int i = 0; i < 2; i += 1) {
        if (server->players[i].fd == 0) {
            server->players[i].fd = server->new_client_fd;
            FD_SET(server->new_client_fd, &server->readfds);
            printf("new set client fd : %d\n", server->new_client_fd);
            break;
        }
    }
    return (0);
}