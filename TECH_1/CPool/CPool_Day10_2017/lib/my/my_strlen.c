/*
 ** EPITECH PROJECT, 2017
 ** my_strlen
 ** File description:
 ** return size of a str
 */

int my_strlen(const char *str) {
	int i;
	while(str[i] != '\0') {
		i += 1;
	}
	return (i);
}

