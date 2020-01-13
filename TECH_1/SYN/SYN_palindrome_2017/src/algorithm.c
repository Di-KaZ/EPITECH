/*
** EPITECH PROJECT, 2017
** algorithm  solo
** File description:
** algorithm for -n
*/

#include "palindrome.h"

char *my_revstr(char *str)
{
	int len = strlen(str);
	char *rev = malloc(sizeof(char) * (len + 1));
	int i = 0;

	if (!rev) {
		printf("[ERROR] malloc.\n");
		exit(84);
	}
	len -= 1;
	for (i = 0; len >= 0; i += 1, len -= 1)
		rev[i] = str[len];
	rev[i] = '\0';
	return (rev);
}

char *add_n_transform(char *to_find, char *rev, char *to_free)
{
	int sum = atoi(to_find) + atoi(rev);
	int temp = sum;
	int size = 0;
	char *sum_char = NULL;

	if (to_free)
		free(to_free);
	for (; temp > 0;  size += 1)
		temp /= 10;
	if (!(sum_char = malloc(sizeof(char) * (size + 1)))) {
		printf("[ERROR] malloc\n.");
		exit(84);
	}
	sprintf(sum_char, "%d", sum);
	return (sum_char);
}

static void child_algorithm(char **find, char **to_find, char **rev)
{
	*find = add_n_transform(*to_find, *rev,
				*find);
	free(*rev);
	*to_find = *find;
	*rev = *find;
	*rev = my_revstr(*rev);

}

void algorithm_solo(palindrome_t *p)
{
	char *find = convert_in_base(atoi(p->to_find), p->base);
	char *temp = strdup(p->to_find);
	int i = 0;

	p->to_find = convert_in_base(atoi(p->to_find), p->base);
	p->rev = my_revstr(find);
	for (i = 0; strcmp(p->to_find, p->rev) != 0 ||
		active_imax_flag(p, i) ||
		!active_imin_flag(p, i); i += 1) {
		child_algorithm(&find, &p->to_find, &p->rev);
		if (is_overflowing(find))
			break;
	}
	if (active_imax_flag(p, i) || is_overflowing(find)) {
		printf("no solution\n");
		exit(0);
	}
	printf("%s leads to %d in %d iteration(s) in base %d\n",
			temp, revert_in_decimal(find, p->base), i, p->base);
	exit(0);
}
