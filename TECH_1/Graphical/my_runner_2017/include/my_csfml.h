/*
** EPITECH PROJECT, 2017
** 
** File description:
** 
*/

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Window.h>
#include <stdlib.h>
#ifndef _MY_CSFML_
#define _MY_CSFML_
/* Define linker for csfml function */

#define DISP_WINDOW(window) (sfRenderWindow_display(window->window))
#define POLL_EVENT(win, evt) (sfRenderWindow_pollEvent(win->window, &evt))
#define SET_FRAMERATE(win, f) (sfRenderWindow_setFramerateLimit(win->window, f))
#define WIN_ISOPEN(win) (sfRenderWindow_isOpen(win->window))
#define CLEAR_WINDOW(win, col) (sfRenderWindow_clear(win->window , col))
#define DISP_SPRITE(win, obj) (sfRenderWindow_drawSprite(win->window, obj->sprite, NULL))
#define SET_SPRITE_SCALE(spr, nb) (sfSprite_setScale(spr->sprite, nb, nb))
#define DISP_SPRITE_RECT(spr, rect) (sfSprite_setTextureRect(spr->sprite, rect))
#define SET_SPRITE_POS(spr, x, y) (sfSprite_setPosition(spr->sprite, x, y))
#define SPRITE_SCALE(spr, nb) (sfSprite_scale(spr->sprite, nb))
#define DESTROY_SPRITE(spr) (sfSprite_destroy(spr->sprite))

/* Structure */

typedef struct sprite_s {
	sfSprite *sprite;
	sfTexture *texture;
} *sprite_t;

typedef struct window_s {
	int height;
	int width;
	sfRenderWindow *window;
} window_t;

typedef struct clocks_s {
	sfClock *clock;
	sfTime time;
} clocks_t;

/* Prototypes */

window_t *ini_window (char* name, int width, int height);
void destroy_window (window_t **window);
sprite_t ini_sprite (char *path_to_text);
void destroy_sprite (sprite_t sprite);
void disp_sprite (window_t *window, sprite_t *sprite);
void window_clear (window_t *window, sfColor color);
clocks_t * ini_clock (void);
float get_elapsed_time (clocks_t *clock);
void move_sprite (sprite_t sprite, sfVector2f vec);
sfVector2f get_sprite_pos (sprite_t sprite);
sfIntRect create_rect (int x, int y, int off_x, int off_y);
sfVector2f create_vect (float x, float y);

/*Version : 1.1 */
#endif
