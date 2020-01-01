/*
** EPITECH PROJECT, 2017
** 
** File description:
** 
*/

#include "my_csfml.h"

void window_clear (window_t *window, sfColor color)
{
	sfRenderWindow_clear(window->window, color);
}

void disp_sprite (window_t *window, sprite_t *sprite)
{
	sfRenderWindow_drawSprite(window->window, sprite->sprite, NULL);
}

void disp_sprite_rect (sprite_t *sprite, int x, int y, int o_x , int o_y)
{
	sfIntRect rect = {x, y ,o_x, o_y};

	sfSprite_setTextureRect(sprite->sprite, rect);
}

void set_sprite_pos (sprite_t * sprite, int x, int y)
{
	sfVector2f vec = {x, y};

	sfSprite_setPosition(sprite->sprite, vec);
}

void set_sprite_scale (sprite_t * sprite, int x, int y)
{
	sfVector2f scale = {x, y};

	sfSprite_setScale(sprite->sprite, scale);
}
