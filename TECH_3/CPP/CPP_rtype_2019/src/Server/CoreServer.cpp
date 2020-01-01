/*
** EPITECH PROJECT, 2019
** CPP_babel_2019
** File description:
** CoreServer.cpp
*/

#include "CoreServer.hpp"

CoreServer::CoreServer(int port)
{
    _i_server = new TCP_Server();

    _i_server->listenOnPort(port);
    std::cout << "started server on port " << port << std::endl;
}

CoreServer::~CoreServer()
{

}

void CoreServer::run()
{
    std::string test = "Welcome";
    boost::array<char, 2000> buff = {0};
    while (true) {
        _new_client = _i_server->acceptClient();
        _new_client->writeClient(&test);
        _new_client->readClient((void *)&buff);
        delete _new_client;
    }
}