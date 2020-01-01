/*
** EPITECH PROJECT, 2018
** 
** File description:
** 
*/

#include "my_csfml.h"
#include <stdio.h>

#ifndef _RUN_
#define _RUN_
enum types {
	plat1 = 1,
	lava = 2,
	jumper = 3,
	phantom = 4,
	heart = 5,
	diamond = 6
};


typedef struct object_s {
	sfVector2f current_pos;
	sfIntRect sprite_rect;
	sfSprite *sprite;
	sfTexture *texture;
	struct object_s *next;
	int type;
} *object_t;

typedef struct sounds_s {
	sfMusic *damage;
	sfMusic *jumper;
	sfMusic *heart;
	sfMusic *jump;
	sfMusic *gem;
	sfMusic *fkinlow;
} *sounds_t;

typedef struct player_s {
	window_t *window;
	sfSprite *sprite;
	sfTexture *texture[3];
	sfTexture *life_text;
	sfSprite *life_sprite;
	sprite_t dead;
	sprite_t victory;
	clocks_t *animation;
	clocks_t *hitable;
	clocks_t *game_speed;
	sfIntRect rect;
	sfIntRect life_rect;
	sfVector2f velo;
	int on_ground;
	int hit;
	int life;
	int skin;
	sounds_t sounds;

} *player_t;

typedef struct layer_s {
	sprite_t nb1;
	sprite_t nb2;
	sprite_t temp;
} *layer_t;

typedef struct parallax_s {
	sprite_t bg;
	layer_t l1;
	layer_t l2;
	layer_t l3;
	layer_t l4;
	layer_t l5;
} *parallax_t;

typedef struct map_s {
	char **map;
	clocks_t *gen_time;
	window_t *window;
	sprite_t pause_menu;
	sfFont *font;
	sfText *fps;
	sfText *skin;
} *map_t;

typedef struct menu_s {
	sprite_t bg_base;
	sprite_t logo;
	sprite_t play;
	sprite_t help;
	sfIntRect v_play;
	sprite_t exit;
	sfIntRect v_exit;
	sprite_t make_map;
	sfIntRect v_make_map;
	sfMusic *music;
	sfMusic *select;
	window_t *window;
} *menu_t;

object_t add_object(const char*, sfVector2f, sfIntRect, int types);
void delete_object(object_t object);
void game(map_t map, player_t player, parallax_t prlx, object_t *list);
parallax_t ini_parallax(void);
void disp_parallax (window_t*, parallax_t, clocks_t *clock);
int manage_event (window_t *window);
void delete_parallax (parallax_t);
void move_parallax (parallax_t);
layer_t ini_layer (char *path);
void display_layer (window_t *, layer_t layer, sfVector2f);
char ** ini_map (char * file_path);
int count_n_line(FILE *file);
void apply_gravity (player_t player, object_t list);
player_t ini_player(window_t *window);
void manage_player (player_t player);
void jump(player_t player);
void walking (player_t player);
object_t add_obj_list (object_t first, int type, sfVector2f pos);
void disp_obj (object_t first, window_t *window, clocks_t *clock);
object_t ini_obj(map_t map);
int manage_life (player_t player);
map_t ini_map_t (window_t *window, char *path);
menu_t ini_menu (window_t *window);
int menu (window_t *window, menu_t menu);
int button_play (window_t *window, menu_t menu);
int button_exit (window_t *window, menu_t menu);
int button_make_map(window_t *window, menu_t menu);
sounds_t ini_sounds (void);
void display_menu(window_t *window, menu_t menu);
void hit_diamond(player_t player, object_t object);
void hit_lava(player_t player, object_t object);
void hit_heart(player_t player, object_t object);
void hit_jumper(player_t player, object_t object);
void destroy_sounds (menu_t menu, sounds_t sounds);
int defeat(player_t);
void victory (player_t player);
void help (menu_t menu);
void pause_screen (map_t map, player_t player);
void change_apperence(player_t player);
object_t last_obj (object_t object);
object_t free_unused (object_t object);
map_t usage_or_map (window_t *window,const char *str);
int my_strlen (const char*str);
int my_putchar (int c);
int my_putstr(const char *str);
#endif
