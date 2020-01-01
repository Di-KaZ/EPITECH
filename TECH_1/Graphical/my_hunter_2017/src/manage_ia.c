/*
** EPITECH PROJECT, 2017
** 
** File description:
** 
*/

#include "my_hunter.h"

static int _duck_status = 0;
static int _side = 1;

void dog_ia (clock__t *clock, dog_ia_t *dog)
{
	if (get_elapsed_time(dog->clock) > 1.0) {
		dog->status = rand() % 10;
		sfClock_restart(dog->clock->clock);
	}
	walking_dog(clock, dog->sprite);
}

void spawn_duck (duck_ia_t *duck, int x, int y)
{
	set_sprite_scale(duck->sprite, 2 * _side, 2);
	if (_duck_status == 0) {
		set_sprite_pos(duck->sprite, x, y);
		_duck_status = 1;
		if (sfSprite_getPosition(duck->sprite->sprite).x >= 640) {
			_side = -1;
		}
		else
			_side = 1;
	}
	if (_duck_status == 2) {
		dead_duck(duck);
		move_sprite(duck->sprite, 0, 4);
	}
	else {
		flying_duck(duck);
		move_sprite(duck->sprite, 3 * _side, -2);
	}
}

void duck_hitbox(window_t *window, duck_ia_t *duck)
{
	if (sfSprite_getPosition(duck->sprite->sprite).x > window->width ||
	    sfSprite_getPosition(duck->sprite->sprite).y < 0 ||
	    sfSprite_getPosition(duck->sprite->sprite).y > window->height ||
	    sfSprite_getPosition(duck->sprite->sprite).y < 0)
		_duck_status = 0;
	if (sfMouse_getPosition((sfWindow*)window->window).x >=
	    sfSprite_getPosition(duck->sprite->sprite).x - 50 &&
	    sfMouse_getPosition((sfWindow*)window->window).x <=
	    sfSprite_getPosition(duck->sprite->sprite).x + 50 &&
	    sfMouse_getPosition((sfWindow*)window->window).y >=
	    sfSprite_getPosition(duck->sprite->sprite).y - 50 &&
	    sfMouse_getPosition((sfWindow*)window->window).y <=
	    sfSprite_getPosition(duck->sprite->sprite).y + 50 &&
	    sfMouse_isButtonPressed(sfMouseLeft))
		    _duck_status = 2;
}
