/*
** EPITECH PROJECT, 2018
** main
** File description:
** main
*/

#include "my_cook.h"

game_t ini_game (char **env)
{
	game_t data = malloc(sizeof(*data));

	if (!env[0])
		return (NULL);
	data->window = ini_window("My_Cook", 1920, 1080);
	data->scenes = ini_scene();
	data->animation = ini_clock();
	data->client_spr[0] = ini_sprite("ressources/clients/Erina.png");
	data->client_spr[1] = ini_sprite("ressources/clients/Ikumi.png");
	data->client_spr[2] = ini_sprite("ressources/clients/Megumi.png");
	data->client_spr[3] = ini_sprite("ressources/clients/Nakiri.png");
	data->client_spr[4] = ini_sprite("ressources/clients/Shinomiya.png");
	data->recipe_arr = ini_recipe(data);
	data->client = add_client(data);
	data->sounds = ini_sounds();
	data->ingredients = ini_ingredients();
	data->ing_pos = 0;
	return (data);
}

int main (int ac, char **av, char**env)
{
	game_t data = ini_game(env);
	(void)ac;
	(void)av;

	if (!data)
		return (84);
	while (sfRenderWindow_isOpen(data->window->window)) {
		while (sfRenderWindow_pollEvent(data->window->window,
					&data->window->event)) {
			if (data->window->event.type == sfEvtClosed)
				sfRenderWindow_close(data->window->window);
		}
		menu(data);
	}
	sfMusic_destroy(data->sounds->music);
	return (0);
}
