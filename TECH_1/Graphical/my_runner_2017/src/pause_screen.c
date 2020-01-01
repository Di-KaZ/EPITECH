/*
** EPITECH PROJECT, 2018
** 
** File description:
** 
*/

#include "run.h"

const int fps_rate[3] = {30, 60, 120};
const char *fps_show[3] = {"30", "60", "120"};
const char *skin_sel[3] = {"Normal", "Old school", "Undead"};

void disp_text (map_t map, int current, int skin)
{
	sfText_setString(map->fps, fps_show[current - 1]);
	sfText_setString(map->skin, skin_sel[skin - 1]);
	sfRenderWindow_drawText(map->window->window, map->fps, NULL);
	sfRenderWindow_drawText(map->window->window, map->skin, NULL);
}

int change_fps (window_t *window, int current)
{
	sfEvent event;
	POLL_EVENT(window, event);

	if (event.key.code == sfKeyLeft && event.type == sfEvtKeyReleased) {
		if (current == 1)
			current = 3;
		else
			current -= 1;
		sfRenderWindow_setFramerateLimit(window->window,
						 fps_rate[current - 1]);
	}
	if (event.key.code == sfKeyRight && event.type == sfEvtKeyReleased) {
		if (current == 3)
			current = 1;
		else
			current += 1;
		sfRenderWindow_setFramerateLimit(window->window,
						 fps_rate[current - 1]);
	}
	return (current);
}

void pause_screen (map_t map, player_t player)
{
	static int fps_ch = 2;

	window_t *window = map->window;
	while (WIN_ISOPEN(window)) {
		sfRenderWindow_clear(window->window, sfBlack);
		sfRenderWindow_drawSprite(window->window,
					  map->pause_menu->sprite, NULL);
		fps_ch = change_fps(window, fps_ch);
		change_apperence(player);
		disp_text (map, fps_ch, player->skin);
		if (sfKeyboard_isKeyPressed(sfKeyQ))
			break;
		DISP_WINDOW(window);
	}
}
