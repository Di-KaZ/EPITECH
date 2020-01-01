/*
** EPITECH PROJECT, 2018
** get_next_line.c
** File description:
** get_next_line functions
*/

#include "get_next_line.h"

static char *my_realloc(char *str, int size)
{
	char *stack = str;

	str = malloc(sizeof(char) * (size + 1));
	str[size] = '\0';
	for (int i = 0; stack[i]; i++)
		str[i] = stack[i];
	free(stack);
	return (str);
}

static int verif(pack_t *pack, int i, int fd)
{
	if (pack->size == -2 || pack->start >= pack->size) {
		pack->size = read(fd, pack->buffer, READ_SIZE);
		pack->start = 0;
	}
	if ((pack->size == 0 || pack->buffer[pack->start] == '\0') && i == 0)
		return (2);
	if (pack->size == 0 || pack->buffer[pack->start] == '\0')
		return (1);
	if (pack->buffer[pack->start] == '\n') {
		pack->start++;
		return (1);
	}
	return (0);
}
static char *get_line(int fd)
{
	char *str;
	static pack_t pack = {"", 0, -2};
	int state;

	str = malloc(sizeof(char) * READ_SIZE + 1);
	str[READ_SIZE] = '\0';
	for (int i = 0, loop = 1; 1; pack.start++, i++) {
		if (i >= READ_SIZE * loop) {
			loop++;
			str = my_realloc(str, READ_SIZE * loop);
		}
		if ((state = verif(&pack, i, fd)) == 2) {
			free(str);
			return (NULL);
		} else if (state == 1) {
			str[i] = '\0';
			return (str);
		}
		str[i] = pack.buffer[pack.start];
	}
}

char *get_next_line(int fd)
{
	if (fd == -1 || READ_SIZE < 1)
		return (NULL);
	return (get_line(fd));
}
