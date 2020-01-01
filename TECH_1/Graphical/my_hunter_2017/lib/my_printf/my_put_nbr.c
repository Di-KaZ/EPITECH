/*
** EPITECH PROJECT, 2017
** my_put_nbr
** File description:
** 
*/
#include "my.h"

int my_put_nbr(int nb)
{
	int res = 0;

	if (nb < 0){
		my_putchar('-');
		res += 1;
		nb = nb * -1;
	}
	if ((nb <= 9) && (nb >= 0)) {
		my_putchar(nb + 48);
		res += 1;
	}
	if (nb > 9) {
		my_put_nbr(nb / 10);
		my_putchar(nb % 10 + 48);
		res += 1;
	}
	return(res);
}
