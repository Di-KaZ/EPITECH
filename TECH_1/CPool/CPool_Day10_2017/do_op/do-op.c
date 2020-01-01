/*
** EPITECH PROJECT, 2017
** do-op
** File description:
** do simple operation
*/
#include"../include/my.h"
int do_calc(int a, int b, char const *op) {
	if(*op == '+')
		return(a + b);
	if(*op == '-')
		return(a - b);
	if(*op == '/')
		return(a / b);
	if(*op == '%')
		return(a % b);
}

int iserror(char const *op, int nb2) {
	if(*op != '+' && *op != '-' && *op != '/' && *op != '%') {
		my_putstr("0\n");
		return(84);
	}
	if((*op == '%') && nb2 == 0) {
		my_putstr("Stop: modulo by zero\n");
		return(84);
	}

	if((*op == '/') && nb2 == 0) {
		my_putstr("Stop: division by zero\n");
		return(84);
	}
	return(0);
}

int main(int av, char **ac) {
	int nb1;
	int nb2;
	char *op;
	int result;

	if(av < 4 || av > 4) {
		return(84);
	}
	nb1 = my_get_nbr(ac[1]);
	nb2 = my_get_nbr(ac[3]);
	op = ac[2];;
	if(iserror(op, nb2) == 84) {
		return(84);
	}
	result = do_calc(nb1, nb2, op);
	my_put_nbr(result);
	my_putchar('\n');
	return(0);
}
