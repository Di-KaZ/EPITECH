/*
** EPITECH PROJECT, 2017
** 
** File description:
** 
*/

#include "my_csfml.h"

window_t *ini_window (char *name, int width, int height)
{
	window_t *window = malloc(sizeof(*window));
	window->width = width;
	window->height = height;
	sfVideoMode mode = {window->width, window->height, 32};
	window->window = sfRenderWindow_create(mode, name,
			     sfTitlebar | sfClose, NULL);
	SET_FRAMERATE(window, 60);
	return (window);
}

sprite_t *ini_sprite (char *path_to_text)
{
	sprite_t *sprite = malloc(sizeof(*sprite));
	sprite->texture = sfTexture_createFromFile(path_to_text, NULL);
	sprite->sprite = sfSprite_create();
	sfSprite_setTexture(sprite->sprite, sprite->texture, sfTrue);
	return (sprite);
}

clock__t *ini_clock (void)
{
	clock__t *clock = malloc(sizeof(*clock));
	clock->clock = sfClock_create();
	return(clock);
}
