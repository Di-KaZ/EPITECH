/*
** EPITECH PROJECT, 2018
** disp_prompt
** File description:
** display the prompt of the shell
*/
#include "mysh.h"

void disp_prompt (int ac, char **av)
{
	char buffer[1000];
	(void)ac;
	(void)av;

	getcwd(buffer, 1000);
	my_putstr("\x1b[31m");
	my_putchar('[');
	my_putstr(buffer);
	my_putchar(']');
	my_putstr("\x1b[32m""$ ""\x1b[0m");
}

int ok_checker (const char *path)
{
	if (open(path, S_IXUSR) == -1)
		return (0);
	return (1);
}
