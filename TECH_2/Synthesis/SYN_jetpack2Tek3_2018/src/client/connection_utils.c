/*
** EPITECH PROJECT, 2019
** jetpack2tek3
** File description:
** socket_utils
*/

#include "client.h"

int get_serv_id(client_parameters_t *client)
{
    char *command = NULL;
    int id = 0;

    send_to_serv(client, "ID\n");
    if (get_command(client, &command) == -1)
        return (-1);
    id = atoi(command + 3);
    free(command);
    return (id);
}

int get_serv_width(char *command)
{
    int i = 0;

    while (command[i] && command[i++] != ' ');
    return (atoi(command + i));
}

int get_serv_height(char *command)
{
    int i = 0;

    while (command[i] && command[i] != ' ')
        i++;
    i++;
    while (command[i] && command[i] != ' ')
        i++;
    i++;
    return (atoi(command + i));
}

char **get_map(char *command, int width, int height)
{
    int i = 0;
    int j = 0;

    while (command[i] && command[i] != ' ')
        i++;
    i++;
    while (command[i] && command[i] != ' ')
        i++;
    i++;
    while (command[i] && command[i] != ' ')
        i++;
    i++;
    return (str_to_wordtab(command + i, width, height));
}

map_parameters_t *get_serv_map(client_parameters_t *client)
{
    map_parameters_t *map = malloc(sizeof(map_parameters_t));
    char *command = NULL;

    send_to_serv(client, "MAP\n");
    if (get_command(client, &command) == -1)
        return (NULL);
    command[strlen(command) - 1] = '\0';
    map->height = get_serv_width(command);
    map->width = get_serv_height(command);
    map->map = get_map(command, map->width, map->height);
    return (map);
}