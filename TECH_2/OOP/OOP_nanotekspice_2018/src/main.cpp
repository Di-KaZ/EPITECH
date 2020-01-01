/*
** EPITECH PROJECT, 2018
** new_nanotekspice
** File description:
** main.cpp
*/

#include "Nanotek.hpp"

int main (int ac, const char **av)
{
	if (ac < 2)
		return(84);
    if (unhandled_param(av[1])) {
        return (0);
    }
	nts::Parser parse(av[1]);
	nts::Nanotek nano(&parse);
	nano.iniValue(ac, av);
	nano.run();
	return (0);
}
