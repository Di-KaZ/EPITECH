/*
** EPITECH PROJECT, 2019
** SYN_jetpack2Tek3_2018
** File description:
** check_collision_algo
*/

#include "server.h"


static void hit_a_coin(server_t *server, int x, int y, int i)
{
    if (server->map[y][x] == 'c') {
            dprintf(server->players[0].fd, "COIN %d %d %d\n",
                                server->players[i].fd, x, y);
            dprintf(server->players[1].fd, "COIN %d %d %d\n",
                                server->players[i].fd, x, y);
            server->map[y][x] = '_';
            server->players[i].score += 1;
    }
}

static int hit_a_fence(server_t *server, int x, int y, int i)
{
    if (server->map[y][x] == 'e') {
        dprintf(server->players[0].fd, "FINISH %d\n", server->players[i].fd);
        dprintf(server->players[1].fd, "FINISH %d\n", server->players[i].fd);
        return (server->players[i].fd);
    }
    return (0);
}

int check_collision(server_t *server)
{
    int x = 0;
    int y = 0;
    int return_val = 0;

    for (int i = 0; i < 2; i += 1) {
        x = server->players[i].x;
        y = server->players[i].y;
        if (x >= server->max_x) {
            dprintf(server->players[0].fd, "FINISH %d\n", -1);
            dprintf(server->players[1].fd, "FINISH %d\n", -1);
            return (-1);
        }
        if (y >= server->max_y)
            y = server->max_y - 1;
        hit_a_coin(server, x, y, i);
        return_val = hit_a_fence(server, x, y, i);
        if (return_val != 0)
            return (return_val);
    }
    return (0);
}
