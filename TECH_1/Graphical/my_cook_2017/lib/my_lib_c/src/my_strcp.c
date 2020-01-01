/*
** EPITECH PROJECT, 2018
** strcp
** File description:
** strcp
*/

#include "my_lib_c.h"

char * my_strcp (const char *str)
{
	int i = 0;
	char *cpy = malloc(sizeof(char) * (my_strlen(str) + 1));

	for (i = 0; str[i]; i += 1)
		cpy[i] = str[i];
	cpy[i] = '\0';
	return (cpy);
}
