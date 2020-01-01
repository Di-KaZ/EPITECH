/*
** EPITECH PROJECT, 2017
** 
** File description:
** 
*/

#include "my_sokoban.h"

player_t ini_player (char **map)
{
	player_t player = malloc(sizeof(*player));
	player->ori_pos = get_pos(map, 'P');
	player->pos = player->ori_pos;
	return (player);
}
