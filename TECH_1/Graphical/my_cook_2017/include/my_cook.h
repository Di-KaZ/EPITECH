/*
** EPITECH PROJECT, 2018
** my_cook.h
** File description:
** my_cook.h
*/

#include "my_csfml.h"
#include <stdio.h>
#include "my_lib_c.h"
#ifndef _MY_COOK_
#define _MY_COOK_
//flags
#define RAW (1)
#define COOKED (2)
#define BURNED (4)
#define ANIMATED (8)
#define STOVE (16)
#define PLATE (32)
#define BACKGROUND (64)
#define RBACKGROUND (128)
#define MOVABLE (256)
#define FOOD (512)

typedef struct recipe_s {
	int is_ready;
	int gain;
	char *name;
	char *path;
	char *composure[3];
} recipe_t;

typedef struct client_s {
	clocks_t *time_before_bored;
	float elapsed_time;
	sprite_t sprite;
	char *recipe;
} client_t;

typedef struct music_s {
	sfMusic *music;
	sfMusic *cooking;
} music_t;

typedef struct ingredient_s {
	char *name;
	char *path;
	unsigned int flag;
	sprite_t sprite;
	struct ingredients_s *prev;
	struct ingredient_s *next;
	sfText *text;
} ingredient_t;

typedef struct game_s {
	window_t *window;
	scene_t scenes;
	clocks_t *animation;
	sprite_t client_spr[5];
	client_t *client;
	int recipe_nb;
	recipe_t *recipe_arr;
	music_t *sounds;
	ingredient_t *ingredients;
	int ing_pos;
} *game_t;

scene_t ini_scene(void);
void print_hello(void *);
object_t add_obj(object_t objs, char*);
void disp_scene(window_t*, scene_t, char*, game_t game);
void close_window(void *);
char **ini_map (char *path);
void play (void *);
void quit (void *);
void options (void *);
void help (void *);
void dragndrop(window_t *window, object_t, sfVector2f);
void food_status (object_t food);
void animate (object_t to_anim);
void menu (void *data);
scene_t find_scene (scene_t scenes, char *);
client_t *add_client (game_t);
object_t find_object (object_t, unsigned int);
void manage_client (client_t *client);
void manage_food (object_t foods, object_t stove);
music_t *ini_sounds(void);
recipe_t *ini_recipe (game_t game);
ingredient_t *ini_ingredients (void);
object_t add_ingredient_list (ingredient_t*, object_t, char*);
void pause_menu (void *data);
void not_implemented (void *);
unsigned int get_flag (char *conf);
void disp_ingredients_menu(game_t);
int aleready_exist (object_t, char *);
#endif
