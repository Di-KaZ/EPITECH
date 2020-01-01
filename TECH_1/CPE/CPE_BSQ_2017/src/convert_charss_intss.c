/*
** EPITECH PROJECT, 2017
** 
** File description:
** 
*/

#include "bsq.h"

int **convert_charss_intss (char **star, bsq_size_t size)
{
	int **int_bsq = malloc(sizeof(int*) * size.height);

	for (int i = 0; star[i] != NULL; i += 1) {
		int_bsq[i] = malloc(sizeof(int) * size.width);
		for (int j = 0; star[i][j] != '\0'; j += 1) {
			int_bsq[i][j] = CHAR2INT(star[i][j]);
		}
	}
	return (get_greater_square(int_bsq, size));
}

void free_int_star_star(int **int_bsq, bsq_size_t size)
{
	for(int i = 0; i < size.height; i += 1)
		free(int_bsq[i]);
	free(int_bsq);
}
