/*
** EPITECH PROJECT, 2018
** 
** File description:
** 
*/

#include "get_next_line.h"
#include <stdio.h>

static int my_strlen (char const *str)
{
	int len;

	if (str)
		for (len = 0; str[len] != '\0'; len++);
	else
		return (0);
	return (len);
}

char *my_realloc (char *str, const char *to_add, int size)
{
	int new_len = my_strlen(str) + size;
	char *realloc = malloc(sizeof(char) * (new_len + 1));
	int i = 0;
	int y = 0;

	for (; str && str[i] != '\0'; i += 1)
		realloc[i] = str[i];
	for (; i < new_len; i += 1, y += 1)
		realloc[i] = to_add[y];
	realloc[new_len] = '\0';
	free(str);
	return (realloc);
}

char *get_next_line (int fd)
{
	static char buffer[READ_SIZE + 1];
	char *line = NULL;
	static int i = 1;

	buffer[READ_SIZE] = '\0';
	if (i == 1)
		read(fd, buffer, READ_SIZE);
	for (; "WAZZA"; i += 1) {
		if (buffer[i - 1] == '\n') {
			line = my_realloc(line, buffer, i - 1);
			i = 1;
			return(line);
		}
		else if (buffer[i] == '\0') {
			line = my_realloc(line, buffer, i);
			read(fd, buffer, READ_SIZE);
			i = 0;
		}
	}
	return ("Unexcpeted error occured");
}
