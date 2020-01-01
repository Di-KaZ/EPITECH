/*
** EPITECH PROJECT, 2018
** 
** File description:
** 
*/

#include "mysh.h"

void manage_signal (int sig)
{
	(void)sig;
	my_putchar('\n');
	disp_prompt(0, NULL);
}
