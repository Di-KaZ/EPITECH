/*
** EPITECH PROJECT, 2017
** my_strlen
** File description:
** return len of a string
*/

int my_strlen (const char *str)
{
	int len = 0;

	if(!str)
		return(0);
	while(str[len] != '\0') {
		len += 1;
	}
	return(len);
}
