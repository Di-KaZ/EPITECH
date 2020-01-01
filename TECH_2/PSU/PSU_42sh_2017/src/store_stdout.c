/*
** EPITECH PROJECT, 2018
** store_stdout.c
** File description:
** Functions between pipes.
*/

#include "mysh.h"

char *realloc_mdr(char *to_realloc, char to_add)
{
	char *realloc = NULL;
	int i = 0;

	if (!to_realloc)
		realloc = malloc(sizeof(char) * (2));
	else
		realloc = malloc(sizeof(char) * (my_strlen(to_realloc) + 2));
	for (i = 0; to_realloc && to_realloc[i]; i += 1)
		realloc[i] = to_realloc[i];
	realloc[i] = to_add;
	realloc[i + 1] = '\0';
	free(to_realloc);
	return (realloc);
}

char *read_pipe(int fd)
{
	char *stdout_r = NULL;
	char buff;

	if (read(fd, &buff, 1) < 0) {
		write(1, &buff, 1);
		stdout_r = realloc_mdr(stdout_r, buff);
	}
	return (stdout_r);
}

char **realloc_line(char **line, char *redirect)
{
	char **realloc = NULL;
	int i = 0;
	if (!line)
		return (NULL);
	for (; line[i]; i += 1);
	realloc = malloc(sizeof(char **) * (i + 2));
	if (!realloc)
		return (NULL);
	for (i = 0; line[i]; i += 1) {
		realloc[i] = line[i];
	}
	realloc[i] = redirect;
	realloc[i + 1] = NULL;
	free (line);
	return (realloc);
}
