/*
** EPITECH PROJECT, 2017
** 
** File description:
** 
*/

#include "bsq.h"

char  **convert_bsq (char **star)
{
	for (int i = 0; star[i] != NULL; i += 1) {
		for (int j = 0; star[i][j] != '\0'; j += 1) {
			if (star[i][j] == '.')
				star[i][j] = '1';
			if (star[i][j] == 'o')
				star[i][j] = '0';
		}
	}
	return (star);
}
