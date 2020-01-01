/*
 ** EPITECH PROJECT, 2017
 ** my_pustr.c
 ** File description:
 ** print a string
 */

void my_putstr(char const *str) {
	int i;
	for(i = 0; str[i] != '\0'; i += 1)
		my_putchar(str[i]);
}

