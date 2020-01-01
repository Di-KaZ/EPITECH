/*
** EPITECH PROJECT, 2017
** 
** File description:
** 
*/

#include "pushswap.h"


void sc (elem_t **la, elem_t **lb)
{
	if ((*lb) && (*lb)->next &&
		(*lb)->nb < (*lb)->next->nb &&
		(*la)->nb > (*la)->next->nb) {
		my_putstr(" sc");
		swap(*la);
		swap(*lb);
	}
}

void sa (elem_t **la, int opt_prev)
{
	if ((*la)->nb > (*la)->next->nb) {
		if (opt_prev == 1)
			my_putchar(' ');
		my_putstr("sa");
		swap(*la);
	}
}

void sb (elem_t **lb)
{
	if (*lb && (*lb)->next && (*lb)->nb < (*lb)->next->nb) {
		my_putstr(" sb");
		swap(*lb);
	}
}
