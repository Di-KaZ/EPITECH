/*
** EPITECH PROJECT, 2018
** transform chained list to an array of char *
** File description:
** well
*/

#include "mysh.h"

int env_number (env_t *env)
{
	int number = 0;

	while (env) {
		if (env->path)
			number += 1;
		env = env->next;
	}
	return (number);
}

char **chained_to_array (env_t *env)
{
	int env_num = env_number(env);
	char **array = malloc(sizeof(char *) * (env_num + 1));

	for (int i = 0; i != env_num;) {
		if (env->path) {
			array[i] = env->path;
			i += 1;
		}
		env = env->next;
	}
	array[env_num] = NULL;
	return (array);
}
