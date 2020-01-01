/*
** EPITECH PROJECT, 2018
** music
** File description:
** music
*/

#include "my_cook.h"

music_t* ini_sounds(void)
{
	music_t *sounds = malloc(sizeof(music_t));
	sounds->music = sfMusic_createFromFile("ressources/music/Shokugeki.ogg");
	sfMusic_setLoop(sounds->music, sfTrue);
	sfMusic_play(sounds->music);

	return (sounds);
}
