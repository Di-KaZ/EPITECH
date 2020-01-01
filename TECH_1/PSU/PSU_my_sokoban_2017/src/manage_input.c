/*
** EPITECH PROJECT, 2017
** 
** File description:
** 
*/

#include "my_sokoban.h"

const int p_key[4] = {KEY_RIGHT, KEY_LEFT, KEY_UP, KEY_DOWN};
void (*cols[4])(box_t boxes, player_t player, char **map) =
{cols_right, cols_left, cols_up, cols_down};

int manage_input (box_t boxes, player_t player, char **map)
{
	int key = getch();

	for (int i = 0; i < 4; i += 1) {
		if (key == p_key[i])
			cols[i](boxes, player, map);
	}
	if (key == (int)' ')
		reset_map(boxes, player);
	return (0);
}
