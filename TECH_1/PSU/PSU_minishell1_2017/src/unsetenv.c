/*
** EPITECH PROJECT, 2018
** unsetenv
** File description:
** delete a variable from the env
*/

#include "mysh.h"

void unsetenv_bi (char **line, env_t *env)
{
	env_t *temp = env;

	if (!line[1]) {
		my_putstr("unsetenv: Too few arguments.\n");
		return;
	}
	while (temp) {
		if (temp->path && my_strfind(temp->path, line[1]) == 1) {
			free(temp->path);
			temp->path = NULL;
		}
		temp = temp->next;
	}
}
