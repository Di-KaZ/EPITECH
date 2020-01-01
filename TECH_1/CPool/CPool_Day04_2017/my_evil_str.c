/*
** EPITECH PROJECT, 2017
** my_evil_str
** File description:
** swap the caracter of a string
*/
char *my_evil_str(char *str) {
	int str_len = my_strlen(&str);
	int max = str_len;
	int min = 0;
	char swap;
	while (min < str_len) {
		swap = str[max];
		str[max] = str[min];
		str[min] = swap;
		max = max - 1;
		min = min + 1;
	}
	return (str);
}
