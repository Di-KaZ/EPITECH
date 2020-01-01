/*
** EPITECH PROJECT, 2018
** my_strcmp
** File description:
** compare two string
*/

#include "my_lib_c.h"

int my_strcmp (char const *str1, char const *str2)
{
	char c1 = '\0';
	char c2 = '\0';

	do {
		c1 = *str1;
		c2 = *str2;
		str1 += 1;
		str2 += 1;
		if (c1 == '\0')
			return (c1 - c2);
	} while (c1 == c2);
	return (c1 - c2);
}

static int same (char const *str, char const *to_find)
{
	if (my_strlen(str) < my_strlen(to_find))
		return (0);
	for (int i = 0; to_find[i]; i += 1)
		if (str[i] != to_find[i])
			return (0);
	return (1);
}

int my_strfind (char const *str, char const *to_find)
{
	for (int i = 0; str[i]; i += 1) {
		if (str[i] == *to_find)
			if (same (str + i, to_find))
				return (1);
	}
	return (0);
}
