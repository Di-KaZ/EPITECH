/*
** EPITECH PROJECT, 2017
** my_csfml.h 
** File description:
** my_csfml.h
*/

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Window.h>
#include <stdlib.h>
#ifndef _MY_CSFML_
#define _MY_CSFML_
/* Structure */
typedef struct sprite_s {
	sfSprite *sprite;
	sfTexture *texture;
} *sprite_t;

typedef struct window_s {
	int height;
	int width;
	sfEvent event;
	sfRenderWindow *window;
} window_t;

typedef struct clocks_s {
	sfClock *clock;
	sfTime time;
} clocks_t;

typedef struct object_s {
	char *name;
	unsigned int type;
	sprite_t sprite;
	int offset;
	struct object_s *next;
} *object_t;

typedef struct button_s {
	char *func;
	sprite_t sprite;
	int offset;
	void (*callback)(void *);
	struct button_s *next;
} *button_t;

typedef struct scene_s {
	char *name;
	object_t objs;
	button_t buttons;
	struct scene_s *next;
} *scene_t;

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
sfVector2f get_mouse_pos (window_t *window);
button_t add_button (button_t buttons, char *);
int buttonIsClicked (button_t button, sfVector2f);
char *get_path (char *conf);
int get_coord (char*, int *i);
int simple_collision (sfSprite*, sfSprite*);
/*Version : 1.14 */
#endif
