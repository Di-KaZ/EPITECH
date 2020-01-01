/*
** EPITECH PROJECT, 2018
** 
** File description:
** 
*/

#include "run.h"

int manage_life (player_t player)
{
	sfSprite_setTextureRect(player->life_sprite, player->life_rect);
	if (get_elapsed_time(player->hitable) < 2.0)
		player->hit = 0;
	if (player->hit == 1 && get_elapsed_time(player->hitable) > 2.0) {
		sfClock_restart(player->hitable->clock);
		player->life_rect.left += 80;
		player->hit = 0;
		player->life -= 1;
	}
	if (player->life == 0)
		defeat(player);
	else if (player->life == 1)
		sfMusic_setVolume(player->sounds->fkinlow, 100);
	else
		sfMusic_setVolume(player->sounds->fkinlow, 0);
	return (0);
}

void destroy_sounds (menu_t menu, sounds_t sounds)
{
	sfMusic_destroy(menu->music);
	sfMusic_destroy(sounds->gem);
	sfMusic_destroy(sounds->jump);
	sfMusic_destroy(sounds->jumper);
	sfMusic_destroy(sounds->damage);
	sfMusic_destroy(sounds->heart);
	sfMusic_destroy(sounds->fkinlow);
}
