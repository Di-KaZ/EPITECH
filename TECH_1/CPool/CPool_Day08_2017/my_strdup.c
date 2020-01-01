/*
** EPITECH PROJECT, 2017
** my_strdup
** File description:
** print a str of any size
*/
#include<stdlib.h>
char *my_strdup(char const *src) {
	char *str;
	int i;

	for(i = 0; i != '\0'; i += 1) {
	}
	str = malloc(sizeof(char) * (i + 1));
	for(i = 0; src[i] != '\0'; i += 1) {
		str[i] = src[i];
	}
	return(str);
}

