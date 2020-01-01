/*
** EPITECH PROJECT, 2017
** 
** File description:
** 
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
