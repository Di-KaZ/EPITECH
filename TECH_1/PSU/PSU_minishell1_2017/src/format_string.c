/*
** EPITECH PROJECT, 2018
** format_string
** File description:
** format_string
*/

#include "mysh.h"

int skip_tab_space (char *str, int *i)
{
	int return_val = 0;
	int j = 0;

	for (j = *i; str[j] && (str[j] == ' ' || str[j] == '\t'); j += 1) {
		return_val = 1;
		*i += 1;
	}
	return (return_val);
}

char *format_string (char *str)
{
	int len = 0;
	char *cleaned = NULL;
	int j = 0;
	int i = 0;

	if (!str)
		return (NULL);
	len = my_strlen(str) + 1;
	cleaned = malloc(sizeof(char) * len);
	skip_tab_space(str, &i);
	for (; i < len && str[i]; i += 1) {
		if (skip_tab_space(str, &i)) {
			cleaned[j++] = ' ';
			cleaned[j++] = str[i];
		}
		else
			cleaned[j++] = str[i];
	}
	cleaned[j] = '\0';
	free(str);
	return (cleaned);
}

void nothing (char **mdr, env_t *lol)
{
	(void)mdr;
	(void)lol;
}
