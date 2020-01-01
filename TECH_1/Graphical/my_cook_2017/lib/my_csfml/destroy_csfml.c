/*
** EPITECH PROJECT, 2017
** destroy 
** File description:
** destroy
*/

#include "my_csfml.h"

void destroy_window (window_t **window)
{
	sfRenderWindow_destroy((*window)->window);
	free(*window);
}

void destroy_sprite (sprite_t sprite)
{
	sfSprite_destroy(sprite->sprite);
	free(sprite);
}
