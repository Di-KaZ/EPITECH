/*
** EPITECH PROJECT, 2017
** 
** File description:
** 
*/

#include "pushswap.h"

int is_sorted (elem_t *list)
{
	elem_t *prev = list;
	list = list->next;

	while (list) {
		if (prev->nb > list->nb)
			return (0);
		prev = prev->next;
		list = list->next;
	}
	return (1);
}

void pushswap (elem_t *la, elem_t *lb)
{
	int is_opt_prev = 0;

	while (lb || is_sorted(la) == 0) {
		sc(&la, &lb);
		sa(&la,is_opt_prev);
		is_opt_prev = 1;
		sb(&lb);
		if (la->nb < la->next->nb && is_sorted(la) == 0) {
			my_putstr(" pb");
			lb = push (&la,lb);
		}
		if (is_sorted(la) && lb) {
			la = push (&lb, la);
			my_putstr(" pa");
		}
	}
	free_list(la);
}
