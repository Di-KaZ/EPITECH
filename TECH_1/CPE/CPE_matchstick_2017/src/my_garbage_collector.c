/*
** EPITECH PROJECT, 2018
** 5
** File description:
** 56
*/

#include "my_garbage_collector.h"

pile_t new_pile (size_t size, pile_t pile)
{
	pile_t new_pile = malloc(sizeof(*new_pile));

	new_pile->address = malloc(size);
	new_pile->next = pile;
	return (new_pile);
}

void *g_malloc (size_t size)
{
	static pile_t pile = NULL;

	pile = new_pile(size, pile);
	if (size == 0) {
		g_free(pile);
		return (NULL);
	}
	return (pile->address);
}

void g_free (pile_t pile)
{
	pile_t temp = pile;

	for (int i = 0; pile; i += 1) {
		temp = pile;
		pile = pile->next;
		free(temp->address);
		free(temp);
	}
}
