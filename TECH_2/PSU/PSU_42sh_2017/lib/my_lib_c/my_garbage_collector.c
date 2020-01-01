/*
** EPITECH PROJECT, 2018
** my_garbage_collector
** File description:
** free every pointer allocated
*/

#include "my_lib_c.h"

typedef struct pile_s {
	void *address;
	struct pile_s *next;
} *pile_t;

pile_t new_pile(size_t size, pile_t pile)
{
	pile_t new_pile = malloc(sizeof(*new_pile));

	new_pile->address = malloc(size);
	new_pile->next = pile;
	return (new_pile);
}

void g_free(pile_t pile)
{
	pile_t temp = pile;

	for (int i = 0; pile; i += 1) {
		temp = pile;
		pile = pile->next;
		free(temp->address);
		free(temp);
	}
}

void *g_malloc(size_t size)
{
	static pile_t pile = NULL;

	pile = new_pile(size, pile);
	if (size == 0) {
		g_free(pile);
		return (NULL);
	}
	return (pile->address);
}
