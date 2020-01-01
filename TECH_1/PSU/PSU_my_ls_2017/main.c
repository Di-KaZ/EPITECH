/*
** EPITECH PROJECT, 2017
** 
** File description:
** 
*/

#include "my_ls.h"

int main (int ac, char **av)
{
	option_t *options = is_option(ac, av);
	if (manage_dir(ac, av, options) == 84)
		return (84);
	free(options);
	my_putchar('\n');
	return (0);
}
