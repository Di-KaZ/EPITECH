/*
** EPITECH PROJECT, 2018
** 
** File description:
** 
*/

#include "run.h"


static player_t ini_player2 (player_t player, window_t *window)
{
	player->hitable = ini_clock();
	player->life = 3;
	player->sounds = ini_sounds();
	player->skin = 1;
	player->window = window;
	player->game_speed = ini_clock();
	player->dead = ini_sprite("Ressources/dead.png");
	player->victory = ini_sprite("Ressources/win.png");
	player->texture[0] =
		sfTexture_createFromFile("Ressources/player_n.png", NULL);
	player->texture[1] =
		sfTexture_createFromFile("Ressources/player_nb.png", NULL);
	player->texture[2] =
		sfTexture_createFromFile("Ressources/player_p.png", NULL);
	sfSprite_setTexture(player->sprite, player->texture[0], sfTrue);
	return (player);
}

player_t ini_player (window_t *window)
{
	player_t player = malloc(sizeof(*player));

	player->sprite = sfSprite_create();
	player->life_sprite = sfSprite_create();
	player->life_text = sfTexture_createFromFile("Ressources/life.png", NULL);
	sfSprite_setTexture(player->life_sprite, player->life_text, sfTrue);
	player->animation = ini_clock();
	player->rect = create_rect(0, 0, 30, 40);
	player->life_rect = create_rect(0, 0, 80, 60);
	sfSprite_setPosition(player->sprite, create_vect(1280 / 2.3, 250));
	sfSprite_setPosition(player->life_sprite, create_vect(0 , 580));
	sfSprite_scale(player->sprite, create_vect(4, 4));
	sfSprite_scale(player->life_sprite, create_vect(2, 2));
	player->velo = create_vect(0, 0);
	player->on_ground = 0;
	sfSprite_setOrigin(player->sprite, create_vect(15, 30));
	return (ini_player2(player,window));
}

void manage_player (player_t player)
{
	sfSprite_setTextureRect(player->sprite, player->rect);
	if (player->on_ground == 1)
		walking(player);
	if (player->velo.y < 0 && player->on_ground == 0)
		player->rect = create_rect(240, 0, 30, 40);
	if (player->on_ground == 0 && player->velo.y > 0)
		player->rect = create_rect(270, 0, 30, 40);
	if ((sfKeyboard_isKeyPressed(sfKeyUp) ||
	     sfKeyboard_isKeyPressed(sfKeySpace))&& player->on_ground == 1 &&
	    player->velo.y > 0) {
		sfMusic_play(player->sounds->jump);
		player->velo = create_vect(0, -20);
		sfSprite_move(player->sprite, player->velo);
	}
}

void walking (player_t player)
{
	if (get_elapsed_time(player->animation) > 0.1) {
		sfClock_restart(player->animation->clock);
		player->rect.left += 30;
	}
	if (player->rect.left >= 240)
		player->rect.left = 0;
}
