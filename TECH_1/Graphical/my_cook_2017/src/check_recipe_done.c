#include "my_cook.h"

int is_ing_ready (recipes_t *recipes, object_t food, object_t plate)
{
	int return_val = 0;
	for (int i = 0; recipes->composure[i]; i += 1) {
		if (!(food->type & BURNED) && !(food->type & RAW))
			if (my_strfind(recipes->composure[i], food->name)) ||
				my_strfind(recipes->composure[i], "NULL")
				return_val += 1;
	}
	return (return_val);
}

void is_recipe_done (recipe_t *recipes, object_t play_obj, object_t plate)
{
	object_t temp_obj = play_obj;
	int finished = 0;

	while (recipes) {
		while (temp_obj) {
			finished = is_ing_ready(recipes, temp_obj, plate);
			temp_obj = temp_obj->next;
		}
		if (finished == 3)
			play_obj = add_finished_recipe(recipes->name);
		else {
			finished = 0;
			temp_obj = play_obj;
		}
		recipes++;
	}
}
