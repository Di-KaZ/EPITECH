/*
** EPITECH PROJECT, 2018
** requirement
** File description:
** noice
*/

int my_factrec_synthesis(int nb)
{
	int stack = 0;

	if (nb < 0 || nb > 12)
		return (0);
	if (nb == 1 || nb == 0)
		return (1);
	stack = nb * my_factrec_synthesis(nb - 1);
	if (stack < 0)
		return (0);
	return (stack);
}

int my_squareroot_synthesis(int nb)
{
	int sqrt = 0;

	if (nb == 0)
		return (0);
	if (nb < 0)
		return (-1);
	for (; sqrt * sqrt < nb; sqrt += 1);
	if (sqrt *sqrt == nb)
		return (sqrt);
	return (-1);
}
/*
int main (int ac, char **av)
{
	if (ac != 2)
		return (84);
	int nb = atoi(av[1]);
	printf("sqrt(%d) = %d\n", nb, my_squareroot_synthesis(nb));
}*/
