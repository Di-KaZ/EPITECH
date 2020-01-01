/*
** EPITECH PROJECT, 2018
** my_strcpy
** File description:
** copy a string
*/

#include "my_lib_c.h"

char *my_strcpy(const char *str)
{
	int i = 0;
	char *cpy = malloc(sizeof(char) * (my_strlen(str) + 1));

	for (i = 0; str[i]; i += 1)
		cpy[i] = str[i];
	cpy[i] = '\0';
	return (cpy);
}
