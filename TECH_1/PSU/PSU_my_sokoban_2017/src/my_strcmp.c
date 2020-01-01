/*
** EPITECH PROJECT, 2017
** 
** File description:
** 
*/

int my_strcmp (char *str1, char* str2)
{
	for (int i = 0; str1[i] != '\0'; i += 1)
		if (str1[i] != str2[i])
			return (0);
	return (1);
}
