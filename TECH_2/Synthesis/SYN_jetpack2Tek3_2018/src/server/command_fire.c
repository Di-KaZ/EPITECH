/*
** EPITECH PROJECT, 2019
** SYN_jetpack2Tek3_2018
** File description:
** command_id
*/

#include "server.h"

int fire_cmd(player_t *client, __attribute((unused))const char *line,
__attribute__((unused))fd_set *readfds, __attribute__((unused))char **map)
{
    client->jetpack_status = client->jetpack_status == 1 ? 0 : 1;
    printf("\x1b[36m[INFO]\x1b[0m\tPlayer ID : %d is jetpack status is now : "
                                "%d\n", client->fd, client->jetpack_status);
    return (0);
}
