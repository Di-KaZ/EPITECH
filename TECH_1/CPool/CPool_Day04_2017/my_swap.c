/*
** EPITECH PROJECT, 2017
** my_switch
** File description:
** swap value of two integrers
*/

void my_swap (int *a, int *b) {

	int swaper;
	swaper = *a;
	*a = *b;
	*b = swaper;
	my_putchar(*a+48);
	my_putchar(*b+48);
}
