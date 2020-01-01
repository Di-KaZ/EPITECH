/*
** EPITECH PROJECT, 2018
** parse_commands.c
** File description:
** Parsing and putin tab.
*/

#include "mysh.h"

char *symbols[] = {"|", "<", ">", NULL};

int count_number_of_command(char **command_tab)
{
	int command_num = 1;

	for (int i = 0; command_tab[i]; i += 1) {
		for (int j = 0; symbols[j]; j += 1) {
			if (my_strcmp(command_tab[i], symbols[j]) == 0)
				command_num += 1;
			if (my_strcmp(command_tab[i], ";") == 0)
				command_num += 1;
		}
	}
	return (command_num);
}

int count_number_of_arg(char **command_tab, int *pos)
{
	int number_arg = 0;

	for (; command_tab[*pos]; *pos += 1) {
		for (int j = 0; symbols[j]; j += 1)
			if (my_strcmp(command_tab[*pos], symbols[j]) == 0) {
				*pos += 1;
				return(number_arg + 1);
			}
			else if (my_strcmp(command_tab[*pos], ";") == 0) {
				*pos += 1;
				return(number_arg);
			}
		number_arg += 1;
	}
	return (number_arg);
}

void damn_cs(char **command_tab, int *prev_pos)
{
	if (my_strcmp(command_tab[*prev_pos], ";") == 0)
		*prev_pos += 1;
}

char ***parse_command(char **command_tab)
{
	int pos = 0;
	int number_arg = 0;
	int j = 0;
	int i = 0;
	int prev_pos = 0;
	char ***parsed = malloc(sizeof(char **) * (count_number_of_command
							(command_tab) + 1));
	for (; command_tab[pos]; j += 1) {
		number_arg = count_number_of_arg(command_tab, &pos);
		parsed[j] = malloc(sizeof(char *) *
				(number_arg + 1));
		for (i = 0; i != number_arg; i += 1, prev_pos += 1) {
			damn_cs(command_tab, &prev_pos);
			parsed[j][i] = command_tab[prev_pos];
		}
		parsed[j][i] = NULL;
	}
	parsed[j] = NULL;
	return (parsed);
}
