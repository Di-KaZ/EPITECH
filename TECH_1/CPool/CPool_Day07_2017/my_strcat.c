/*
** EPITECH PROJECT, 2017
** my_strcat
** File description:
** copy a string into another
*/

char *my_strcat(char *dest, char const *src) {
	int i = 0;
	int n = 0;

	while(dest[i] != '\0') {
		i += 1;
	}
	while(src[n] != '\0') {
		dest[i] = src[n];
		n += 1;
		i += 1;
	}
	return(dest);

}
