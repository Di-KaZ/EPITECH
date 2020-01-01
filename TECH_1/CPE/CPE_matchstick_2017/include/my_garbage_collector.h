/*
** EPITECH PROJECT, 2018
** 
** File description:
** 
*/

#ifndef _MY_GARBAGE_COLLECTOR_
#define _MY_GARBAGE_COLLECTOR_
#include <stdlib.h>
typedef struct pile_s {
	void *address;
	struct pile_s *next;
} *pile_t;
pile_t new_pile (size_t size, pile_t pile);
void *g_malloc (size_t size);
void g_free(pile_t pile);
#endif
