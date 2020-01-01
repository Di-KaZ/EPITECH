/*
** EPITECH PROJECT, 2018
** 
** File description:
** 
*/

#include "mysh.h"

int change_old_pwd (env_t *env)
{
	char buffer[10000];
	char *path = search_path(env, "OLDPWD=");
	static int first = 1;

	if (first == 1) {
		first = 0;
		return (1);
	}
	getcwd(buffer, 10000);
	if ((path = my_strcat("OLDPWD=", buffer)))
		return (1);
	return (-1);
}

int switch_old (env_t *env)
{
	char buffer[1000];
	char *path = search_path(env, "OLDPWD=");

	getcwd(buffer, 1000);
	chdir(search_path(env, "OLDPWD=") + 7);
	if ((path = my_strcat("OLDPWD=", buffer)))
		return (1);
	return (-1);
}

void cd_command (char **line, env_t *env)
{
	static char prev_dir[1000];

	if ((my_strcmp(line[0], "cd") == 0
	     && line[1] && my_strcmp(line[1], "-") == 0)) {
		switch_old (env);
	}
	if (my_strcmp(line[0], "cd") == 0 && line[1] == NULL) {
		change_old_pwd(env);
		chdir(search_path(env, "HOME=") + 5);
	}
	else if (my_strcmp(line[1], "-") == 0) {
		chdir(prev_dir);
		change_old_pwd(env);
	}
	else if (chdir(line[1]) == 0)
		change_old_pwd(env);
	else
		my_printf("%s is not a directory.\n", line[1]);
}
