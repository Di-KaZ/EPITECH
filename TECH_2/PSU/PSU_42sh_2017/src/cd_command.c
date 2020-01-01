/*
** EPITECH PROJECT, 2018
** cd_command
** File description:
** cd
*/

#include "mysh.h"

void cd_command (char **line, env_t *env)
{
	static char prev_dir[1000];
	static int first = 1;

	first == 1 ? getcwd(prev_dir, 1000) : 0;
	if (my_strcmp (line[0], "cd") == 0
		&& line[1] != NULL && my_strcmp(line[1], "-") == 0 &&
		chdir(prev_dir) == 0) {
		getcwd(prev_dir, 1000);
		return;
	}
	if (my_strcmp(line[0], "cd") == 0 && line[1] == NULL) {
		chdir(search_path(env, "HOME=") + 5);
	}
	else if (chdir(line[1]) == 0) {
	}
	else {
		my_putstr(line[1]);
		my_putstr(" is not a directory.\n");
	}
	first = 0;
}

