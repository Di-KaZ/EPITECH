/*
** EPITECH PROJECT, 2018
** linkers
** File description:
** usage of function pointers
*/

#include "mysh.h"

void disp_env_l (char **line, env_t *env)
{
	(void)line;
	disp_env (env);
}

void exit_l (char **line, env_t *env)
{
	free_env(env);
	free_line(line, NULL);
	exit (0);
}

void clear_l (char **line, env_t *env)
{
	(void)line;
	(void)env;
	my_putstr("\033[H\033[2J");
}
