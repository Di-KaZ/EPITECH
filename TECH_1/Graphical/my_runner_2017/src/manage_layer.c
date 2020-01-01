/*
** EPITECH PROJECT, 2018
** 
** File description:
** 
*/

#include "run.h"

layer_t ini_layer (char *path)
{
	layer_t layer = malloc(sizeof(*layer));

	layer->nb1 = ini_sprite(path);
	layer->nb2 = ini_sprite(path);
	layer->temp = NULL;
	return (layer);
}

void display_layer (window_t *window, layer_t layer, sfVector2f vec)
{
	move_sprite(layer->nb1, vec);
	sfSprite_setPosition(layer->nb2->sprite,
			     create_vect(get_sprite_pos(layer->nb1).x + 1280,
					 get_sprite_pos(layer->nb1).y));
	if (get_sprite_pos(layer->nb1).x + 1280 == 0) {
		layer->temp = layer->nb1;
		layer->nb1 = layer->nb2;
		layer->nb2 = layer->temp;
	}
	DISP_SPRITE(window, layer->nb1);
	DISP_SPRITE(window, layer->nb2);
}
