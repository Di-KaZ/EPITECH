/*
** EPITECH PROJECT, 2019
** CPP_babel_2019
** File description:
** main.cpp
*/

#include <iostream>
#include <stdlib.h>
#include <string>
#include "UDP_Server.hpp"

int main(int argc, char **argv)
{
    try {
        if (argc != 2) {
            std::cerr << "Usage: server <port>" << std::endl;
            return 1;
        }
        boost::asio::io_service io_service;
        UDP_Server server(io_service, std::stoi(argv[1]));
        io_service.run();
    }
    catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    return (0);
}