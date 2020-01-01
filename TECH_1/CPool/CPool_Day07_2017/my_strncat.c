/*
** EPITECH PROJECT, 2017
** my_strncat
** File description:
** copy a string into another till n
*/

char *my_strcat(char *dest, char const *src, int n) {
	int i = 0;
	int z = 0;

	while(dest[i] != '\0') {
		i += 1;
	}
	while(src[z] != '\0' && z < n) {
		dest[i] = src[z];
		n += 1;
		i += 1;
	}
	return(dest);

}
