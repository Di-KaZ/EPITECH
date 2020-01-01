/*
** EPITECH PROJECT, 2018
** 4
** File description:
** 3
*/

#include "matchstick.h"

int can_remove_match (char *line, int nb_matches, int max_stick)
{
	int nb_found = 0;

	if (nb_matches > max_stick)
		return (1);
	for (int i = 0; line[i]; i += 1)
		if (line[i] == '|')
			nb_found += 1;
	if (nb_found >= nb_matches)
		return (0);
	return (1);
}

char **remove_match (char **board, int line, int nb)
{
	int i = my_strlen(board[line]);

	for (; i != 0 && nb != 0; i -= 1) {
		if (board[line][i] == '|') {
			board[line][i] = ' ';
			nb -= 1;
		}
	}
	return (board);
}

int check_win (char **board)
{
	for (int i = 0; board[i]; i += 1) {
		for (int j = 0; board[i][j]; j += 1) {
			if (board[i][j] == '|')
				return (0);
		}
	}
	return (1);
}

int is_str_num (const char *str)
{
	for (int i = 0; str[i]; i += 1) {
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (0);
	}
	return (1);
}
