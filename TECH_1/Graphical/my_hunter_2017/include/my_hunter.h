/*
** EPITECH PROJECT, 2017
** 
** File description:
** 
*/

#include "my_csfml.h"
#include "my.h"

/* define */
#define WALKING(x) (x >= 0 && x <= 5)
#define JUMPING(x) (x >= 6 && x <= 9)
#define GET_DOG_POS(dog) (sfSprite_getPosition(dog->sprite->sprite))
#define SPR_POS(spr) (sfSprite_getPostition(spr->sprite->srpite))
#define MOUSE_POS(win) (sfMouse_getPosition(((sfWindow*)(win->window)
/* Structures */
typedef struct dog_ia_s {
	sprite_t *sprite;
	clock__t *clock;
	int status;
} dog_ia_t;

typedef struct duck_ia_s {
	sprite_t *sprite;
	clock__t *clock;
	clock__t *reset_spawn;
	int status;
} duck_ia_t;

typedef struct title_s {
	sprite_t *title;
	sprite_t *title_play;
	sprite_t *title_quit;
} title_t;

typedef struct load_sounds_s {
	sfMusic *soundtrack;
	sfMusic *shoot;
}load_sounds_t;

/* Prototypes */

void game_loop(load_sounds_t *sounds);
void manage_event (window_t **window);
load_sounds_t *ini_sounds (void);
void free_sounds (load_sounds_t **sounds);
void manage_texture (window_t *window,clock__t *clock,
		 sprite_t *background, dog_ia_t *dog, duck_ia_t *duck);
void spawn_duck (duck_ia_t *duck, int x, int y);
void dog_ia (clock__t *clock, dog_ia_t *dog);
void walking_dog (clock__t *clock, sprite_t *sprite);
dog_ia_t *ini_dog (void);
void destroy_dog (dog_ia_t **dog);
void jumping_dog(sprite_t *dog);
duck_ia_t *ini_duck (void);
void destroy_duck (duck_ia_t **duck);
void flying_duck (duck_ia_t *duck);
int titlescreen (void);
int manage_f_quit (window_t **window);
int manage_play (window_t **window, sprite_t *title_play);
int manage_quit (window_t **window, sprite_t *title_quit);
title_t *ini_title (void);
void free_title (title_t **title);
void usage (void);
void duck_hitbox(window_t *window, duck_ia_t *duck);
void dead_duck(duck_ia_t *duck);
