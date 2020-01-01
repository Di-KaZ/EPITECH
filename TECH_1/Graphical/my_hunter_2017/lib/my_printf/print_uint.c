/*
** EPITECH PROJECT, 2017
** 
** File description:
** 
*/

#include "my.h"

int print_uint_bin (unsigned int nb)
{
	if (nb > 0) {
		print_uint_bin(nb / 2);
		my_put_nbr(nb % 2);
	}
	return(0);
}
