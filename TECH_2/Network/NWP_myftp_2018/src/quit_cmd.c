/*
** EPITECH PROJECT, 2019
** NWP_myftp_2018
** File description:
** quit_cmd
*/

#include "ftp.h"

int none_cmd(player_t *client,
__attribute__ ((unused))const char *line,
__attribute__ ((unused))fd_set *readfds)
{
    send(client->fd, "500\r\n", 5, 0);
    return (0);
}