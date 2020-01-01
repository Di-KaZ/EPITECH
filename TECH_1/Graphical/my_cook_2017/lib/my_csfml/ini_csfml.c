/*
** EPITECH PROJECT, 2017
** ini_csfml 
** File description:
** ini_csfml
*/

#include "my_csfml.h"

window_t *ini_window (char *name, int width, int height)
{
	window_t *window = malloc(sizeof(*window));
	if (!window)
		return(NULL);
	window->width = width;
	window->height = height;
	sfVideoMode mode = {window->width, window->height, 32};
	window->window = sfRenderWindow_create(mode, name,
			     sfTitlebar | sfClose, NULL);
	sfRenderWindow_setFramerateLimit(window->window, 60);
	return (window);
}

sprite_t ini_sprite (char *path_to_text)
{
	sprite_t sprite = malloc(sizeof(*sprite));
	if (!sprite)
		return (NULL);
	sprite->texture = sfTexture_createFromFile(path_to_text, NULL);
	sprite->sprite = sfSprite_create();
	sfSprite_setTexture(sprite->sprite, sprite->texture, sfTrue);
	return (sprite);
}

clocks_t *ini_clock (void)
{
	clocks_t *clock = malloc(sizeof(*clock));
	if (!clock)
		return (NULL);
	clock->clock = sfClock_create();
	return(clock);
}
