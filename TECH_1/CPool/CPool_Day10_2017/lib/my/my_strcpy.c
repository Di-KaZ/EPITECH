/*
 ** EPITECH PROJECT, 2017
 ** my_strcpy
 ** File description:
 ** copy a string into another
 */

char *my_strcpy(char *dest, char const *src) {
	int i;
	for(i = 0; i != '\0'; i += 1)
		dest[i] = src[i];
	dest[i] = '\0';
	return(dest);
}

