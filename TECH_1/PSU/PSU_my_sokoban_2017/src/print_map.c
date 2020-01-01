/*
** EPITECH PROJECT, 2017
** 
** File description:
** 
*/

#include "my_sokoban.h"

void print_map (char **map)
{
	for (int i = 0; map[i] != NULL; i += 1) {
		for (int j = 0; map[i][j] != '\n'; j += 1) {
			if (NOT_OBJECTS(map[i][j]))
				mvaddch(i, j, map[i][j] | COLOR_PAIR(1));
			if (IS_O(map[i][j]))
				mvaddch(i, j, map[i][j] | COLOR_PAIR(3));
			if (IS_GROUND(map[i][j]))
				mvaddch(i, j, ' ' | COLOR_PAIR(3));
		}
	}
}

vector_t get_pos(char **map, char who)
{
	int x = 0;
	int y = 0;
	vector_t pos = {-1, -1};

	while (map[y] != NULL) {
		x = 0;
		while (map[y][x] != '\0') {
			if (map[y][x] == who) {
				pos.x = x;
				pos.y = y;
			}
			x += 1;
		}
		y += 1;
	}
	return (pos);
}

int manage_screen (char **map, player_t player, box_t boxes)
{
	print_map(map);
	print_player(player);
	print_boxes(boxes);
	check_box_stuck(boxes, map);
	if (check_stuck(boxes) == 1) {
		free_boxes(boxes);
		free(map);
		my_put_exit("You loose !\n", 12, 1);
	}
	if (check_win(boxes) == 1 || manage_input(boxes, player, map) == 1)
		return (1);
	return (0);
}

void print_player (player_t player)
{
	mvaddch(player->pos.y, player->pos.x , 'P' | COLOR_PAIR(2));
}

void print_boxes (box_t boxes)
{
	while (boxes != NULL) {
		mvaddch(boxes->pos.y, boxes->pos.x, 'X' | COLOR_PAIR(4));
		boxes = boxes->next;
	}
}
