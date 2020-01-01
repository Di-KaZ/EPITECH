/*
** EPITECH PROJECT, 2017
** 
** File description:
** 
*/

#include "pushswap.h"

elem_t *add_head (elem_t *list, int nb)
{
	elem_t *to_add = malloc(sizeof(elem_t));
	to_add->nb = nb;
	to_add->next = list;
	return (to_add);
}

elem_t *add_tail (elem_t *list, int nb)
{
	elem_t *temp = NULL;
	elem_t *to_add = malloc(sizeof(elem_t));

	to_add->nb = nb;
	to_add->next = NULL;
	if (list == NULL)
		return (to_add);
	else
		temp = list;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = to_add;
	return (list);
}

elem_t *fill_list (elem_t *list, int size, char **listarr)
{
	for (int i = 1; i < size; i += 1) {
		if (listarr != NULL)
			list = add_tail(list, my_get_nbr(listarr[i]));
		else
			list = add_tail(list, -1);
	}
	return (list);
}
/* Debug fuction that print a list */
void printl (elem_t *list)
{
	if (list == NULL)
		return;
	my_put_nbr(list->nb);
	if (list->next != NULL)
		my_putchar(' ');
	printl(list->next);
}

int main (int ac, char **av)
{
	elem_t *lista = NULL;
	elem_t *listb = NULL;

	if (ac == 1)
		return (84);
	if (ac == 2) {
		my_putchar('\n');
		return (0);
	}

	lista = fill_list(lista, ac, av);
	pushswap(lista, listb);
	my_putchar('\n');
	return (0);
}
