/*
** EPITECH PROJECT, 2018
** exec_diff_redic.c
** File description:
** Executes binary and redirect the result.
*/

#include "mysh.h"

int exec_one_command(char c, char *binary_path, char **arg, char **env)
{
	int status;

	if (c)
		return(0);
	if ((status = fork()) == 0) {
		execve(binary_path, arg, env);
	}
	else {
		wait(&status);
		return(1);
	}
	return (-1);
}


int exec_redir_file_command(char c, char ***line, env_t *env, int where)
{
	int status;
	char *binary_path = search_for_exist_path(search_path(env, "PATH=") + 5,
								line[where][0]);
	int fd;
	char **arr_env = chained_to_array(env);
	int pipefd[2];
	char buf;

	if (c != '>')
		return(0);
	fd = open(line[where + 1][0], O_CREAT | O_RDWR, S_IRUSR | S_IWUSR);
	if (fd == -1) {
		return (1);
	}
	pipe(pipefd);
	if ((status = fork()) == 0) {
		dup2(pipefd[1], 1);
		close(pipefd[0]);
		execve(binary_path, line[where], arr_env);
	}
	else {
		wait(&status);
		close(pipefd[1]);
		while (read(pipefd[0], &buf, 1) > 0)
			write(fd, &buf, 1);
		close(fd);
		return(1);
	}
	return (-1);
}
