/*
** EPITECH PROJECT, 2018
** 
** File description:
** 
*/

#include "run.h"

void change_apperence(player_t player)
{
	sfEvent event;
	window_t *window = player->window;

	POLL_EVENT(window, event);
	if (event.key.code == sfKeyA && event.type == sfEvtKeyReleased) {
		if (player->skin == 1)
			player->skin = 3;
		else
			player->skin -= 1;
	}
	if (event.key.code == sfKeyZ &&  event.type == sfEvtKeyReleased) {
		if (player->skin == 3)
			player->skin = 1;
		else
			player->skin += 1;
	}
	sfSprite_setTexture(player->sprite, player->texture[player->skin - 1],
									sfTrue);
}

object_t last_obj (object_t list)
{
	while (list && list->next != NULL)
		list = list->next;
	return (list);
}
