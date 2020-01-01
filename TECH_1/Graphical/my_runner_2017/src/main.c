/*
** EPITECH PROJECT, 2018
** 
** File description:
** 
*/

#include "run.h"

int main (int ac, char **av)
{
	window_t *window = ini_window("Runner", 1280, 720);
	map_t map = usage_or_map (window, av[1]);
	parallax_t prlx = ini_parallax();
	player_t player = ini_player(window);
	menu_t menut = ini_menu(window);
	object_t list = NULL;

	sfMusic_play(menut->music);
	if (ac != 2 || !map || !(map->map)) {
		destroy_sounds(menut, player->sounds);
		return(0);
	}
	while(WIN_ISOPEN(window)) {
		menu(window, menut);
		game(map, player, prlx, &list);
		DISP_WINDOW(window);
	}
	destroy_sounds(menut, player->sounds);
	return (0);
}


void game (map_t map, player_t player, parallax_t prlx, object_t *list)
{
	while (WIN_ISOPEN(map->window)) {
		if (sfKeyboard_isKeyPressed(sfKeyEscape) == sfTrue)
			pause_screen(map, player);
		disp_parallax(map->window, prlx, player->game_speed);
		disp_obj(*list, map->window, player->game_speed);
		apply_gravity(player, *list);
		manage_player(player);
		*list = ini_obj(map);
		sfRenderWindow_drawSprite(map->window->window,
					  player->sprite, NULL);
		sfRenderWindow_drawSprite(map->window->window,
					  player->life_sprite, NULL);
		if (manage_life(player) == 1)
			sfRenderWindow_close(map->window->window);
		manage_event (map->window);
		sfRenderWindow_display(map->window->window);
	}
}

int manage_event (window_t *window)
{
	sfEvent event;

	while(POLL_EVENT(window, event)) {
		if (event.type == sfEvtClosed) {
			sfRenderWindow_close(window->window);
			return (1);
		}
	}
	return (0);
}

int menu (window_t *window, menu_t menu)
{
	sfVector2f vect = {1.0009, 1.0009};

	while (WIN_ISOPEN(window)) {
		CLEAR_WINDOW (window, sfBlue);
		if (sfSprite_getScale(menu->logo->sprite).x <= 2.5)
			sfSprite_scale(menu->logo->sprite, vect);
		else
			sfSprite_scale(menu->logo->sprite, vect);
		sfRenderWindow_drawSprite(window->window, menu->bg_base->sprite,
									NULL);
		sfRenderWindow_drawSprite(window->window, menu->logo->sprite,
									NULL);
		display_menu(window, menu);
		if (button_play(window, menu) == 1)
			break;
		button_exit(window, menu);
		button_make_map(window, menu);
		manage_event (window);
		DISP_WINDOW (window);
	}
	return (0);
}
