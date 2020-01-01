/*
** EPITECH PROJECT, 2018
** disp_scene
** File description:
** disp_scene
*/

#include "my_cook.h"

scene_t find_scene (scene_t scenes, char *name)
{
	while (scenes) {
		if (my_strfind(scenes->name , name))
			return (scenes);
		scenes = scenes->next;
	}
	return (NULL);
}

static void disp_obj (window_t *window, object_t temp_objs)
{
	while (temp_objs) {
		if (!(temp_objs->type & RBACKGROUND)) {
			sfRenderWindow_drawSprite(window->window,
					temp_objs->sprite->sprite, NULL);
		}
		dragndrop(window, temp_objs, get_mouse_pos(window));
		temp_objs = temp_objs->next;
	}
}

static void disp_button (window_t *window, button_t temp_buttons, game_t game)
{
	while (temp_buttons) {
		sfRenderWindow_drawSprite(window->window,
					  temp_buttons->sprite->sprite, NULL);
		if (buttonIsClicked(temp_buttons, get_mouse_pos(window)) &&
		    window->event.type == sfEvtMouseButtonReleased)
			temp_buttons->callback(game);
		temp_buttons = temp_buttons->next;
	}
}


void disp_scene(window_t *window, scene_t scenes, char *name, game_t game)
{
	scene_t to_disp = find_scene(scenes, name);
	object_t temp_objs = to_disp->objs;
	button_t temp_buttons = to_disp->buttons;
	disp_obj(window, temp_objs);
	if (get_elapsed_time(game->animation) > 0.5) {
		animate (temp_objs);
		sfClock_restart(game->animation->clock);
	}
	disp_button(window, temp_buttons, game);
}
