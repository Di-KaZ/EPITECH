/*
** EPITECH PROJECT, 2019
** CPP_babel_2019
** File description:
** Core.hppServer
*/

#include "IServer.hpp"
#include "BabelTcpServer.hpp"
#include "BabelUdpServer.hpp"
#include "PortAudio.hpp"
#include <memory>
#include <map>

#pragma once
class CoreServer {
    public:
        CoreServer(int port);
        ~CoreServer();
        void run();
    private:
        PortAudioClass audio;
        IServer *_i_server;
        IServerClient *_new_client = nullptr;
};