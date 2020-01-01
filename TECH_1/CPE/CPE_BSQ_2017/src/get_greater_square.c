/*
** EPITECH PROJECT, 2017
** 
** File description:
** 
*/

#include "bsq.h"

int **get_greater_square (int **int_bsq, bsq_size_t size)
{
	for (int i = 1; i < size.height; i += 1) {
		for (int j = 1; j < size.width; j += 1) {
			if (int_bsq[i][j] != 0)
				int_bsq[i][j] = compare_value (int_bsq[i][j - 1]
							,int_bsq[i - 1][j - 1]
							,int_bsq[i - 1][j]);
		}
	}
	return(int_bsq);
}
int *get_coord_square (int **int_bsq, bsq_size_t size)
{
	int *coord_square = malloc(sizeof(int) * 3);

	coord_square[0] = 0;
	coord_square[1] = -1;
	coord_square[2] = -1;
	for (int i = size.height - 1; i != 0; i -= 1) {
		for(int j = size.width - 1; j != 0 ; j -= 1) {
			if (coord_square[0] <= int_bsq[i][j]) {
				coord_square[0] = int_bsq[i][j];
				coord_square[1] = i;
				coord_square[2] = j;
			}
		}
	}
	return (coord_square);
}
char ** remake_clean (char **star)
{
	for (int i = 0; star[i] != NULL; i += 1) {
		for (int j = 0; star[i][j] != '\0'; j += 1) {
			if (star[i][j] == '0')
				star[i][j] = 'o';
			if (star[i][j] != 'x' && star[i][j] != 'o')
				star[i][j] = '.';
		}
	}
	return(star);
}

char **result_bsq (char **star, int *coord)
{
	int y = coord[1];
	int x = coord[2];

	for (int i = 0; i < coord[0]; i += 1) {
		x = coord[2];
		for (int j = 0; j < coord[0]; j += 1) {
			if (star[y][x] != '\0')
				star[y][x] = 'x';
			x -= 1;
		}
		y -= 1;
	}
	return (remake_clean(star));
}
