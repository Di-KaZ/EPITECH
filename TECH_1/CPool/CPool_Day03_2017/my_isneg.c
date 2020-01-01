/*
** EPITECH PROJECT, 2017
** my_isneg
** File description:
** display if the number is positive or negative
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

