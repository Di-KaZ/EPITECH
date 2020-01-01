/*
** EPITECH PROJECT, 2019
** SYN_jetpack2Tek3_2018
** File description:
** command_coin
*/

#include "client.h"

int command_coin(update_thread_t *update, char *line)
{
    int x = 0;
    int y = 0;
    sfColor color = {0, 0, 0 , 0};
    line += 5;
    while (*line && *line++ != ' ');
    x = atoi(line);
    while (*line && *line++ != ' ');
    y = atoi(line);
    sfSprite_setColor
    (update->graphic->map->title_map[y][x]->spr, color);
}