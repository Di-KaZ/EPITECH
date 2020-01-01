/*
** EPITECH PROJECT, 2019
** CPP_babel_2019
** File description:
** Core.hppServer
*/

#include "IServer.hpp"
#include "TCP_Server.hpp"
#include "UDP_Server.hpp"
#include <memory>
#include <map>

#pragma once
class CoreServer {
    public:
        CoreServer(int port);
        ~CoreServer();
        void run();
    private:
        IServer *_i_server;
        IServerClient *_new_client = nullptr;
};