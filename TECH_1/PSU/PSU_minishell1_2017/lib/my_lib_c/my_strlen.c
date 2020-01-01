/*
** EPITECH PROJECT, 2017
** my_strlen
** File description:
** return the len of a string
*/

int my_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i]) {
		i = i + 1;
	}
	return (i);
}
