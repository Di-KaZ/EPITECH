/*
** EPITECH PROJECT, 2018
** command
** File description:
** exec
*/

#include "mysh.h"
#include <sys/types.h>
#include <sys/wait.h>

void disp_env(env_t *env)
{
	while (env) {
		if (env->path)
			my_printf("%s\n", env->path);
		env = env->next;
	}
}

void exec_prog(char **line, char  **env)
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
		wait(&status);
		if (WCOREDUMP(status))
			my_putstr("Segmentation fault (core dumped)\n");
	}
}

char *search_for_exist_path(char *path, char *bin_name)
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
/* LAISSE STP */
int exec_binary(char ***line, env_t *env, char c, int where)
{
	char *binary_path = NULL;
	char **arr_env = chained_to_array(env);
	int pipefd[2];
	int status[2];
	static int prev_double_command = 0;

	if (prev_double_command == 1) {
		prev_double_command = 0;
		return (1);
	}
	if (!line[where][0]) {
		my_putstr("Invalid null command.\n");
		return(0);
	}
	if (line[where][0] && line[where][0][0] && line[where][0][0]
		== '.' && line[where][0][1] == '/') {
		exec_prog(line[where], arr_env);
		return (0);
	}
	if (!(binary_path = search_for_exist_path(search_path(env, "PATH=") + 5,
						  line[where][0]))) {
		my_printf("%s: Command not found.\n", line[where][0]);
		return(0);
	}
	if (exec_one_command(c, binary_path, line[where], arr_env))
		return(0);
	if (exec_redir_file_command(c, line, env, where)) {
		prev_double_command = 1;
		return (1);
	}
	if (c == '|') {
		pipe(pipefd);
		if ((status[0] = fork()) == 0) {
			dup2(pipefd[1], 1);
			close(pipefd[0]);
			execvp(binary_path, line[where]);
		}
		if ((status[1] = fork()) == 0) {
			dup2(pipefd[0], 0);
			close(pipefd[1]);
			binary_path = search_for_exist_path
				(search_path(env, "PATH=") + 5,
							line[where + 1][0]);
			execve(binary_path, line[where + 1], NULL);
			if (WCOREDUMP(status[0]))
				my_putstr("Segmentation fault (core dumped)\n");
		}
		close(pipefd[0]);
		close(pipefd[1]);
		wait(&status[0]);
		wait(&status[1]);
	}
	return (1);
} /* LAISSE STP */

char *search_path(env_t *env, const char *to_find)
{
	while (env) {
		if (env->path && str_first_find(env->path, (char *)to_find)) {
			return (env->path);
		}
		env = env->next;
	}
	return (NULL);
}
