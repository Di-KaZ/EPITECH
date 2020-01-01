/*
** EPITECH PROJECT, 2017
** my_rev_param
** File description:
** print in reverse order the parameters of a fonction
*/

int main(int argc, char **argv) {
	int n = argc - 1;
	while( n >= 0 ) {
		my_putstr(argv[n]);
		my_putchar('\n');
		n -= 1;
	}
	return(0);
}
