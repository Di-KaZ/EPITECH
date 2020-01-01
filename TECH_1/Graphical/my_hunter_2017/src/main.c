/*
** EPITECH PROJECT, 2017
** 
** File description:
** 
*/

#include "my_hunter.h"

int main (int ac, char **av)
{
	load_sounds_t *sounds = ini_sounds();
	if (ac == 2 && av[1][0] == '-' && av[1][1] == 'h') {
		usage();
		free_sounds(&sounds);
		return (0);
	}
	sfMusic_play(sounds->soundtrack);
	if (titlescreen() == 1) {
		free_sounds(&sounds);
		return (0);
	}
	game_loop(sounds);
	free_sounds(&sounds);
	return(0);
}

void game_loop (load_sounds_t *sounds)
{
	window_t *window = ini_window("My Hunter", 1280, 720);
	sprite_t *background = ini_sprite("Ressources/background.png");
	dog_ia_t *dog = ini_dog();
	duck_ia_t *duck = ini_duck();
	clock__t *clock = ini_clock();

	SET_FRAMERATE(window, 60);
	while (WIN_ISOPEN(window)) {
		if (sfMouse_isButtonPressed(sfMouseLeft))
			sfMusic_play(sounds->shoot);
		manage_texture(window, clock, background, dog, duck);
		manage_event(&window);
		DISP_WINDOW(window);
	}
	destroy_sprite(&background);
	destroy_dog(&dog);
	destroy_window(&window);
}

void manage_texture(window_t *window, clock__t *clock,
		 sprite_t *background, dog_ia_t *dog, duck_ia_t *duck)
{
	dog_ia(clock, dog);
	duck_hitbox(window, duck);
	spawn_duck(duck, GET_DOG_POS(dog).x + 20, GET_DOG_POS(dog).y - 45);
	window_clear(window, sfBlack);
	disp_sprite(window, background);
	disp_sprite(window, dog->sprite);
	disp_sprite(window, duck->sprite);
}

void manage_event (window_t **window)
{
	sfEvent event;

	while (POLL_EVENT((*window), event)) {
		if (event.type == sfEvtClosed)
			sfRenderWindow_close((*window)->window);
	}
}
