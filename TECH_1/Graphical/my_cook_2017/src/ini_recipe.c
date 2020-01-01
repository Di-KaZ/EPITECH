/*
** EPITECH PROJECT, 2018
** ini recipe
** File description:
** ini recipe
*/

#include "my_cook.h"

recipe_t add_recipe (char **conf, int *i, recipe_t recipe)
{
	for (; conf[*i]; *i += 1) {
		if (my_strfind(conf[*i], "path"))
			recipe.path = get_path(conf[*i + 1]);
		if (my_strfind(conf[*i], "name"))
			recipe.name = conf[*i + 1];
		if (my_strfind(conf[*i], "ingredient")) {
			recipe.composure[0] = conf[*i + 1];
			recipe.composure[2] = conf[*i + 2];
			recipe.composure[3] = conf[*i + 3];
		}
		if (my_strfind(conf[*i], "end"))
			return(recipe);

	}
	return (recipe);
}

recipe_t *ini_recipe (game_t game)
{
	char **conf = ini_map("ressources/game.recipes");
	game->recipe_nb = my_getnbr(conf[0]);
	recipe_t *recipes = malloc(sizeof(recipe_t) * (game->recipe_nb + 1));
	int j = 0;

	recipes[game->recipe_nb].name = NULL;
	for (int i = 0; conf[i]; i += 1) {
		if (my_strfind(conf[i], "recipe")) {
			recipes[j] = add_recipe(conf, &i, recipes[j]);
			j += 1;
		}
	}
	return (recipes);
}
