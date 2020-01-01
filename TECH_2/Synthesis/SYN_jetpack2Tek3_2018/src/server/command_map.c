/*
** EPITECH PROJECT, 2019
** SYN_jetpack2Tek3_2018
** File description:
** command_map
*/

#include "server.h"

char *get_map_in_line(const char **map, int total_size)
{
    int line_num = 0;
    char *line = malloc(sizeof(char) * (total_size + 1));

    memset(line, 0, total_size);
    if (!line) {
        PRINT_ERROR_MSG_N_RETUN("Unable to alloc", 0);
    }
    while (map[line_num])
        strcat(line, map[line_num++]);
    return (line);
}

int map_cmd(player_t *client,
            __attribute__((unused))const char *line,
            __attribute__((unused))fd_set *readfds,
            char **map)
{
    int x = strlen(map[0]);
    int y = 0;
    char *map_line = NULL;

    while (map[y++]);
    y -= 1;
    map_line = get_map_in_line((const char **)map, x * y);
    if (!map_line)
        return (84);
    dprintf(client->fd, "MAP %d %d %s\n", y, x, map_line);
    free(map_line);
    return (0);
}