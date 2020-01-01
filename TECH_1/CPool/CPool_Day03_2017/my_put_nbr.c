/*
** EPITECH PROJECT, 2017
** my_put_nbr
** File description:
** for every value of a int it display it
*/	
int my_put_nbr(int nb) {

	int b = nb;
	int c;
	while ( b != 0) {
		c = b;
		b = b / 10;
	}
	my_putchar(c + 48);
	return (0);
}

