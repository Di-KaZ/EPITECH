/*
** EPITECH PROJECT, 2019
** SYN_jetpack2Tek3_2018
** File description:
** game_algorithm
*/

#include "server.h"


static void send_players_status(player_t *player1, player_t *player2)
{
    dprintf(player1->fd, "PLAYER %d %.1f %.1f %d\n", player1->fd, player1->x,
                                        player1->y, player1->score);
    dprintf(player1->fd, "PLAYER %d %.1f %.1f %d\n", player2->fd, player2->x,
                                        player2->y, player2->score);
    dprintf(player2->fd, "PLAYER %d %.1f %.1f %d\n", player1->fd, player1->x,
                                        player1->y, player1->score);
    dprintf(player2->fd, "PLAYER %d %.1f %.1f %d\n", player2->fd, player2->x,
                                        player2->y, player2->score);
}

static void update_player_pos(player_t *player1, player_t *player2, int gravity)
{
    player1->x += 0.1;
    player2->x += 0.1;

    if (player1->jetpack_status == 1) {
        player1->y -= 0.1 / gravity;
    } else {
        player1->y += 0.1 * gravity;
    }
    if (player2->jetpack_status == 1) {
        player2->y -= 0.1 / gravity;
    } else {
        player2->y += 0.1 * gravity;
    }
}

static void keep_player_in_map(player_t *player1, player_t *player2, int y)
{
    if (player1->y >= y)
        player1-> y = y;
    if (player2->y >= y)
        player2-> y = y;
    if (player1->y <= 0)
        player1-> y = 0;
    if (player2->y <= 0)
        player2-> y = 0;
}

int game_algorithm(server_t *server)
{
    int return_val = 0;

    if (!server->game_started && server->players[0].is_ready &&
                                    server->players[1].is_ready) {
        dprintf(server->players[0].fd, "START\n");
        dprintf(server->players[1].fd, "START\n");
        server->game_started = 1;
    }
    if (server->game_started) {
        send_players_status(&server->players[0], &server->players[1]);
        update_player_pos(&server->players[0], &server->players[1],
                                                        server->gravity);
        keep_player_in_map(&server->players[0], &server->players[1],
                                                        server->max_y);
        return_val = check_collision(server);
        if (return_val != 0)
            return (return_val);
    }
    return (0);
}