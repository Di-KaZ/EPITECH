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

/* Define shortcut for csfml function */

#define DISP_WINDOW(window) (sfRenderWindow_display(window->window))
#define POLL_EVENT(win, evt) (sfRenderWindow_pollEvent(win->window, &evt))
#define SET_FRAMERATE(win, f) (sfRenderWindow_setFramerateLimit(win->window, f))
#define WIN_ISOPEN(win) (sfRenderWindow_isOpen(win->window))

/* Structure */

typedef struct sprite_s {
	sfSprite *sprite;
	sfTexture *texture;
} sprite_t;

typedef struct window_s {
	int height;
	int width;
	sfRenderWindow *window;
} window_t;

typedef struct clock_s {
	sfClock *clock;
	sfTime time;
} clock__t;

/* Prototypes */

window_t *ini_window (char* name, int width, int height);
void destroy_window (window_t **window);
sprite_t *ini_sprite (char *path_to_text);
void destroy_sprite (sprite_t **sprite);
void disp_sprite (window_t *window, sprite_t *sprite);
void window_clear (window_t *window, sfColor color);
clock__t * ini_clock (void);
float get_elapsed_time (clock__t *clock);
void disp_sprite_rect (sprite_t *sprite, int x, int y, int o_x, int o_y);
void set_sprite_pos(sprite_t *sprite, int x, int y);
void set_sprite_scale (sprite_t *sprite, int x, int y);
void move_sprite (sprite_t *sprite, int x, int y);
sfVector2f get_sprite_pos (sprite_t *sprite);
void mul_sprite_scale (sprite_t *sprite, int x, int y);
