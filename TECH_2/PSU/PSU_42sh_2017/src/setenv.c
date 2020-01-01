/*
** EPITECH PROJECT, 2018
** setenv
** File description:
** add a variable to the env
*/

#include "mysh.h"

int aleready_exist (char *env1, char *to_find)
{
	char c1 = '\0';
	char c2 = '\0';

	do {
		c1 = *env1++;
		c2 = *to_find++;
		if (c1 == '\0' || c1 == '=' || c2 == '=')
			return (c1 - c2);
	} while (c1 == c2);
	return (c1 - c2);
}

int use_free_space (env_t *list, char *to_set)
{
	env_t *temp = list;

	while (temp) {
		if (!temp->path) {
			temp->path = to_set;
			return (1);
		}
		temp = temp->next;
	}
	return (0);
}

static int added (env_t *list, char *to_set)
{
	env_t *to_add = NULL;
	env_t *temp = list;

	if (!(to_add = malloc(sizeof(env_t)))) {
		my_putstr("Unable to set new env variable.\n");
		return (-1);
	}
	to_add->path = my_strcpy(to_set);
	to_add->next = NULL;
	while (temp->next) {
		temp = temp->next;
	}
	temp->next = to_add;
	return (1);
}

char *create_path (char **line)
{
	char *path_to_add = NULL;
	char *temp = NULL;

	if (line[1])
		path_to_add = my_strcat(line[1], "=");
	if (line[2]) {
		temp = path_to_add;
		path_to_add = my_strcat(temp, line[2]);
		free(temp);
	}
	return (path_to_add);
}

void setenv_bi (char **line, env_t *list)
{
	env_t *temp = list;
	char *path_to_add = create_path(line);

	if (!line || !line[1])
		return;
	while (temp) {
		if (temp->path && my_strfind(path_to_add, temp->path)) {
			free(temp->path);
			temp->path = my_strcpy(path_to_add);
			return;
		}
		temp = temp->next;
	}
	added (list, path_to_add);
}
