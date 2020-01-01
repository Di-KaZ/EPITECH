/*
** EPITECH PROJECT, 2018
** close_window
** File description:
** close_window
*/

#include "my_cook.h"

void close_window (void *window)
{
	window_t *ye = window;
	sfRenderWindow_close(ye->window);
}

void not_implemented (void *data)
{
	if (data)
		my_putstr("Sorry this function is not yet implemented. :(\n");
}
