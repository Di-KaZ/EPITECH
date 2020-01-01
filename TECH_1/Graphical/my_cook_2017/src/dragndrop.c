/*
** EPITECH PROJECT, 2018
** draganddrop
** File description:
** draganddrop
*/

#include "my_cook.h"

static int check_is_in_box (object_t object, sfVector2f mouse_pos)
{
	sfFloatRect rect = sfSprite_getLocalBounds(object->sprite->sprite);

	if (mouse_pos.x < sfSprite_getPosition(object->sprite->sprite).x +
	    rect.width &&
	    mouse_pos.x > sfSprite_getPosition(object->sprite->sprite).x &&
	    mouse_pos.y < sfSprite_getPosition(object->sprite->sprite).y +
	    rect.height &&
	    mouse_pos.y > sfSprite_getPosition(object->sprite->sprite).y &&
	    sfMouse_isButtonPressed(sfMouseLeft))
		return (1);
	return (0);
}

void dragndrop (window_t *window, object_t object, sfVector2f mouse_pos)
{
	static object_t current = NULL;

	if (!(object->type & MOVABLE))
		return;
	if (!current && check_is_in_box(object, mouse_pos))
		current = object;
	if (window->event.type == sfEvtMouseButtonReleased)
		current = NULL;
	if (current)
		sfSprite_setPosition(current->sprite->sprite,
		create_vect((mouse_pos.x -
		sfSprite_getLocalBounds(current->sprite->sprite).width / 2)
		,(mouse_pos .y -
		sfSprite_getLocalBounds(current->sprite->sprite).height / 2)));
}
