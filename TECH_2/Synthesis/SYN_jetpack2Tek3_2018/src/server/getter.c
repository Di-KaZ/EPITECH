/*
** EPITECH PROJECT, 2019
** SYN_jetpack2Tek3_2018
** File description:
** getter
*/

#include "server.h"

void get_gravity(server_t *param, const char **arg)
{
    if (strcmp(arg[0], "-g") == 0 && is_alpha(arg[1])) {
        param->gravity = atoi(arg[1]);
    }
}

void get_map(server_t *param, const char **arg)
{
    if (strcmp(*arg, "-m") == 0) {
        param->map = create_map(arg[1], param);
        param->players[0].y = param->max_y / 2;
        param->players[1].y = param->max_y / 2;
    }
}