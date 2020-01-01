/*
** EPITECH PROJECT, 2018
** pause
** File description:
** pause
*/

#include "my_cook.h"

void pause_menu (void *data)
{
	game_t game = data;

	while (sfRenderWindow_isOpen(game->window->window)) {
		sfRenderWindow_clear(game->window->window, sfBlue);
		disp_scene(game->window, game->scenes, "pause", game);
		while (sfRenderWindow_pollEvent(game->window->window,
						&game->window->event)) {
			if (game->window->event.type == sfEvtClosed)
				sfRenderWindow_close(game->window->window);
		}
		sfRenderWindow_display(game->window->window);
	}
}
