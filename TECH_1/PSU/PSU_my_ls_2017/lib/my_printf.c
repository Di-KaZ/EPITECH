/*
** EPITECH PROJECT, 2017
** 
** File description:
** 
*/

#include <stdarg.h>
#include "my.h"

void oct_base (int c)
{
	if (c > 0) {
		oct_base(c / 8);
		my_put_nbr(c % 8);
	}
}

void put_oct (char *str) {
	while (*str != '\0') {
		if(*str < 32 || *str >= 127) {
			my_putchar('\\');
			oct_base(*str);
		}
		else {
			my_putchar(*str);
		}
		str += 1;
	}
}

char there_opt (char *str, char last_opt)
{
	if (last_opt == '%' && *str == '%')
		return(*(str + 1));
	if (*str == '%' && *(str - 1) != '%') {
		return(*(str + 1));
	}
	return ('\0');
}

int my_printf (char *str, ...)
{
	va_list args;
	char last_opt;
	char opt = '\0';

	va_start(args,str);
	if (!str) {
		my_putstr("formating string as to be valid.");
		return(84);
	}
	while (*str != '\0') {
		last_opt = opt;
		opt = there_opt(str, last_opt);
		if  (opt != '\0') {
			if (opt == 'd' || opt == 'i')
				my_put_nbr(va_arg(args,int));
			opt == 'c' ? my_putchar(va_arg(args,int)) : 0;
			opt == 's' ? my_putstr(va_arg(args,char*)) : 0;
			opt == 'S' ? put_oct(va_arg(args,char*)) : 0;
			opt == 'b' ? print_uint_bin(va_arg(args,unsigned int))
									  : 0;
			opt == '%' ? my_putchar('%') : 0;
			str += 2;
		}
		else {
			my_putchar(*str);
			str += 1;
		}
	}
	va_end(args);
	return(0);
}
