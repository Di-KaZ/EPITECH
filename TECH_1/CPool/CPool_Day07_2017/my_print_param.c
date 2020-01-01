/*
** EPITECH PROJECT, 2017
** my_print_param
** File description:
** print parameters of the main fonction
*/

int main(int argc, char **argv) {
	int n = 0;

	while( n < argc ) {
		my_putstr(argv[n]);
		my_putchar('\n');
		n += 1;
	}
	return(0)
}
