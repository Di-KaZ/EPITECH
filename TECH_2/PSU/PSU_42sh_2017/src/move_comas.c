/*
** EPITECH PROJECT, 2018
** comas.c
** File description:
** comas
*/

#include "mysh.h"

int comas_to_move(char *line, char c)
{
	int nb = 0;

	for (int i = 0; line[i]; i+= 1) {
		if (line[i] == c && i != 0 && line[i - 1] == ' ')
			nb += 2;
		if (line[i] == c && line[i + 1] != ' ')
			nb += 2;
	}
	return (nb);
}
char *move_every_shit(char *line)
{
	char to_move[] = {'|', '>', '<', ';', '\0'};

	for (int i = 0; i != to_move[i]; i += 1) {
		line = move_comas(line, to_move[i]);
	}
	return (line);
}

char * move_comas(char *line, char c)
{
	int j = 0;
	char *moved = malloc(sizeof(char) * (comas_to_move(line, c)
	 					+ my_strlen(line) + 1));
	if (my_strlen(line) == 1) {
		free(moved);
			return (line);
	}
	for (int i = 0; line[i]; j += 1, i += 1) {
		if (line[i] == c && i != 0 && line[i - 1] != ' ') {
			moved[j++] = ' ';
			moved[j] = c;
		}
		if (line[i] == c && line[i + 1] != ' ') {
			moved[j++] = c;
			moved[j++] = ' ';
			moved[j] = line[i++];
		}
		moved[j] = line[i];
	}
	moved[j] = '\0';
	free (line);
	return (moved);
}
