/*
** EPITECH PROJECT, 2017
** 
** File description:
** 
*/

#include "my_csfml.h"

void move_sprite (sprite_t *sprite, int x, int y)
{
	sfVector2f move = {x, y};

	sfSprite_move(sprite->sprite, move);
}

sfVector2f get_sprite_pos (sprite_t *sprite)
{
	sfVector2f pos = sfSprite_getPosition(sprite->sprite);

	return(pos);
}

void mul_sprite_scale (sprite_t *sprite, int x, int y)
{
	sfVector2f mul = {x, y};

	sfSprite_scale(sprite->sprite, mul);
}
