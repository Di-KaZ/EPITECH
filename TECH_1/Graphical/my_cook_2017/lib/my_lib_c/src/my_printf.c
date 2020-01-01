/*
** EPITECH PROJECT, 2018
** my_printf
** File description:
** my_printf
*/

#include "my_lib_c.h"

const char opts[6] =
{
	'd',
	'i',
	's',
	'c',
	'%',
	'\0'
};

int (*printing_func[4]) (va_list) =
{
	print_int,
	print_int,
	print_string,
	print_char
};

int mini_printf (char *format, va_list args)
{
	int len = 0;

	for (int i = 0; format[i]; i += 1) {
		for (int j = 0; opts[j] && format[i] == '%'; j += 1) {
			if (format[i + 1] == opts[j]) {
				len += printing_func[j](args);
				i += 2;
			}
		}
		if (format[i] != '%') {
			len += 1;
			my_putchar(format[i]);
		}
	}
	return (len);
}

int my_printf (char *format, ...)
{
	int len = 0;
	va_list arg;
	va_start (arg, format);
	len = mini_printf(format, arg);
	va_end (arg);
	return (len);
}
