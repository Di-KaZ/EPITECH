/*
** EPITECH PROJECT, 2018
** main
** File description:
** palindrome of number
*/

#include "palindrome.h"

const char *flags[] =
{
	"-h",
	"-n",
	"-p",
	"-b",
	"-imin",
	"-imax",
	NULL
};

static void (*fill_struct[])(char *arg, palindrome_t *palindrome) =
{
	flag_h,
	flag_n,
	flag_p,
	flag_b,
	flag_imin,
	flag_imax
};

palindrome_t *initialize_palindrome(void)
{
	palindrome_t *palindrome = malloc(sizeof(palindrome_t));

	if (!palindrome) {
		printf("[ERROR] : malloc.\n");
		exit(84);
	}
	palindrome->base = 10;
	palindrome->flags = 0;
	palindrome->imax = 0;
	palindrome->imin = 0;
	palindrome->rev = NULL;
	return (palindrome);
}

void flag_h(__attribute__((unused))char *arg ,
		__attribute__((unused))palindrome_t *palindrome)
{
	printf("USAGE\n\t"
		" -n number -p palindrome"
		"[-b base] [-imin i] [-imax i]\n\n"
		"DESCRIPTION\n"
		"\t-n n\tinteger to be transformed (>=0)\n"
		"\t-p pal\tpalindromic number to be obtained "
		"(incompatible with the -n option) (>=0)\n"
		"\t\tif defined, all fitting values of n will be output\n"
		"\t-b base\tbase in which the procedure will be executed "
		"(i<b<=10) [def: 10]\n"
		"\t-imin i\tminimum number of iterations, included (>=0) "
		"[def: 0]\n"
		"\t-imax i\tmaximum number of iterations, included (>=0) "
		"[def: 100]\n");
	exit(0);
}

void check_next_opt(char *next_arg)
{
	if (!next_arg)
		return;
	for (int i = 0; flags[i]; i += 1) {
		if (strcmp(next_arg, flags[i]) == 0)
			return;
	}
	printf("invalid argument\n");
	exit(84);
}

palindrome_t *create_palindrome(int ac, char **av)
{
	palindrome_t *palindrome = initialize_palindrome();
	if (ac == 1)
		exit(0);
	for (int i = 0; av[i]; i += 1)
		for (int j = 0; flags[j]; j += 1)
			if (strcmp(av[i], flags[j]) == 0) {
				fill_struct[j](av[i + 1], palindrome);
				check_next_opt(av[i + 1] ? av[i + 2] : NULL);
			}
	if (!palindrome || ((palindrome->flags & n_flag) &&
				(palindrome->flags & p_flag))) {
		printf("[ERROR] : you can't use -n and -p at the same time.\n");
		exit(84);
	}
	if (!(palindrome->flags & n_flag) && !(palindrome->flags & p_flag)) {
		printf("[ERROR] : you have to chose at least -n or -p flag.\n");
		exit (84);
	}
	return (palindrome);
}

int main (int ac, char **av)
{
	palindrome_t *palindrome = create_palindrome(ac, av);
	if (palindrome->flags & p_flag) {
		algorithm_using_p(palindrome);
		return (0);
	}
	if (palindrome->flags & n_flag) {
		algorithm_solo(palindrome);
		return (0);
	}
}
