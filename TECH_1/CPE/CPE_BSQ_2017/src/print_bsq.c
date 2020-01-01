/*
** EPITECH PROJECT, 2017
** 
** File description:
** 
*/

#include "bsq.h"

void print_bsq (char **star)
{
	for (int i = 0; star[i] != NULL; i += 1) {
		if (columns_special(star, i) == 1 ||
		    line_special(star) == 1)
			return;
		my_putstr(star[i]);
		my_putchar('\n');
	}
}

int columns_special (char **star, int i)
{
	int return_val = 0;

	if (star[i][0] == '.' && star[i][1] == '\0') {
		return_val = 1;
		my_putstr("x\n");
		for (;star[i + 1] != NULL; i += 1) {
			my_putstr(star[i + 1]);
			my_putchar('\n');
		}
	}
	return(return_val);
}

int line_special (char **star)
{
	int return_val = 0;
	int i = 0;

	if (star[1] == NULL) {
		return_val = 1;
		while (star[0][i] != '\0') {
			if (star[0][i] == '.') {
				my_putchar('x');
				break;
			}
			else
				my_putchar(star[0][i]);
			i += 1;
		}
		for (i += 1; star[0][i] != '\0'; i += 1) {
			my_putchar(star[0][i]);
		}
		my_putchar('\n');
	}
	return (return_val);
}
