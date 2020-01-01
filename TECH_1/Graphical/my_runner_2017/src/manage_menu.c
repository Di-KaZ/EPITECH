/*
** EPITECH PROJECT, 2018
** 
** File description:
** 
*/

#include "run.h"

static menu_t ini_menu2 (menu_t menu, window_t *window)
{
	menu->v_play = create_rect(0, 0, 1280, 63);
	menu->v_exit = create_rect(0, 0, 1280, 63);
	menu->v_make_map = create_rect(0, 0, 1280, 63);
	menu->window = window;
	menu->help = ini_sprite("Ressources/help.png");
	return(menu);
}

menu_t ini_menu (window_t *window)
{
	menu_t menu = malloc(sizeof(*menu));

	menu->bg_base = ini_sprite("Ressources/bg_base.png");
	menu->logo = ini_sprite("Ressources/logo.png");
	menu->play = ini_sprite("Ressources/play.png");
	menu->exit = ini_sprite("Ressources/exit.png");
	menu->make_map = ini_sprite("Ressources/make_map.png");
	menu->music = sfMusic_createFromFile("Ressources/soundtrack.ogg");
	sfMusic_setLoop(menu->music, sfTrue);
	sfMusic_setVolume(menu->music, 70.0);
	sfSprite_scale(menu->logo->sprite, create_vect(2, 2));
	sfSprite_setPosition(menu->logo->sprite, create_vect(450, 250));
	sfSprite_setPosition(menu->play->sprite, create_vect(0, 503));
	sfSprite_setPosition(menu->make_map->sprite, create_vect(0, 581));
	sfSprite_setPosition(menu->exit->sprite, create_vect(0, 658));
	sfSprite_setOrigin(menu->logo->sprite, create_vect(160, 47));
	return (ini_menu2(menu, window));
}

int button_play(window_t *window, menu_t menu)
{
	sfVector2i mouse_pos = sfMouse_getPosition((sfWindow*)(window->window));

	    if (mouse_pos.y >= 503 && mouse_pos.y <= 565) {
		sfSprite_setTextureRect(menu->play->sprite, menu->v_play);
		if (sfMouse_isButtonPressed(sfMouseLeft))
			return (1);
	}
	else
		sfSprite_setTextureRect(menu->play->sprite,
					create_rect(0, 65, 1280, 62));
	return(0);
}

void display_menu (window_t *window, menu_t menu)
{
	sfRenderWindow_drawSprite(window->window, menu->play->sprite, NULL);
	sfRenderWindow_drawSprite(window->window, menu->exit->sprite, NULL);
	sfRenderWindow_drawSprite(window->window, menu->make_map->sprite, NULL);
}
