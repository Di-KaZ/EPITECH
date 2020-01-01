/*
** EPITECH PROJECT, 2018
** pointer_table
** File description:
** poiner_table
*/

#include "my_cook.h"

const char *action_ch[6] =
{
	"play",
	"options",
	"quit",
	"menu",
	"help",
	NULL
};

void (*action[5])(void *) =
{
	play, options,
	quit, menu, help,
};


void tab_pointer (button_t button)
{
	for (int i = 0; action_ch[i]; i += 1) {
		if (my_strfind(button->func, action_ch[i])) {
			button->callback = action[i];
		}
	}
}
