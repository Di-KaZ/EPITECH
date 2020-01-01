/*
** EPITECH PROJECT, 2017
** my_strcpy
** File description:
** cpy a string into another
*/

int *my_strcpy (char *dest, char const *src) {
	int i = 0;
	while (src[i] != '\0') {
		src[i] = dest[i];
		i = i + 1;
	}
	src[i] = '\0';
	return (dest);
}
