/*
** EPITECH PROJECT, 2017
** 
** File description:
** 
*/

#include "my_hunter.h"

dog_ia_t *ini_dog (void)
{
	dog_ia_t *dog = malloc(sizeof(*dog));

	dog->sprite = ini_sprite("Ressources/misc.png");
	dog->clock = ini_clock();
	set_sprite_pos(dog->sprite, 0, 435);
	dog->status = 1;
	return(dog);
}

void destroy_dog (dog_ia_t **dog)
{
	destroy_sprite(&(*dog)->sprite);
	free(*dog);
}

duck_ia_t *ini_duck (void)
{
	duck_ia_t *duck = malloc(sizeof(*duck));
	duck->sprite = ini_sprite("Ressources/misc.png");
	duck->clock = ini_clock();
	duck->reset_spawn = ini_clock();
	disp_sprite_rect(duck->sprite, 0, 0, 0, 0);
	duck->status = 0;
	return(duck);
}

void destroy_duck (duck_ia_t **duck)
{
	destroy_sprite(&(*duck)->sprite);
	free(*duck);
}
