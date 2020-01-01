/*
** EPITECH PROJECT, 2018
** ergerg
** File description:
** rege
*/

#include "matchstick.h"
#include "get_next_line.h"

static int manage_line (int line_nb)
{
	char *gnl = NULL;
	int nb = 0;

	if ((gnl = get_next_line(0)) == NULL)
		return (-2);
	if (!is_str_num(gnl)) {
		my_putstr("Error: invalid input (positive number expected)\n");
		return (-1);
	}
	nb = my_getnbr(gnl);
	if (!(nb >= 1 && nb <= line_nb)) {
		my_putstr("Error: this line is out of range\n");
		return (-1);
	}
	return (nb);
}

static int manage_match (char *board_line, int max_stick)
{
	char *gnl = NULL;
	int nb = 0;

	if ((gnl = get_next_line(0)) == NULL)
		return (-2);
	if (!is_str_num(gnl)) {
		my_putstr("Error: invalid input (positive number expected)\n");
		return (-1);
	}
	nb = my_getnbr(gnl);
	if (nb == 0) {
		my_putstr("Error: you have to remove at least one match\n");
		return (-1);
	}
	if (nb > max_stick) {
		too_much_sticks(max_stick);
		return (-1);
	}
	if (can_remove_match(board_line, nb, max_stick)) {
		my_putstr("Error: not enough matches on this line\n");
		return (-1);
	}
	return (nb);
}

int player_turn (char **board, int line_nb, int max_stick)
{
	int nb_l = 0;
	int nb_m = 0;

	my_putstr("Line: ");
	if ((nb_l = manage_line(line_nb)) == -1)
		return (0);
	if (nb_l == -2)
		return (-2);
	my_putstr("Matches: ");
	if ((nb_m = manage_match(board[nb_l], max_stick)) == -1)
		return (0);
	if (nb_m == -2)
		return (-2);
	remove_match(board, nb_l, nb_m);
	my_putstr("Player removed ");
	my_putnbr(nb_m);
	my_putstr(" match(es) from line ");
	my_putnbr(nb_l);
	my_putchar('\n');
	return (1);
}
