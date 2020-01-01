/*
** EPITECH PROJECT, 2018
** exec_multiple_commands.c
** File description:
** Functions used for pipes.
*/

#include "mysh.h"

const char shit_things[] = {'|', '<', '>', '\0'};
const char *shit_thing[] = {"|", "<", ">", NULL};

char did_we_need_to(char **command)
{
	for (int i = 0; command[i]; i += 1)
		for (int j = 0; shit_thing[j]; j += 1)
			if (my_strcmp(command[i], shit_thing[j]) == 0) {
				command[i] = NULL;
				return (shit_things[j]);
			}
	return ('\0');
}

void exec_multiple_prog(char **line, env_t *env)
{
	char ***parsed = parse_command(line);
	char c = '\0';

	for (int j = 0; parsed[j]; j += 1) {
		c = did_we_need_to(parsed[j]);
		manage_command(parsed, j, env, c);
	}
	free (parsed);
}
