/*
** EPITECH PROJECT, 2017
** algorithm p
** File description:
** algo for -p
*/

#include "palindrome.h"

int is_overflowing(char *nb)
{
	if (strlen(nb) >= 10)
		return (1);
	if (atoi(nb) < 0)
		return (1);
	return (0);
}

int algorithm(palindrome_t *p)
{
	char *find = strdup(p->start);
	int i = 0;

	p->rev = convert_in_base(atoi(my_revstr(p->start)), p->base);
	p->to_find = convert_in_base(atoi(p->to_find), p->base);
	for (i = 0; strcmp(p->to_find, p->rev) != 0 ||
		!active_imin_flag(p, i) ||
		active_imax_flag(p, i);  i += 1) {
		find = add_n_transform(find, p->rev, find);
		free(p->rev);
		p->rev = my_revstr(find);
		if (is_overflowing(find) || atoi(find) > atoi(p->to_find))
			return (0);
	}
	if (active_imax_flag(p, i) == 2 || !active_imin_flag(p, i)) {
		return (0);
	}
	printf("%s leads to %s in %d iteration(s) in base %d\n",
			p->start, p->rev, i, p->base);
	return (1);
}
