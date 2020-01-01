/*
** EPITECH PROJECT, 2018
** command
** File description:
** exec
*/

#include "mysh.h"

void disp_env (env_t *env)
{
	while (env) {
		if (env->path)
			my_printf("%s\n", env->path);
		env = env->next;
	}
}

void exec_prog (char **line, char  **env)
{
	int status;
	char *path = my_strcat("./", line[0] + 2);

	if (!line[0][2]) {
		free(path);
		my_putstr("./: Permission denied.\n");
		return;
	}
	if (access(path, F_OK)) {
		free(path);
		my_printf("%s: Command not found.\n", line[0]);
		return;
	}

	if (fork() == 0)
		execve(line[0] + 2, line, env);
	else {
		wait3(&status, 0, NULL);
		if (WCOREDUMP(status))
			my_putstr("Segmentation fault (core dumped)\n");
	}
}

char *search_for_exist_path (char *path, char *bin_name)
{
	char **parsed = path_parser(path);
	char *temp = NULL;
	char *path_found = NULL;

	for (int i = 0; parsed[i]; i += 1) {
		temp = my_strcat(parsed[i], bin_name);
		if (access(temp, F_OK) == 0)
			path_found = temp;
		else
			free(temp);
		free(parsed[i]);
	}
	free(parsed);
	return (path_found);
}

void exec_binary (char **line, env_t *env)
{
	int status;
	char *binary_path = NULL;
	char **arr_env = chained_to_array(env);

	if (line[0][0] && line[0][0] == '.' && line[0][1] == '/') {
		exec_prog(line, arr_env);
		return;
	}
	if (!(binary_path = search_for_exist_path(search_path(env, "PATH=") + 5,
						  line[0]))) {
		my_printf("%s: Command not found.\n", line[0]);
		return;
	}
	if (env != NULL && fork() == 0) {
		execve(binary_path, line, arr_env);
		my_printf("lolZPAEOJZAPOJEZAPOJEAPOEJPOZAJEPOJEZAPOM");
	}
	else {
		wait3(&status, 0, NULL);
		if (WCOREDUMP(status))
			my_putstr("Segmentation fault (core dumped)\n");
	}
}

char *search_path (env_t *env, const char *to_find)
{
	while (env) {
		if (env->path && str_first_find(env->path, (char *)to_find)) {
			return (env->path);
		}
		env = env->next;
	}
	return (NULL);
}
