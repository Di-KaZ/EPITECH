/*
** EPITECH PROJECT, 2018
** 
** File description:
** 
*/

#include "my_lib_c.h"

int my_strlen (const char *str)
{
	int len = 0;

	for (len = 0; str[len] != '\0'; len += 1);
	return (len);
}

int my_putchar (const int c)
{
	if (write(1, &c, 1) < 0)
		return (-1);
	return (c);
}

int my_putstr (const char *str)
{
	if (write(1, str, my_strlen(str)) < 0)
		return (-1);
	return (my_strlen(str));
}

void my_put_2d_char(const char **array)
{
	for (int i = 0; array[i]; i += 1) {
		my_putstr(array[i]);
		my_putchar('\n');
	}
}
