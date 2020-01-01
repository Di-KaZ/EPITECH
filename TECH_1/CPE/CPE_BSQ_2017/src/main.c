/*
** EPITECH PROJECT, 2017
** 
** File description:
** 
*/

#include "bsq.h"

int main (int ac, char **av)
{
	file_t file = NULL;
	bsq_size_t size;
	char **bsq_arr = NULL;
	int **int_bsq_arr = NULL;
	int *coord_square = NULL;

	if (ac != 2)
		return (84);
	file = ini_file(av[1]);
	if (!file)
		return (84);
	size = get_size(file);
	bsq_arr = char_star_to_char_star_star(file->buffer, size);
	int_bsq_arr = convert_charss_intss(bsq_arr, size);
	coord_square = get_coord_square(int_bsq_arr, size);
	bsq_arr = result_bsq(bsq_arr, coord_square);
	print_bsq (bsq_arr);
	free_ressources (coord_square ,int_bsq_arr, bsq_arr, size);
	free_file(file);
	return (0);
}
