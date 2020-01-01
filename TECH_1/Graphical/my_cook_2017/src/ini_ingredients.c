/*
** EPITECH PROJECT, 2018
** ini_ingredients
** File description:
** ini_ingredients
*/

#include "my_cook.h"

static void set_rect (ingredient_t *ingredient)
{
	sfSprite_setTextureRect(ingredient->sprite->sprite,
			create_rect(0, 0,
			sfSprite_getLocalBounds(
			ingredient->sprite->sprite).width / 3,
			sfSprite_getLocalBounds(
			ingredient->sprite->sprite).height));
}

ingredient_t *add_ingredient (char **config, int *i, ingredient_t *ingredients)
{
	ingredient_t *ingredient = malloc(sizeof(ingredient_t));
	ingredient->next = ingredients;

	for (; config[*i]; *i += 1) {
		if (my_strfind(config[*i], "name"))
			ingredient->name = config[*i + 1];
		if (my_strfind(config[*i], "type"))
			ingredient->flag = get_flag(config[*i + 1]);
		if (my_strfind(config[*i], "path")) {
			ingredient->path = get_path(config[*i + 1]);
			ingredient->sprite = ini_sprite(ingredient->path);
			ingredient->flag & RAW ? set_rect(ingredient) : 0;
		}
		if (my_strfind(config[*i], "end"))
			return (ingredient);
	}
	return (ingredient);
}

ingredient_t *ini_ingredients (void)
{
	char **conf = ini_map("ressources/game.ingredients");
	ingredient_t *ingredients = NULL;

	for (int i = 0; conf[i]; i += 1) {
		if (my_strfind(conf[i], "ingredient")) {
			ingredients = add_ingredient(conf, &i, ingredients);
		}
	}
	return (ingredients);
}
