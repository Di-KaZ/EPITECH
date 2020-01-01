/*
** EPITECH PROJECT, 2018
** linker
** File description:
** linker
*/

#include "my_lib_c.h"

int print_int (va_list args)
{
	return (my_putnbr(va_arg(args, int)));
}

int print_string (va_list args)
{
	return (my_putstr(va_arg(args, char*)));
}

int print_char (va_list args)
{
	my_putchar(va_arg(args, int));
	return (1);
}

int print_percent (va_list args)
{
	if (args)
		my_putchar('%');
	return (1);
}
