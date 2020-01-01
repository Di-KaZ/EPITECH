/*
** EPITECH PROJECT, 2018
** 6
** File description:
** 4
*/

#include "matchstick.h"

void too_much_sticks (int max_stick)
{
	my_putstr("Error: you cannot remove more than ");
	my_putnbr(max_stick);
	my_putstr(" matches per turn\n");
}
