/*
** EPITECH PROJECT, 2019
** CPP_babel_2019
** File description:
** CoreServer.cpp
*/

#include "CoreServer.hpp"

CoreServer::CoreServer(int port)
{
    // Change type of server here
    _i_server = new BabelUdpServer();

    _i_server->listenOnPort(port);
    std::cout << "started server on port " << port << std::endl;
}

CoreServer::~CoreServer()
{

}

void CoreServer::run()
{
    unsigned long read_len = _BYTE_NUM_;
    unsigned long write_len = _BYTE_NUM_;
    float *sample = nullptr;
    // std::vector<float *> samples_recived;
    float *recived = nullptr;

    while (true) {
        sample = audio.record();
        _new_client = _i_server->acceptClient();
        _new_client->writeClient(sample, write_len);
        recived = (float *)malloc(_BYTE_NUM_);
        if (!recived)
            throw "shiet happens";
        _new_client->readClient(&recived, read_len);
        audio.play(recived);
        free(recived);
        delete _new_client;
    }
}