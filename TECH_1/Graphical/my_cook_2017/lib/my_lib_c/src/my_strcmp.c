/*
** EPITECH PROJECT, 2018
** 
** File description:
** 
*/

#include "my_lib_c.h"

int my_strcmp (char const *str1, char const *str2)
{
	if (my_strlen(str1) == my_strlen(str2)) {
		for (int i = 0; str1[i] != '\0'; i += 1) {
			if (str1[i] != str2[i])
				return (0);
		}
	}
	else
		return (0);
	return (1);
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
	if (!str || !to_find)
		return (0);
	for (int i = 0; str[i]; i += 1) {
		if (str[i] == *to_find)
			if (same (str + i, to_find))
				return (1);
	}
	return (0);
}
