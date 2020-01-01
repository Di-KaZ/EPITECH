/*
** EPITECH PROJECT, 2018
** client.c
** File description:
** client.c
*/

#include "my_cook.h"

void manage_client (client_t *client)
{
	if (sfSprite_getPosition(client->sprite->sprite).x <= 800)
		sfSprite_move(client->sprite->sprite, create_vect(10, 0));
}

object_t find_object (object_t objects, unsigned int to_find)
{
	while (objects) {
		if ((objects->type  & to_find) != 0)
			return (objects);
		objects = objects->next;
	}
	return (NULL);
}

client_t *add_client (game_t game)
{
	client_t *client = malloc(sizeof(client_t));
	srand(my_random());
	client->sprite = game->client_spr[rand() % 5];
	client->elapsed_time = 0;
	client->time_before_bored = ini_clock();
	client->recipe = game->recipe_arr[rand() % game->recipe_nb].name;
	sfSprite_setPosition(client->sprite->sprite, create_vect(0, 100));
	return (client);
}
