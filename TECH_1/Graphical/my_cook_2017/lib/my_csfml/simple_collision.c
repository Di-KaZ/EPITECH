/*
** EPITECH PROJECT, 2018
** collision
** File description:
** collision
*/

#include "my_csfml.h"

int simple_collision (sfSprite *n1, sfSprite *n2)
{
	sfFloatRect rect_n1 = sfSprite_getGlobalBounds(n1);
	sfFloatRect rect_n2 = sfSprite_getGlobalBounds(n2);

	return (sfFloatRect_intersects((const sfFloatRect*)&rect_n1,
				       (const sfFloatRect*)&rect_n2,
				       NULL));
}
