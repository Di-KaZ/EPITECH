/*
** EPITECH PROJECT, 2018
** ini_scene
** File description:
** ini scene
*/

#include "my_cook.h"

scene_t add_scene (char **config, int *i, scene_t scenes)
{
	scene_t scene = malloc(sizeof(*scene));

	scene->objs = NULL;
	scene->buttons = NULL;
	for (; config[*i]; *i += 1) {
		if (my_strfind(config[*i], "name"))
			scene->name = config[*i + 1];
		if (my_strfind(config[*i], "obj"))
			scene->objs = add_obj(scene->objs, config[*i + 1]);
		if (my_strfind(config[*i], "button"))
			scene->buttons = add_button(scene->buttons,
						    config[*i + 1]);
		if (my_strfind(config[*i], "end"))
			break;
	}
	scene->next = scenes;
	return (scene);
}

scene_t ini_scene (void)
{
	char **config = ini_map("ressources/game.scene");
	scene_t scenes = NULL;

	if (!config)
		return(NULL);
	for (int i = 0; config[i]; i += 1) {
		if (my_strfind(config[i], "scene"))
			scenes = add_scene(config, &i, scenes);
	}
	return (scenes);
}
