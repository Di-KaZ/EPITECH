/*
** EPITECH PROJECT, 2017
** 
** File description:
** 
*/

#include "my_hunter.h"

static int _offset_walking = 0;
static int _speed  = 5;

void walking_dog (clock__t *clock, sprite_t *dog)
{
	if (sfSprite_getPosition(dog->sprite).x < -100 || _speed == 5) {
		set_sprite_scale (dog, 3, 3);
		 _speed = 5;
	}
	if (sfSprite_getPosition(dog->sprite).x > 1400 || _speed == -5) {
		_speed = -5;
		set_sprite_scale (dog, -3, 3);
	}
	move_sprite (dog, _speed, 0);
	disp_sprite_rect(dog, _offset_walking , 20, 50, 50);
	if (_offset_walking == 200)
		_offset_walking = 0;
	if (get_elapsed_time(clock) > 0.1) {
		_offset_walking += 50;
		sfClock_restart(clock->clock);
	}
}

void jumping_dog(sprite_t *dog)
{
	if (_speed == 5)
		set_sprite_scale(dog, 3, 3);
	if (_speed == -5)
		set_sprite_scale(dog, -3, 3);
	disp_sprite_rect(dog, 210, 70, 60, 50);
}
