/*
** EPITECH PROJECT, 2018
** open_map
** File description:
** open_map
*/

#include "my_cook.h"

int count_n_line (FILE *file)
{
	char *buffer = NULL;
	int i = 0;
	size_t size = 0;

	for (i = 0; getline(&buffer, &size, file) != -1; i += 1) {
		free(buffer);
		buffer = NULL;
	}
	free(buffer);
	return(i);
}

char **ini_map (char *path)
{
	FILE *file = fopen(path, "r");
	char *buffer = NULL;
	int cols;
	char **map = NULL;
	size_t size = 0;

	if (file == NULL ? write(1, "File is not a map", 17) : 0)
		return (NULL);
	cols = count_n_line(file) + 1;
	map = malloc(sizeof(char*) * cols);
	fclose(file);
	file = fopen(path, "r");
	for (int i = 0; getline(&buffer, &size, file) != -1; i += 1) {
		map[i] = buffer;
		buffer = NULL;
	}
	free(buffer);
	map[cols - 1] = NULL;
	fclose(file);
	return(map);
}
