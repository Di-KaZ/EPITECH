/*
** EPITECH PROJECT, 2018
** 
** File description:
** 
*/

#include "run.h"

map_t ini_map_t (window_t *window, char * path)
{
	map_t map = malloc(sizeof(*map));
	map->map = ini_map (path);
	map->gen_time = ini_clock();
	map->pause_menu = ini_sprite("Ressources/pause_menu.png");
	map->window = window;
	map->fps = sfText_create();
	map->skin = sfText_create();
	map->font = sfFont_createFromFile("Ressources/font.ttf");
	sfText_setPosition(map->skin, create_vect(150, 150));
	sfText_setColor(map->skin, sfWhite);
	sfText_setFont(map->skin, map->font);
	sfText_setPosition(map->fps, create_vect(1100, 150));
	sfText_setColor(map->fps, sfWhite);
	sfText_setFont(map->fps,map->font);
	return(map);
}
