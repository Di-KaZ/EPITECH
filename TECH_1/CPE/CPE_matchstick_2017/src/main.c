/*
** EPITECH PROJECT, 2018
** 
** File description:
** 
*/

#include "matchstick.h"

int load_error (int ac, char **av)
{
	srandom(getpid());
	if (ac != 3) {
		my_putstr("Usage :\n\t./matchstick [lines number]");
		my_putstr(" [removable stick per round]\n");
		return (1);
	}
	if (!is_str_num (av[1]) || (!(my_getnbr(av[1]) > 1 &&
				      my_getnbr(av[1]) < 100))) {
		my_putstr("Too big map\n");
		return (1);
	}
	if (!is_str_num(av[2]) || my_getnbr(av[2]) <= 0) {
		my_putstr("Minimal: one removable matchstick per round\n");
		return (1);
	}
	return (0);
}

int main (int ac, char **av)
{
	char **board = NULL;
	int size = 0;
	int val = 0;

	if (load_error(ac ,av))
		return (84);
	size = my_getnbr(av[1]);
	board = ini_board(size);
	while ("True") {
		my_put_2d_array(board);
		my_putstr("\nYour turn:\n");
		while ((val = player_turn(board, size, my_getnbr(av[2]))) == 0);
		if (val == -2)
			return (0);
		if ((check_win(board) ? ai_win(board) : 0))
			return (2);
		my_put_2d_array(board);
		my_putstr("\nAI's turn...\n");
		while (ai_turn(board, size, my_getnbr(av[2])) == 0);
		if ((check_win(board) ? player_win(board) : 0))
			return (1);
	}
	return (0);
}
