/*
** EPITECH PROJECT, 2018
** converter of base
** File description:
** convert into a base
*/

#include "palindrome.h"

int sizeof_res(int nb, int base)
{
	int i = 0;

	for (; nb > 0; i += 1)
		if (nb != 0)
			nb /= base;
	return (i);
}

int revert_in_decimal(char *nb, int base)
{
	int len = strlen(nb);
	int power = 1;
	int res = 0;

	for (int i = len - 1; i >= 0; i -= 1) {
		if (!(nb[i] >= '0' && nb[i] <= '9') &&
			(int)(nb[i] - '0') >= base) {
			printf("[ERROR] : convertion.\n");
			exit(84);
		}
		res += (nb[i] - '0') * power;
		power *= base;
	}
	return (res);
}

char *convert_in_base(int nb, int base)
{
	char *res = malloc(sizeof(char) * (sizeof_res(nb, base) + 1));
	char *real_res = NULL;
	int i = 0;

	while (nb > 0) {
		res[i] = nb % base + '0';
		nb /= base;
		i += 1;
	}
	res[i] = '\0';
	real_res = my_revstr(res);
	free(res);
	return (real_res);
}
