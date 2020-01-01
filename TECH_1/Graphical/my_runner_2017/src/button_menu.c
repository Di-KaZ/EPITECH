/*
** EPITECH PROJECT, 2018
** 
** File description:
** 
*/

#include "run.h"

int button_exit (window_t *window, menu_t menu)
{
	sfVector2i mouse_pos = sfMouse_getPosition((sfWindow*)window->window);

	if (mouse_pos.y >= 658 && mouse_pos.y <= 720) {
		sfSprite_setTextureRect(menu->exit->sprite, menu->v_exit);
		if (sfMouse_isButtonPressed(sfMouseLeft)) {
			sfRenderWindow_close(window->window);
		}
	}
	else
		sfSprite_setTextureRect(menu->exit->sprite,
					create_rect(0, 65, 1280, 62));
	return (0);
}

int button_make_map (window_t *window, menu_t menu)
{
	sfVector2i mouse_pos = sfMouse_getPosition((sfWindow*)window->window);

	if (mouse_pos.y >= 581 && mouse_pos.y <= 643) {
		if (sfMouse_isButtonPressed(sfMouseLeft)) {
			help(menu);
		}
		sfSprite_setTextureRect(menu->make_map->sprite, menu->v_make_map);
	}
	else
		sfSprite_setTextureRect(menu->make_map->sprite,
					create_rect(0, 65, 1280, 62));
	return (0);
}
