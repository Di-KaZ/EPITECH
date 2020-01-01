/*
** EPITECH PROJECT, 2017
** 
** File description:
** 
*/

#include "bsq.h"

file_t ini_file(char *path)
{
	file_t file = malloc(sizeof(*file));

	if (!file)
		return (NULL);
	if (stat(path, &(file->info)) == -1)
		return (NULL);
	if (file->info.st_size == 0)
		return (NULL);
	file->buffer = malloc(sizeof(file->buffer) * file->info.st_size);
	if (!file->buffer)
		return (NULL);
	file->fd = open(path, O_RDONLY);
	read(file->fd, file->buffer, file->info.st_size);
	return (file);
}

void free_file (file_t file)
{
	free(file->buffer);
	close(file->fd);
	free(file);
}
