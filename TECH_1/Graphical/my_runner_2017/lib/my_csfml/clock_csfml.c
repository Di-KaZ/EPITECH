/*
** EPITECH PROJECT, 2017
** 
** File description:
** 
*/

#include "my_csfml.h"

float get_elapsed_time (clocks_t *clock)
{
	float second;

	clock->time = sfClock_getElapsedTime(clock->clock);
	second = clock->time.microseconds / 1000000.0;
	return(second);
}
