/*
** EPITECH PROJECT, 2017
** 
** File description:
** 
*/

#include "my_ls.h"

option_t *is_option(int ac, char **av)
{
	option_t *options = init_flag();

	if (av[1] == NULL)
		return (options);
	for (int i = 1; i < ac; i += 1)
		if (av[i][0] == '-')
			fill_flag(&options, av[i]);
	return (options);
}

option_t *init_flag (void)
{
	option_t *options = malloc(sizeof(*options));

	options->l_flag = 0;
	options->rr_flag = 0;
	options->d_flag = 0;
	options->r_flag = 0;
	options->t_flag = 0;
	return (options);
}

int fill_flag (option_t **options, const char *string)
{
	for (int i = 1; string[i] != '\0'; i += 1) {
		if (string[i] == 'l')
			(*options)->l_flag = 1;
		else if (string[i] == 'R')
			(*options)->rr_flag = 1;
		else if (string[i] == 'd')
			(*options)->d_flag = 1;
		else if (string[i] == 'r')
			(*options)->r_flag = 1;
		else if (string[i] == 't')
			(*options)->t_flag = 1;
		else
			return (84);
	}
	return (0);
}
