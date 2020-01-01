/*
** EPITECH PROJECT, 2017
** 
** File description:
** 
*/

#include "my_hunter.h"

load_sounds_t *ini_sounds (void)
{
	load_sounds_t *sounds = malloc(sizeof(*sounds));
	sounds->soundtrack = sfMusic_createFromFile("Ressources/soundtrack.ogg");
	sounds->shoot = sfMusic_createFromFile("Ressources/HEADSHOT.ogg");
	sfMusic_setVolume(sounds->soundtrack, 5.5);
	sfMusic_setVolume(sounds->shoot, 5.5);
	sfMusic_setLoop(sounds->soundtrack, sfTrue);
	return (sounds);
}

void free_sounds(load_sounds_t **sounds)
{
	sfMusic_destroy((*sounds)->shoot);
	sfMusic_destroy((*sounds)->soundtrack);
	free(*sounds);
}
