/*
** EPITECH PROJECT, 2017
** algorithm using p
** File description:
** print till i the possibilities of making this palindrome
*/

#include "palindrome.h"

int active_imin_flag(palindrome_t *palindrome, int iteration)
{
	if (palindrome->flags & imin_flag &&
		iteration < palindrome->imin) {
		return (0);
	}
	return (1);
}

int active_imax_flag(palindrome_t *palindrome, int iteration)
{
	if (!(palindrome->flags & imax_flag))
		return (0);
	if (iteration > palindrome->imax) {
		return (2);
	}
	return (0);
}

char *itos(int nb)
{
	char *nb_char = NULL;
	int temp = nb;
	int size = 0;

	for (; temp > 0; size += 1)
		temp /= 10;
	if (!(nb_char = malloc(sizeof(char) * (size + 1)))) {
		printf("[ERROR] malloc.\n");
		exit(84);
	}
	sprintf(nb_char, "%d", nb);
	return (nb_char);
}

void algorithm_using_p(palindrome_t *p)
{
	char *to_go = convert_in_base(atoi(p->to_find), p->base);
	char *rev = my_revstr(to_go);

	if (strcmp(to_go, rev) != 0) {
		free(to_go);
		free(rev);
		printf("[ERROR] : -p must be a palindrome.\n");
		exit(84);
	}
	for (int i = 2; i <= atoi(to_go) + 1; i += 1) {
		algorithm(p);
		free(p->start);
		p->start = itos(i);
	}
	free(to_go);
	free(rev);
}
