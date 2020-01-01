/*
** EPITECH PROJECT, 2017
** 
** File description:
** 
*/

#include "bsq.h"

int compare_value (int x, int y, int z)
{
	if (x <= y && x <= z)
		return (x + 1);
	if (y <= x && y <= z)
		return (y + 1);
	if (z <= x && z <= y)
		return (z + 1);
	return (666);
}
