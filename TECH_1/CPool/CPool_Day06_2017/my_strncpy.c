/*
** EPITECH PROJECT, 2017
** my_strncpy
** File description:
** copy n char of a strin into another
*/

int my_strncpy (char *dest, char const *src, int n) {
	int i = 0;
	while (i <= n) {
		src[i] = dest[i];
		i = i + 1;
	}
	return (dest);
}
