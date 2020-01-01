/*
** EPITECH PROJECT, 2019
** SYN_jetpack2Tek3_2018
** File description:
** command_id
*/

#include "server.h"

void get_port(server_t *param, const char **arg)
{
    if (strcmp(arg[0], "-p") == 0 &&
        strlen(arg[1]) == 4 &&
        is_alpha(arg[1])) {
        param->s_port = atoi(arg[1]);
    }
}

int ready_cmd(player_t *client, __attribute((unused))const char *line,
__attribute__((unused))fd_set *readfds, __attribute__((unused))char **map)
{
    client->is_ready = 1;
    printf("\x1b[36m[INFO]\x1b[0m\tPlayer ID : %d is now ready\n", client->fd);
    return (0);
}
