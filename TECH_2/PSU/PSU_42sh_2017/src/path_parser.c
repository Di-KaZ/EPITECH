/*
** EPITECH PROJECT, 2018
** path_parser
** File description:
** parse the path variable of the env
*/

#include "mysh.h"

int str_first_find (char *str, char *to_find)
{
	char c1 = '\0';
	char c2 = '\0';
	int i = 0;

	do {
		c1 = str[i];
		c2 = to_find[i];
		if (c2 == '\0')
			return (1);
		if (!c1 || c1 != c2)
			return (0);
		i += 1;
	} while (c2);
	return (1);
}

static int malloc_nb_word (const char *str)
{
	int word = 2;

	for (int i = 0; str[i] != '\0'; i += 1) {
		if (str[i] == ':')
			word += 1;
	}
	return (word);
}

static char *get_word (const char *str, int start, int end)
{
	char *word = malloc(sizeof(char) * (end - start + 2));
	int i = 0;

	for (i = 0; start < end; start += 1, i += 1) {
		word[i] = str[start];
	}
	word[i] = '/';
	word[i + 1] = '\0';
	return (word);
}

char **path_parser (const char *str)
{
	int pos = 0;
	int i = 0;
	int current_word = 0;
	char **tab = NULL;

	tab = malloc(sizeof(char *) * malloc_nb_word(str));
	for (i = 0; str[i] != '\0'; i += 1) {
		if (str[i] == ':') {
			tab[current_word] = get_word(str, pos, i);
			i += 1;
			pos = i;
			current_word += 1;
		}
	}
	tab[current_word] = get_word(str, pos, i);
	tab[current_word + 1] = NULL;
	return (tab);
}
