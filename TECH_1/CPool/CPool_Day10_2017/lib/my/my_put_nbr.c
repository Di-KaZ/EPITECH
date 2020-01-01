/*
 * EPITECH PROJECT, 2017
 ** my_put_nbr
 ** File description:
 ** print a number
 */

int my_put_nbr(int nb) {
	int last_nb;

	if (nb < 0) {
		my_putchar('-');
		nb = nb * (-1);
	}
	if (nb >= 0) {
		if (nb >= 10) {
			last_nb = (nb % 10);
			nb = (nb - last_nb) / 10;
			my_put_nbr(nb);
			my_putchar(48 + last_nb);
		}
		else
			my_putchar(48 + nb % 10);
	}
}
