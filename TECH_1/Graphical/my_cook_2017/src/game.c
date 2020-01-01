/*
** EPITECH PROJECT, 2018
** game
** File description:
** game
*/

#include "my_cook.h"

static void play_display (game_t game, scene_t play)
{
	object_t food = play->objs;
	sfRenderWindow_clear(game->window->window, sfBlue);
	sfRenderWindow_drawSprite(game->window->window,
		find_object(play->objs,RBACKGROUND)->sprite->sprite, NULL);
	sfRenderWindow_drawSprite(game->window->window,
				  game->client->sprite->sprite, NULL);
	manage_client(game->client);
	manage_food (play->objs, find_object(play->objs, STOVE));
	disp_scene(game->window, game->scenes, "play", game);
	while (food) {
		if ((food->type & FOOD))
			sfRenderWindow_drawSprite(game->window->window,
				food->sprite->sprite, NULL);
		food = food->next;
	}
	disp_ingredients_menu(game);
}

void play (void *data)
{
	game_t game = data;
	scene_t play = find_scene(game->scenes, "play");
	while (sfRenderWindow_isOpen(game->window->window)) {
		play_display(game, play);
		while (sfRenderWindow_pollEvent(game->window->window,
					&game->window->event)) {
			if (game->window->event.type == sfEvtClosed)
				sfRenderWindow_close(game->window->window);
			if (game->window->event.type == sfEvtKeyReleased &&
			    game->window->event.key.code == sfKeyEscape)
				pause_menu(game);
		}
		sfRenderWindow_display(game->window->window);
	}
}

void quit (void *data)
{
	game_t game = data;

	sfRenderWindow_close(game->window->window);
}

void menu (void *data)
{
	game_t game = data;

	while (sfRenderWindow_isOpen(game->window->window)) {
		sfRenderWindow_clear(game->window->window, sfBlue);
		disp_scene(game->window, game->scenes, "menu", game);
		while (sfRenderWindow_pollEvent(game->window->window,
					&game->window->event)) {
			if (game->window->event.type == sfEvtClosed)
				sfRenderWindow_close(game->window->window);
		}
		sfRenderWindow_display(game->window->window);
	}
}

void options (void *data)
{
	game_t game = data;

	while (sfRenderWindow_isOpen(game->window->window)) {
		sfRenderWindow_clear(game->window->window, sfBlue);
		disp_scene(game->window, game->scenes, "option", game);
		while (sfRenderWindow_pollEvent(game->window->window,
					&game->window->event)) {
			if (game->window->event.type == sfEvtClosed)
				sfRenderWindow_close(game->window->window);
		}
		sfRenderWindow_display(game->window->window);
	}
}
