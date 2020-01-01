/*
** EPITECH PROJECT, 2017
** 
** File description:
** 
*/

#include "bsq.h"

void free_ressources (int *coord, int **int_bsq,
		      char **bsq_arr, bsq_size_t size)
{
	free(coord);
	free_int_star_star(int_bsq, size);
	free_char_star_star (bsq_arr);
}
