/*
** EPITECH PROJECT, 2017
** struct filler
** File description:
** fill the struct on palindrome using flags
*/

#include "palindrome.h"

void flag_n(char *args, palindrome_t *palindrome)
{
	if (!args || !is_str_num(args) || is_overflowing(args)) {
		printf("[ERROR] : number must be integer > 0.\n");
		exit(84);
	}
	palindrome->flags |= n_flag;
	palindrome->to_find = strdup(args);
	palindrome->start = strdup(args);
}

void flag_p(char *args, palindrome_t *palindrome)
{
	if (!args || !is_str_num(args) || is_overflowing(args)) {
		printf("[ERROR] : number must be integer > 0.\n");
		exit(84);
	}
	palindrome->flags |= p_flag;
	palindrome->to_find = strdup(args);
	palindrome->start = strdup("1");
}

void flag_b(char *args, palindrome_t *palindrome)
{
	if (!args || !is_str_num(args) || atoi(args) > 10 || atoi(args) < 1) {
		printf("[ERROR] : base must be integer > 1 && <= 10.\n");
		exit(84);
	}
	palindrome->flags |= b_flag;
	palindrome->base = atoi(args);
}

void flag_imin(char *args, palindrome_t *palindrome)
{
	if (!args || !is_str_num(args) || is_overflowing(args)) {
		printf("[ERROR] : imin must be integer > 0.\n");
		exit(84);
	}
	if (palindrome->imin > palindrome->imax)
		exit(84);
	palindrome->flags |= imin_flag;
	palindrome->imin = atoi(args);
}

void flag_imax(char *args, palindrome_t *palindrome)
{
	if (!args || !is_str_num(args) || is_overflowing(args)) {
		printf("[ERROR] : imax must be integer > 0.\n");
		exit(84);
	}
	if (palindrome->imin > palindrome->imax)
		exit(84);
	palindrome->flags |= imax_flag;
	palindrome->imax = atoi(args);
}
