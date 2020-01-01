/*
** EPITECH PROJECT, 2017
** 
** File description:
** 
*/

#include "my_sokoban.h"

box_t ini_boxes (char **map)
{
	box_t boxes = NULL;

	for (int i = 0; map[i] != NULL; i += 1) {
		for (int j = 0; map[i][j] != '\0'; j += 1) {
			if (map[i][j] == 'X' && boxes != NULL) {
				boxes = fill_box(boxes, j, i);
			}
			if (map[i][j] == 'X' && boxes == NULL)
				boxes = fill_box(NULL, j, i);
		}
	}
	return (boxes);
}

box_t fill_box (box_t boxes, int x , int y)
{
	box_t box = malloc(sizeof(*box));

	box->pos.x = x;
	box->pos.y = y;
	box->ori_pos = box->pos;
	box->next = boxes;

	return (box);
}

void free_boxes (box_t boxes)
{
	box_t temp = boxes;

	while (boxes != NULL) {
		temp = boxes;
		boxes = boxes->next;
		free(temp);
	}
	free(boxes);
}
