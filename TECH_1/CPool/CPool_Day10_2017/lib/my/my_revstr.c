/*
 ** EPITECH PROJECT, 2017
 ** my_revstr
 ** File description:
 ** printf a string  in reverse order
 */

char my_revstr(char *str) {
	int strlen = (my_strlen(str)-1);
	char temp;
	int i;
	for(i = 0; i <= strlen; i += 1) {
		temp = str[i];
		str[strlen] = str[i];
		str[i] = temp;
		strlen -= 1;
	}
	return(*str);
}

