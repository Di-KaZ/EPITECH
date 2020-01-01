/*
** EPITECH PROJECT, 2018
** 
** File description:
** 
*/

#include "mysh.h"

char *add_str (const char *str1, const char *str2)
{
	int len = my_strlen(str1) + my_strlen(str2) + 2;
	char *add_str = malloc(sizeof(char) * len);
	int pos = 0;

	for (pos = 0; str1[pos] != '\0'; pos += 1) {
		add_str[pos] = str1[pos];
	}
	add_str[pos++] = '/';
	for (int i = 0; str2[i] != '\0'; pos += 1, i += 1) {
		add_str[pos] = str2[i];
	}
	add_str[pos] = '\0';
	return (add_str);
}
