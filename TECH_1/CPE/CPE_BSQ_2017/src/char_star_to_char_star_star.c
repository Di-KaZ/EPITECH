/*
** EPITECH PROJECT, 2017
** 
** File description:
** 
*/

#include "bsq.h"

char **char_star_to_char_star_star (char *str, bsq_size_t size)
{
	char **to_arr = malloc(sizeof(char*) * (size.height + 1));
	int i = 0;
	int j = 0;
	int s = 0;

	str += size.start_of_map;
	while (j < size.height) {
		to_arr[j] = malloc(sizeof(char) * (size.width + 1));
		i = 0;
		while (str[s] != '\n' && str[s] != '\0') {
			to_arr[j][i] = str[s];
			i += 1;
			s += 1;
		}
		s += 1;
		to_arr[j][i] = '\0';
		j += 1;
	}
	to_arr[j] = NULL;
	return (convert_bsq(to_arr));
}

void free_char_star_star (char **star)
{
	for (int i = 0; star[i] != NULL; i += 1)
		free(star[i]);
	free(star);
}
