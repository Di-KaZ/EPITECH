/*
** EPITECH PROJECT, 2018
** 4
** File description:
** 5
*/

#include "get_next_line.h"
#include "my_garbage_collector.h"

static int my_strlen (char const *str)
{
	int len = 0;

	if (str)
		for (len = 0; str[len] != '\0'; len++);
	else
		return (0);
	return (len);
}

char *my_realloc (char *str, const char *to_add, int size)
{
	int new_len = my_strlen(str) + size;
	char *realloc = g_malloc(sizeof(char) * (new_len + 1));
	int i = 0;
	int y = 0;

	for (; str && str[i] != '\0'; i += 1)
		realloc[i] = str[i];
	for (; i < new_len; i += 1, y += 1)
		realloc[i] = to_add[y];
	realloc[new_len] = '\0';
	return (realloc);
}

char *get_next_line (int fd)
{
	static char buffer[READ_SIZE + 1];
	static int i = 1;
	char *line = NULL;

	buffer[0] = '\0';
	if (i == 1)
		read(fd, buffer, READ_SIZE);
	for (; "True"; i += 1) {
		if (buffer[0] == '\0')
			return (NULL);
		if (buffer[i - 1] == '\n') {
			line = my_realloc(line, buffer, i - 1);
			i = 1;
			return(line);
		}
		else if (i == READ_SIZE + 1) {
			line = my_realloc(line, buffer, i);
			read(fd, buffer, READ_SIZE);
			i = 0;
		}
	}
	return (NULL);
}
