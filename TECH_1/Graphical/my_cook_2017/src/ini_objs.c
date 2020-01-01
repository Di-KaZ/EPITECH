/*
** EPITECH PROJECT, 2018
** ini objs
** File description:
** ini objs
*/

#include "my_cook.h"

object_t add_obj (object_t objs, char *conf)
{
	object_t obj = malloc(sizeof(*obj));
	int i = 0;

	obj->sprite = ini_sprite(get_path(conf));
	sfSprite_setPosition(obj->sprite->sprite,
				create_vect(get_coord(conf, &i),
					    get_coord(conf, &i)));
	obj->type = get_flag(conf + i);
	obj->next = objs;
	obj->offset = sfSprite_getLocalBounds(obj->sprite->sprite).width / 3;
	obj->name = NULL;
	food_status(obj);
	return (obj);
}

const char *flags[8] =
{
	"raw",
	"animated",
	"stove",
	"plate",
	"background",
	"movable",
	"BACKGROUND",
	NULL
};

const unsigned int char_flag[7] =
{
	RAW,
	ANIMATED,
	STOVE,
	PLATE,
	BACKGROUND,
	MOVABLE,
	RBACKGROUND
};

unsigned int get_flag (char *conf)
{
	unsigned int flags_to = 0;

	for (int i = 0; flags[i]; i += 1)
		if (my_strfind(conf, flags[i])) {
			flags_to |= char_flag[i];
		}
	return (flags_to);
}

int aleready_exist (object_t objs, char *name)
{
	while (objs) {
		if (my_strfind(objs->name, name))
			return (1);
		objs = objs->next;
	}
	return (0);
}
