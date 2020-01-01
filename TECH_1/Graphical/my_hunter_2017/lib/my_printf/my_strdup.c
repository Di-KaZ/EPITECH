/*
** EPITECH PROJECT, 2017
** 
** File description:
** 
*/

#include "my.h"

char *my_strdup (const char *s)
{
	int i;
	char *ptdr = malloc(sizeof(*ptdr) * (my_strlen(s) + 1));

	if (!s)
		return("\0");
	for (i = 0; s[i] != '\0'; i += 1)
		ptdr[i] = s[i];
	ptdr[i] = '\0';
	return (ptdr);
}
