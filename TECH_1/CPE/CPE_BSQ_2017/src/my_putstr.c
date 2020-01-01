/*
** EPITECH PROJECT, 2017
** my_putstr
** File description:
** put a string
*/

#include "bsq.h"

int my_putstr(const char *str)
{
	int len = my_strlen(str);

	if(write(1, str, len) < 0)
		return(0);
	return(len);
}

