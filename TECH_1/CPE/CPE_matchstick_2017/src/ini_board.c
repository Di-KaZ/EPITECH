/*
** EPITECH PROJECT, 2018
** 4
** File description:
** 43
*/

#include "matchstick.h"

char *fill_str (char *str, char c, int size)
{
	for (int i = 0; i < size; i += 1) {
		str[i] = c;
	}
	str[size] = '\0';
	return (str);
}

char **do_triangle (char **board, int size)
{
	int temp = size;
	int y = 0;
	for (int i = 1; i <= size; i += 1) {
		for (int x = 1; x < temp; x += 1)
			y += 1;
		temp -= 1;
		for (int x = 1; x <= 2 * i - 1; x += 1)
			board[i][y + x] = '|';
		y = 0;
	}
	return (board);
}

char **ini_board (int size)
{
	char **board = g_malloc(sizeof(char*) * (size + 3));

	for (int i = 0; i < size + 3; i += 1)
		board[i] = g_malloc(sizeof(char) * (size * 2 + 2));
	board[0] = fill_str(board[0], '*', size * 2 + 1);
	board[size + 1] = fill_str(board[size + 1], '*', size * 2 + 1);
	for (int i = 1; i < size + 1; i += 1) {
		board[i] = fill_str(board[i], ' ', size * 2 + 1);
		board[i][0] = '*';
		board[i][size * 2] = '*';
	}
	board[size + 2] = NULL;
	do_triangle(board, size);
	return (board);
}

