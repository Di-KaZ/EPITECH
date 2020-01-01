/*
** EPITECH PROJECT, 2017
** 
** File description:
** 
*/

#include "my_hunter.h"

static int _offset_f = 130;
static int _offset_d = 280;

void flying_duck(duck_ia_t *duck)
{
	disp_sprite_rect(duck->sprite, _offset_f, 170, 40, 40);
	if (_offset_f == 250) {
		_offset_f = 130;
		return;
	}
	if (get_elapsed_time(duck->clock) > 0.1) {
		_offset_f += 40;
		sfClock_restart(duck->clock->clock);
	}
}

void dead_duck(duck_ia_t *duck)
{
	disp_sprite_rect(duck->sprite, _offset_d, 220, 30, 40);
	if (_offset_d == 340) {
		_offset_d = 280;
		return;
	}
	if (get_elapsed_time(duck->clock) > 0.1) {
		_offset_d += 30;
		sfClock_restart(duck->clock->clock);
	}
}
