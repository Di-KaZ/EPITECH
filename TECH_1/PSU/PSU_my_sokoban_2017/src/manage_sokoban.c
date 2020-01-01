/*
** EPITECH PROJECT, 2017
** 
** File description:
** 
*/

#include "my_sokoban.h"

char **ini_sokoban (char *path)
{
	FILE *file = fopen(path, "r");
	char *buffer = NULL;
	int cols;
	char **map = NULL;
	size_t size = 0;

	if (file == NULL)
		return (NULL);
	cols =  count_n_line(file) + 1;
	map = malloc(sizeof(char*) * cols);
	file = freopen(path, "r", file);
	for (int i = 0; getline(&buffer, &size, file) != -1; i += 1) {
		map[i] = buffer;
		buffer = NULL;
	}
	free(buffer);
	map[cols - 1] = NULL;
	fclose(file);
	return(map);
}

int count_n_line (FILE *file)
{
	char *buffer = NULL;
	int i;
	size_t size = 0;

	for (i = 0; getline(&buffer, &size, file) != -1; i += 1) {
		free(buffer);
		buffer = NULL;
	}
	free(buffer);
	return (i);
}

void free_map (char **map)
{
	int i = 0;

	for (i = 0; map[i] != NULL; i += 1)
		free(map[i]);
	free(map[i]);
	free(map);
}
