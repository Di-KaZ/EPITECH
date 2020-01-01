/*
** EPITECH PROJECT, 2019
** CPP_babel_2019
** File description:
** main.cpp
*/

#include "CoreServer.hpp"
#include <stdlib.h>

int main(int ac, char **av)
{
    CoreServer serv(std::atoi(av[1]));

    // if you want to switch from udp to tcp check coreserver constructor
    serv.run();
    return (0);
}