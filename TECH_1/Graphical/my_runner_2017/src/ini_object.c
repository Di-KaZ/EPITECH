/*
** EPITECH PROJECT, 2018
** 
** File description:
** 
*/

#include "run.h"

const char *path[6] = {
	"Ressources/plateforme1.png",
	"Ressources/lava.png",
	"Ressources/jumper.png",
	"Ressources/plateforme1.png",
	"Ressources/heart.png",
	"Ressources/diamond.png"
};

const sfIntRect rect[6] = {
	{0, 0, 60, 16},
	{0, 0, 60, 16},
	{0, 0, 32, 16},
	{0, 0, 0, 0},
	{0, 0, 17, 16},
	{0,0, 26, 21}
};

const int types[6] = {
	plat1,
	lava,
	jumper,
	phantom,
	heart,
	diamond
};

object_t add_object (const char *path_to_file,
		     sfVector2f pos,
		     sfIntRect rect,
		     int type)
{
	object_t object = malloc(sizeof(*object));

	object->type		= type;
	object->current_pos	= pos;
	object->sprite_rect	= rect;
	object->sprite		= sfSprite_create();
	object->texture		= sfTexture_createFromFile(path_to_file, NULL);
	sfSprite_setTexture(object->sprite, object->texture, sfTrue);
	sfSprite_setTextureRect(object->sprite, rect);
	sfSprite_scale(object->sprite, create_vect(3, 3));
	sfSprite_setPosition(object->sprite, object->current_pos);
	object->next = NULL;
	return (object);
}

void delete_object (object_t object)
{
	sfSprite_destroy(object->sprite);
	sfTexture_destroy(object->texture);
	free(object);
}

object_t add_obj_list (object_t first, int type, sfVector2f pos)
{
	object_t temp = NULL;
	object_t to_add = NULL;

	for (int i = 0; i < 6; i += 1) {
		if (type == types[i]) {
			to_add = add_object(path[i], pos, rect[i], types[i]);
		}
	}
	if(!first)
		return(to_add);
	else
		temp = first;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = to_add;
	return(first);
}

sounds_t ini_sounds (void)
{
	sounds_t sounds = malloc(sizeof(*sounds));

	sounds->damage = sfMusic_createFromFile("Ressources/damage.ogg");
	sounds->jumper = sfMusic_createFromFile("Ressources/jumper.ogg");
	sounds->heart = sfMusic_createFromFile("Ressources/heart.ogg");
	sounds->jump = sfMusic_createFromFile("Ressources/jump.ogg");
	sounds->gem = sfMusic_createFromFile("Ressources/gem.ogg");
	sounds->fkinlow = sfMusic_createFromFile("Ressources/fkinlow.ogg");
	sfMusic_setLoop(sounds->fkinlow, sfTrue);
	sfMusic_setVolume(sounds->fkinlow,0.0);
	sfMusic_play(sounds->fkinlow);
	return (sounds);
}
