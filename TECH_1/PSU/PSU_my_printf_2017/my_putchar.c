/*
** EPITECH PROJECT, 2017
** my_putchar
** File description:
** print a char
*/

#include <unistd.h>

int my_putchar (int c)
{
    if(write(1, &c, 1) < 0);
	return('\0');
    return(c);
}
