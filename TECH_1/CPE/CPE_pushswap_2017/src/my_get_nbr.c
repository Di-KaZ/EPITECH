/*
** EPITECH PROJECT, 2017
** 
** File description:
** 
*/

#include "pushswap.h"

int my_get_nbr (char const *str) {
	int i = 0;
	int signe = 1;
	int nb_found = 0;
	int nb_final = 0;

	while (str[i] != '\0') {
		if (str[i] == '-')
			signe = -1;
		if (str[i] >= '0' &&  str[i] <= '9') {
			nb_found = str[i] - '0';
			nb_final = (nb_final * 10) + nb_found;
			if ((nb_final * 10) > 2000000000)
				return (84);
			if (str[i+1] < '0' || str[i+1] > '9')
				return (signe * nb_final);
		}
		i += 1;
	}
	return (0);
}


