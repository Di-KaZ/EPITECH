/*
** EPITECH PROJECT, 2018
** manage cook
** File description:
** manage cook
*/

#include "my_cook.h"

void is_food_cooked (object_t food, object_t stove)
{
	if ((food->type & RAW) != 0 &&
	    simple_collision(food->sprite->sprite, stove->sprite->sprite)) {
		food->type &= ~RAW;
		food->type |= COOKED;
		sfSprite_setTextureRect(food->sprite->sprite,
		create_rect(food->offset, 0,
		    (sfSprite_getLocalBounds(food->sprite->sprite).width),
			    (sfSprite_getLocalBounds(
				food->sprite->sprite).height)));

	}
}

void manage_food (object_t foods, object_t stove)
{
	while (foods) {
		is_food_cooked(foods, stove);
		foods = foods->next;
	}
}

void food_status (object_t food)
{
	if ((food->type & RAW) != 0) {
		sfSprite_setTextureRect(food->sprite->sprite,
		create_rect(0, 0,
		(sfSprite_getLocalBounds(food->sprite->sprite).width / 3),
		(sfSprite_getLocalBounds(food->sprite->sprite).height)));
	}
}

void animate (object_t to_anim)
{
	static int frame = 0;

	if (frame == 3)
		frame = 0;
	while (to_anim) {
		if ((to_anim->type & ANIMATED)) {
			sfSprite_setTextureRect(to_anim->sprite->sprite,
			create_rect((to_anim->offset * frame), 0,
				    to_anim->offset, (sfSprite_getLocalBounds(
					to_anim->sprite->sprite).height)));
		}
		to_anim = to_anim->next;
	}
		frame += 1;
}
