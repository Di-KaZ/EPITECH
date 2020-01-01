/*
** EPITECH PROJECT, 2019
** PSU_zappy_2018
** File description:
** main
*/

#include "zappy_server.hpp"

int main(int, const char **av)
{
    Zappy::Server serv;

    try {
        if (serv.initializeParam(av) == -1)
            return (84);
        if (serv.initializeServer() == -1)
            return (84);
        return (serv.run());
    } catch (const std::string &e) {
        return (84);
    }
    return (0);
}