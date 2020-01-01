/*
** EPITECH PROJECT, 2017
** 
** File description:
** 
*/

#include "bsq.h"

bsq_size_t get_size (file_t file)
{
	int i = 0;
	bsq_size_t size = {0, 0, 0};

	while (file->buffer[i] != '\n' && file->buffer[i] != '\0') {
		if (!IS_NUM(file->buffer[i]))
			return (size);
		i += 1;
	}
	size.start_of_map = i + 1;
	size.height = get_height(file);
	size.width = get_width(file, i + 1);
	return(size);
}

int get_width (file_t file, int start_offset)
{
	int width = 0;

	while (file->buffer[start_offset] != '\n') {
		width += 1;
		start_offset += 1;
	}
	return (width);
}

int get_height (file_t file)
{
	int i = 0;
	int nb_found = 0;
	int nb_final = 0;

	while (file->buffer[i] != '\n') {
		if (IS_NUM(file->buffer[i])) {
			nb_found = file->buffer[i] - '0';
			nb_final = (nb_final * 10) + nb_found;
			if (file->buffer[i+1] < '0' || file->buffer[i+1] > '9')
				return (nb_final);
		}
		i += 1;
	}
	return (0);
}

