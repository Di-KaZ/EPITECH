/*
 ** EPITECH PROJECT, 2017
 ** my_isneg
 ** File description: check if a number is negative or positive
 **
 */

int my_isneg(int n) {
	if (n < 0) {
		my_putchar('N');
	}
	else {
		my_putchar('P');
	}
	return (0);
}

