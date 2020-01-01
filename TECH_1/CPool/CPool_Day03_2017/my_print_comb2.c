/*
** EPITECH PROJECT, 2017
** my_print_comb2
** File description:
** print 00 to 99
*/

int my_print_comb2(void) {
	int a = 0;
	int b = 0;
	while (a <= 9) {
		my_putchar(a+48);
		my_putchar(b+48);
		my_putchar('\n');
		if (b == 9) {
			a++;
		        b = 0;
		}
		else {
			b++;
		}
	}
}
