/*
** EPITECH PROJECT, 2017
** my_computer_factorial_it
** File description:
** return the factorial of a numer
*/

int my_compte_factorial_it(int nb) {
	int nb_fact = nb;
	int i = 1 ;
	if (nb = 0) {
		return 1;
	}
	else if (nb < 0) {
		return 0;
	}
	else {
		while (i <= nb) {
			nb_fact = nb_fact * i;
			i = i + 1;
		}
		return nb;
	}
}

