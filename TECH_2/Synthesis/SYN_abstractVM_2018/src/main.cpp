/*
** EPITECH PROJECT, 2019
** abstractWM
** File description:
** main
*/

#include <iostream>
#include "Factory.h"
#include "parsingFile.hpp"

int main (int ac, char **av)
{
	try {
		if (ac == 1) {
			parsingFile parser;
		} else {
			std::string filepath = av[1];
			parsingFile parserer(filepath);
		}
	} catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
		return (84);
	} catch (...) {
        	std::cerr << "Unknown exception caught" << std::endl;
        	exit(84);
	}
	return (0);
}
