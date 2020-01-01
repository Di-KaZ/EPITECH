/*
** EPITECH PROJECT, 2017
** 
** File description:
** 
*/

#include "my_sokoban.h"

void cols_right (box_t boxes, player_t player, char **map)
{
	while (boxes != NULL) {
		if (map[player->pos.y][player->pos.x + 1] == '#' ||
		    (player->pos.x + 1 == boxes->pos.x &&
		     player->pos.y == boxes->pos.y && boxes->is_stuck_x == 1))
			return;
		if (player->pos.x + 1 == boxes->pos.x &&
		    map[boxes->pos.y][boxes->pos.x + 1] != '#' &&
		    player->pos.y == boxes->pos.y &&
		    boxes->is_stuck_x == 0) {
			boxes->pos.x += 1;
			player->pos.x += 1;
			return;
		}
		boxes = boxes->next;
	}
	player->pos.x += 1;
}

void cols_left (box_t boxes, player_t player, char **map)
{
	while (boxes != NULL) {
		if (map[player->pos.y][player->pos.x - 1] == '#' ||
		    (player->pos.x - 1 == boxes->pos.x &&
		     player->pos.y == boxes->pos.y && boxes->is_stuck_x == 1))
			return;
		if (player->pos.x - 1 == boxes->pos.x &&
		    map[boxes->pos.y][boxes->pos.x - 1] != '#' &&
		    player->pos.y == boxes->pos.y &&
		    boxes->is_stuck_x == 0) {
			boxes->pos.x -= 1;
			player->pos.x -= 1;
			return;
		}
		boxes = boxes->next;
	}
	player->pos.x -= 1;
}

void cols_down (box_t boxes, player_t player, char **map)
{
	while (boxes != NULL) {
		if (map[player->pos.y + 1][player->pos.x] == '#' ||
		    (player->pos.x == boxes->pos.x &&
		     player->pos.y + 1 == boxes->pos.y && boxes->is_stuck_y == 1))
			return;
		if (player->pos.x == boxes->pos.x &&
		    map[boxes->pos.y + 1][boxes->pos.x] != '#' &&
		    player->pos.y + 1 == boxes->pos.y &&
		    boxes->is_stuck_y == 0) {
			boxes->pos.y += 1;
			player->pos.y += 1;
			return;
		}
		boxes = boxes->next;
	}
	player->pos.y += 1;
}

void cols_up (box_t boxes, player_t player, char **map)
{
	while (boxes != NULL) {
		if (map[player->pos.y - 1][player->pos.x] == '#' ||
		    (player->pos.x == boxes->pos.x &&
		     player->pos.y - 1 == boxes->pos.y && boxes->is_stuck_y == 1))
			return;
		if (player->pos.x == boxes->pos.x &&
		    map[boxes->pos.y - 1][boxes->pos.x] != '#' &&
		    player->pos.y - 1 == boxes->pos.y &&
		    boxes->is_stuck_y == 0) {
			boxes->pos.y -= 1;
			player->pos.y -= 1;
			return;
		}
		boxes = boxes->next;
	}
	player->pos.y -= 1;
}

void reset_map (box_t boxes, player_t player)
{
	player->pos = player->ori_pos;
	while (boxes != NULL) {
		boxes->pos = boxes->ori_pos;
		boxes = boxes->next;
	}
}
