/*
** EPITECH PROJECT, 2018
** 
** File description:
** 
*/

#include "run.h"

parallax_t ini_parallax (void)
{
	parallax_t prlx = malloc(sizeof(*prlx));

	prlx->bg = ini_sprite("Ressources/plx-1.png");
	prlx->l1 = ini_layer("Ressources/plx-2.png");
	prlx->l2 = ini_layer("Ressources/plx-3.png");
	prlx->l3 = ini_layer("Ressources/plx-4.png");
	prlx->l4 = ini_layer("Ressources/plx-5.png");
	prlx->l5 = ini_layer("Ressources/ground.png");
	sfSprite_scale(prlx->l5->nb1->sprite, create_vect(8, 5));
	sfSprite_scale(prlx->l5->nb2->sprite, create_vect(8, 5));
	return(prlx);
}

void disp_parallax (window_t *window, parallax_t prlx, clocks_t *clock)
{
	if (get_elapsed_time(clock) > 0.01) {
		CLEAR_WINDOW(window, sfGreen);
		DISP_SPRITE(window, prlx->bg);
		display_layer(window, prlx->l1, create_vect(-2, 0));
		display_layer(window, prlx->l2, create_vect(-3, 0));
		display_layer(window, prlx->l3, create_vect(-4, 0));
		display_layer(window, prlx->l4, create_vect(-5, 0));
		display_layer(window, prlx->l5, create_vect(-5, 0));
	}
}
