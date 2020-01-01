/*
** EPITECH PROJECT, 2018
** check_is_recipe
** File description:
** check_is_recipe
*/

#include "my_cook.h"

recipe_t is_recipe (recipe_t *recipes, object_t objects)
{
	int ing_count = 0;
	temp_obj = objects;
	object_t plate = find_object(objects, "plate");

	while (!my_strcmp(recipes->name, "NULL")) {
		while (temp_obj) {
			if (my_strcmp(recipes->composure , "NULL") ||
			    my_strcmp(recipes->composure, temp_obj->type))
				ing_count += 1;
			if (ing_count == 3)
				return (recipes);
			temp_obj = temp_obj->next;
		}
		ing_count = 0;
		recipes = recipes->next;
	}
	return (NULL);
}
