/*
** EPITECH PROJECT, 2017
** my_putstr
** File description:
** display character of a string
*/
int my_putstr( char const *str) {
	int i;
	i = 0;
	while (str[i] != '\0') {
		my_putchar(str[i]);
		i = i + 1;
		}
}

