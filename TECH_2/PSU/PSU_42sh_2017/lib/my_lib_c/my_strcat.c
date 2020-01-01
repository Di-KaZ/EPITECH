/*
** EPITECH PROJECT, 2018
** my_strcat
** File description:
** concatenate two strings
*/

#include "my_lib_c.h"

char *my_strcat(char *str1, char *str2)
{
	char *res = malloc(sizeof(char) * (my_strlen(str1) + my_strlen(str2)
				+ 1));
	int pos = 0;

	for (int i = 0; str1[i]; i += 1, pos += 1)
		res[pos] = str1[i];
	for (int i = 0; str2[i]; i += 1, pos += 1)
		res[pos] = str2[i];
	res[pos] = '\0';
	return (res);
}
