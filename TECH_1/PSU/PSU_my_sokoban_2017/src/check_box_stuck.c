/*
** EPITECH PROJECT, 2017
** 
** File description:
** 
*/

#include "my_sokoban.h"

void check_box_stuck (box_t boxes, char **map)
{
	while (boxes != NULL) {
		if  (map[boxes->pos.y][boxes->pos.x - 1] == '#' ||
		     map[boxes->pos.y][boxes->pos.x + 1] == '#') {
			boxes->is_stuck_x = 1;
		}
		else {
			boxes->is_stuck_x = 0;
		}
		if (map[boxes->pos.y - 1][boxes->pos.x] == '#' ||
		    map[boxes->pos.y + 1][boxes->pos.x] == '#') {
			boxes->is_stuck_y = 1;
		}
		else {
			boxes->is_stuck_y = 0;
		}
		check_box_ok(boxes, map);
		boxes = boxes->next;
	}
}

void check_box_ok (box_t boxes, char **map)
{
	if (map[boxes->pos.y][boxes->pos.x] == 'O')
		boxes->is_ok = 1;
	else
		boxes->is_ok = 0;
}

int check_win (box_t boxes)
{
	int is_win = 1;

	while (boxes != NULL) {
		if (boxes->is_ok == 0)
			is_win = 0;
		boxes = boxes->next;
	}
	return (is_win);
}

int check_stuck (box_t boxes)
{
	int return_value = 1;

	while (boxes != NULL) {
		if (boxes->is_stuck_x == 0
		    || boxes->is_stuck_y == 0 || boxes->is_ok == 1)
			return_value = 0;
		boxes = boxes->next;
	}
	return (return_value);
}
