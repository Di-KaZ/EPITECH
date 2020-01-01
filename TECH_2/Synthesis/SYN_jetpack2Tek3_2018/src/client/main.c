/*
** EPITECH PROJECT, 2019
** temp_jetpack
** File description:
** main
*/

#include "client.h"

int connection_protocol(client_parameters_t *client, game_parameters_t *game)
{
    game->id = get_serv_id(client);
    game->map = get_serv_map(client);
    if (game->id < 0 && !game->map)
        return (-1);
    return (0);
}

int start_game(client_parameters_t *client)
{
    game_parameters_t *game = malloc(sizeof(game_parameters_t));
    graphic_display_t *graphic = NULL;
    char *line = NULL;
    pthread_t update_thread;
    update_thread_t update;

    if (connection_protocol(client, game) == 0)
        send_to_serv(client, "READY\n");
    get_command(client, &line);
    if (strcmp(line, "START\n") == 0) {
        graphic = initialize_graphical(game->map->width, game->map->height,
                                game->id, (const char **)game->map->map);
        graphic->client = client;
        update.client = client;
        update.game = game;
        pthread_create(&update_thread, NULL,
            &update_info_cli_thread, (void *)&update);
        start_graphical_n_thread(&update, &update_thread, graphic);
    }
    return (0);
}

int main (int ac, const char **av)
{
    client_parameters_t *client = malloc(sizeof(client_parameters_t));
    int check = initialize_client_param(client, ac, av);

    if (check != 0)
        return (84);
    else {
        if (socket_and_connect(client) == -1)
            return (84);
        start_game(client);
    }
    return (0);
}
