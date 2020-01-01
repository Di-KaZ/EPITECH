/*
** EPITECH PROJECT, 2018
** 1
** File description:
** 4
*/

#include "matchstick.h"
#include "get_next_line.h"

static int manage_line (int line_nb)
{
	int nb = random() % line_nb + 1;

	if(nb == 0)
		nb = 1;
	if (!(nb > 0 && nb <= line_nb)) {
		return (-1);
	}
	return (nb);
}

static int manage_match (char *board_line, int max_stick)
{
	int nb = random() % (max_stick + 1 - 1) + 1;

	if (nb == 0 || max_stick == 1)
		return (1);
	if (can_remove_match(board_line, nb, max_stick))
		return (-1);
	return (nb);
}

int ai_turn (char **board, int line_nb, int max_stick)
{
	int nb_l = 0;
	int nb_m = 0;

	if ((nb_l = manage_line(line_nb)) < 1)
		return (0);
	if ((nb_m = manage_match(board[nb_l], max_stick)) < 1)
		return (0);
	board = remove_match(board, nb_l, nb_m);
	my_putstr("AI removed ");
	my_putnbr(nb_m);
	my_putstr(" match(es) from line ");
	my_putnbr(nb_l);
	my_putchar('\n');
	return (1);
}
