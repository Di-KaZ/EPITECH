/*
 ** EPITECH PROJECT, 2017
 ** my_strncpy
 ** File description:
 ** cpoy a string into another till n
 */

char my_strncpy(char *dest, char const *src, int n) {
	int i;
	for(i = 0; i != '\0' && i <= n; i += 1)
		dest[i] = src[i];
	return(*dest);
}
