/*
** EPITECH PROJECT, 2018
** 
** File description:
** 
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

static int malloc_nb_word (const char *str)
{
	int word = 2;

	for (int i = 0; str[i] != '\0'; i += 1) {
		if (str[i] == ' ')
			word += 1;
	}
	return (word);
}

static char *get_word (const char *str, int start, int end)
{
	char *word = malloc(sizeof(char) * (end - start + 1));
	int i = 0;

	for (i = 0; start < end; start += 1, i += 1) {
		word[i] = str[start];
	}
	word[i] = '\0';
	return (word);
}

char **my_str_to_word_array (const char *str)
{
	int pos = 0;
	int i = 0;
	int current_word = 0;
	char **tab = NULL;

	if (!str)
		return (NULL);
	tab = malloc(sizeof(char*) * malloc_nb_word(str));
	for (i = 0; str[i] != '\0'; i += 1) {
		if (str[i] == ' ') {
			tab[current_word] = get_word(str, pos, i);
			i += 1;
			pos = i;
			current_word += 1;
		}
	}
	tab[current_word] = get_word(str, pos, i);
	tab[current_word + 1] = NULL;
	return(tab);
}
