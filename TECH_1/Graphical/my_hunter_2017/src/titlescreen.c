/*
** EPITECH PROJECT, 2017
** 
** File description:
** 
*/

#include "my_hunter.h"

int titlescreen (void)
{
	window_t *window = ini_window("My_Hunter : Titlescreen", 1280, 720);
	title_t *title = ini_title();
	int re = 0;

	SET_FRAMERATE(window, 60);
	while (WIN_ISOPEN(window)) {
		window_clear(window, sfBlack);
		disp_sprite(window, title->title);
		if (manage_quit(&window, title->title_quit) == 1) {
			re = 1;
			sfRenderWindow_close(window->window);
		}
		if (manage_play(&window, title->title_play) == 1)
			sfRenderWindow_close(window->window);
		if (manage_f_quit(&window) == 1)
			re = 1;
		DISP_WINDOW(window);
	}
	free_title(&title);
	return (re);
}

int manage_f_quit (window_t **window)
{
	sfEvent event;
	while (POLL_EVENT((*window), event)) {
		if (event.type == sfEvtClosed) {
			sfRenderWindow_close((*window)->window);
			return (1);
		}
	}
	return (0);
}

int manage_play (window_t **window, sprite_t *title_play)
{
		if(sfMouse_getPosition((sfWindow*)(*window)->window).x >= 140 &&
		   sfMouse_getPosition((sfWindow*)(*window)->window).x <= 350 &&
		   sfMouse_getPosition((sfWindow*)(*window)->window).y >= 450 &&
		   sfMouse_getPosition((sfWindow*)(*window)->window).y <= 490) {
			disp_sprite(*window, title_play);
			if (sfMouse_isButtonPressed(sfMouseLeft))
				return (1);
		}
	return(0);
}

int manage_quit (window_t **window, sprite_t *title_quit)
{
		if(sfMouse_getPosition((sfWindow*)(*window)->window).x >= 140 &&
		   sfMouse_getPosition((sfWindow*)(*window)->window).x <= 350 &&
		   sfMouse_getPosition((sfWindow*)(*window)->window).y >= 575 &&
		   sfMouse_getPosition((sfWindow*)(*window)->window).y <= 615) {
			disp_sprite(*window, title_quit);
			if (sfMouse_isButtonPressed(sfMouseLeft))
				return (1);
	}
	return (0);
}
