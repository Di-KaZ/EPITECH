/*
** EPITECH PROJECT, 2018
** 
** File description:
** 
*/

#include "run.h"

static const sfVector2f pos[5] = {
	{1280, 100},
	{1280, 270},
	{1280, 350},
	{1280, 450},
	{1280, 590}
};//map position

object_t ini_obj (map_t map)
{
	static object_t list = NULL;
	object_t last = last_obj(list);
	static int i = 0;
	static int j = 0;

	list = free_unused(list);
	if (last == NULL || (sfSprite_getPosition(last->sprite)).x + 163 < 1280) {
		for (j = 0; j < 5; j += 1) {
			if (map->map[j][i] == '\0')
				break;
			if (map->map[j][i] == ' ') {
				list = add_obj_list(list, phantom, pos[j]);
			}
			else
				list = add_obj_list(list, map->map[j][i] - '0',
						    pos[j]);
		}
		i += 1;
	}
	return (list);
}

void disp_obj (object_t first, window_t *window, clocks_t *clock)
{
	while (first != NULL) {
		if (get_elapsed_time(clock) > 0.01) {
			sfSprite_move (first->sprite, create_vect(-5, 0));
		}
		sfSprite_setTextureRect(first->sprite, first->sprite_rect);
		sfRenderWindow_drawSprite(window->window, first->sprite, NULL);
		first = first->next;
	}
}

object_t free_unused (object_t list)
{
	object_t temp = list;

	if (list && sfSprite_getPosition(list->sprite).x + 163 < 0) {
		temp = temp->next;
		delete_object(list);
	}
	return (temp);

}
