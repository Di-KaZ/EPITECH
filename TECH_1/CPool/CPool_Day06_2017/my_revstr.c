/*
** EPITECH PROJECT, 2017
** my_revstr
** File description:
** reverse a string
*/

int my_revstr (char *str) {
	char temp;
	int i = 0;
	int max;
	int strlen;
	while (str[i] != '\0') {
		i = i + 1;
	}
	strlen = i - 1;
	max = strlen;
	i = 0;
	while (i <= max) {
		temp = str[max];
		str[max] = str[i];
		str[i] = temp;
		max = max - 1;
		i = i + 1;
	}
	return (str);
}
