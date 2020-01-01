/*
** EPITECH PROJECT, 2017
** 
** File description:
** 
*/

#include "my_sokoban.h"

int check_map (char **map)
{
	int box_number = 0;
	int mark_number = 0;

	for (int i = 0; map[i] != NULL; i += 1) {
		for (int j = 0; map[i][j] != '\0'; j += 1) {
			if (!PRINTABLE(map[i][j]))
				return (-1);
			if (map[i][j] == 'X')
				box_number += 1;
			if (map[i][j] == 'O')
				mark_number += 1;
		}
	}
	if (box_number != mark_number || box_number == 0 || mark_number == 0)
		return (-1);
	return (0);
}

void my_put_exit (char *message, int len, int re_val)
{
	write(1, message, len);
	exit(re_val);
}
