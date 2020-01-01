/*
** EPITECH PROJECT, 2018
** manage_signal
** File description:
** respond to kill signal
*/

#include "mysh.h"

void manage_signal (int sig)
{
	(void)sig;
	my_putchar('\n');
	disp_prompt(0, NULL);
}
