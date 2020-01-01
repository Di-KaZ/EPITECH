/*
** EPITECH PROJECT, 2017
** 
** File description:
** 
*/

#include "my_csfml.h"

void move_sprite (sprite_t sprite, sfVector2f vec)
{
	sfSprite_move(sprite->sprite, vec);
}

sfVector2f get_sprite_pos (sprite_t sprite)
{
	sfVector2f pos = sfSprite_getPosition(sprite->sprite);

	return(pos);
}

sfIntRect create_rect (int x, int y, int off_x, int off_y)
{
	sfIntRect rect = {x, y, off_x, off_y};

	return (rect);
}

sfVector2f create_vect (float x, float y)
{
	sfVector2f vect = {x, y};

	return (vect);
}
