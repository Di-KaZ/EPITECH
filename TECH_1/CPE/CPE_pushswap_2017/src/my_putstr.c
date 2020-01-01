/*
** EPITECH PROJECT, 2017
** 
** File description:
** 
*/

#include <unistd.h>
#include "pushswap.h"

int my_putstr (const char *str)
{
	int len = my_strlen(str);

	if(write(1, str, len) < 0)
		return(0);
	return(len);
}

