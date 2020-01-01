/*
** EPITECH PROJECT, 2019
** SYN_jetpack2Tek3_2018
** File description:
** command_id
*/

#include "server.h"

int id_cmd(player_t *client, __attribute((unused))const char *line,
__attribute__((unused))fd_set *readfds, __attribute__((unused))char **map)
{
    dprintf(client->fd, "ID %d\n", client->fd);
    return (0);
}
