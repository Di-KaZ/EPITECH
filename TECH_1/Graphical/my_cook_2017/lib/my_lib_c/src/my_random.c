/*
** EPITECH PROJECT, 2018
** random
** File description:
** random
*/

#include "my_lib_c.h"

int my_random (void)
{
	int fd = open("/dev/urandom", O_RDONLY);
	char buffer[100];
	int i = 100;
	if (fd == - 1)
		return (-1);
	while (i == 100) {
		read(fd, buffer, 100);
		for (i = 0; i != 100; i += 1) {
			if (IS_NUM(buffer[i])) {
				close(fd);
				return (my_getnbr((char* const)(buffer + i)));
			}
		}
	}
	return (-1);
}
