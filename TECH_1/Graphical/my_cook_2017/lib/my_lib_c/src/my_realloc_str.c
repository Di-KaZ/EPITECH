/*
** EPITECH PROJECT, 2018
** realloc
** File description:
** realloc
*/

#include "my_lib_c.h"

char *my_realloc_str (char *str, const char *to_alloc)
{
	char *result = malloc(sizeof(char) * (my_strlen(to_alloc) + 1));

	free(str);
	for (int i = 0; to_alloc[i]; i += 1)
		result[i] = to_alloc[i];
	result[my_strlen(to_alloc)] = '\0';
	return (result);
}
