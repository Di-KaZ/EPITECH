/*
** EPITECH PROJECT, 2018
** OOP_arcade_2018
** File description:
** main.cpp
*/
#include "ArcadeHandler.hpp"

int main (int ac, char **av)
{
    arcade::Core core;

    if (ac != 2) {
        std::cout << "./arcade libgraph.so" << std::endl;
        return (84);
    }
    core.loadDynamicLib(av[1], arcade::type_t::GRAPHICAL);
    core.run();
    return (0);
}