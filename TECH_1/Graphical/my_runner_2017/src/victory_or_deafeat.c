/*
** EPITECH PROJECT, 2018
** 
** File description:
** 
*/

 #include "run.h"

void victory (player_t player)
{
	sfMusic_setVolume(player->sounds->fkinlow, 0);
	while (WIN_ISOPEN(player->window)) {
		sfRenderWindow_drawSprite(player->window->window,
					  player->victory->sprite, NULL);
		manage_event(player->window);
		if(sfKeyboard_isKeyPressed(sfKeyQ)) {
			sfRenderWindow_close(player->window->window);
		}
		sfRenderWindow_display(player->window->window);
	}
}

int defeat (player_t player)
{
	sfMusic_setVolume(player->sounds->fkinlow, 0);
	while (WIN_ISOPEN(player->window)) {
		sfRenderWindow_drawSprite(player->window->window,
					  player->dead->sprite, NULL);
		manage_event(player->window);
		if(sfKeyboard_isKeyPressed(sfKeyQ)) {
			sfRenderWindow_close(player->window->window);
		}
		sfRenderWindow_display(player->window->window);
	}
	return (1);
}

void help (menu_t menu)
{
	while (1) {
		sfRenderWindow_drawSprite(menu->window->window,
					  menu->help->sprite, NULL);
		if (sfKeyboard_isKeyPressed(sfKeyQ))
			break;
		sfRenderWindow_display(menu->window->window);
	}
}
