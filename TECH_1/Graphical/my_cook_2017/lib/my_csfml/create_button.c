/*
** EPITECH PROJECT, 2018
** create_button
** File description:
** create button
*/

#include "my_csfml.h"

int get_coord (char *str, int *i)
{
	int signe = 1;
	int nb_found = 0;
	int nb_final = 0;
	for (; str[*i] != '\0'; *i += 1) {
		if (str[*i] == '-')
			signe = -1;
		if (str[*i] >= '0' && str[*i] <= '9') {
			nb_found = str[*i] - '0';
			nb_final = (nb_final * 10) + nb_found;
			if (str[*i + 1] < '0' || str[*i + 1] > '9') {
				*i += 2;
				return (signe * nb_final);
			}
		}
	}
	return (-4242);
}

char *get_path (char *conf)
{
	int i = 0;
	char *path = NULL;
	for (; conf[i] == ' ' || conf[i] == '\t'; i += 1);
	conf += i;
	for (i = 0; conf[i] != ' ' && conf[i]; i += 1);
	path = malloc(sizeof(char) * (i + 1));
	for (i = 0; conf[i] != ' ' && conf[i] != '\n' && conf[i]; i += 1)
		path[i] = conf[i];
	path[i] = '\0';
	return (path);
}

void tab_pointer (button_t);

button_t add_button (button_t last, char *conf)
{
	button_t button = malloc(sizeof(*button));
	button->sprite = ini_sprite(get_path(conf));
	int i = 0;
	sfSprite_setPosition(button->sprite->sprite,
			     create_vect(get_coord(conf, &i),
					 get_coord(conf, &i)));
	button->func = get_path(conf + i);
	button->offset = sfSprite_getLocalBounds(button->sprite->sprite).width
									/ 2;
	tab_pointer (button);
	button->next = last;
	return (button);
}

static void animate_button (button_t button, sfVector2f mouse_pos)
{
	sfFloatRect rect = sfSprite_getLocalBounds(button->sprite->sprite);

	if (!(mouse_pos.x < sfSprite_getPosition(button->sprite->sprite).x +
		rect.width &&
		mouse_pos.x > sfSprite_getPosition(button->sprite->sprite).x &&
		mouse_pos.y < sfSprite_getPosition(button->sprite->sprite).y +
		rect.height &&
		mouse_pos.y > sfSprite_getPosition(button->sprite->sprite).y))
		sfSprite_setTextureRect(button->sprite->sprite,
					create_rect(button->offset, 0,
					button->offset, rect.height));
	else
		sfSprite_setTextureRect(button->sprite->sprite,
					create_rect(0, 0,
					button->offset, rect.height));
}

int my_strfind(const char*, const char*);

int buttonIsClicked(button_t button, sfVector2f mouse_pos)
{
	sfFloatRect rect = sfSprite_getLocalBounds(button->sprite->sprite);
	if (my_strfind(button->func, "animated"))
		animate_button (button, mouse_pos);

	return (mouse_pos.x < sfSprite_getPosition(button->sprite->sprite).x +
		rect.width &&
		mouse_pos.x > sfSprite_getPosition(button->sprite->sprite).x &&
		mouse_pos.y < sfSprite_getPosition(button->sprite->sprite).y +
		rect.height &&
		mouse_pos.y > sfSprite_getPosition(button->sprite->sprite).y);
}
