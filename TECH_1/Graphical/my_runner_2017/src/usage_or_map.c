/*
** EPITECH PROJECT, 2018
** 
** File description:
** 
*/

#include "run.h"
#include <unistd.h>

void disp_usage (void)
{
	my_putstr("\x1b[31m""Welcome to my_runner\n""\x1b[0m");
	my_putstr("\tto begin use ./my_runner ");
	my_putstr("\x1b[32m""[map_path]\n""\x1b[0m");
	my_putstr("\twhile in game you can set your skin and fps");
	my_putstr(" by pressing escape\n");
	my_putstr("\tA guide to make map is implemented in the menu\n");
}

map_t usage_or_map (window_t *window, const char *str)
{
	if (str && str[0] == '-' && str[1] == 'h') {
		disp_usage();
		return (NULL);
	}
	else
		return (ini_map_t(window, (char*)str));
	return (NULL);
}
