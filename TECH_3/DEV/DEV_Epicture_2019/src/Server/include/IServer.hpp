/*
** EPITECH PROJECT, 2019
** CPP_babel_2019
** File description:
** IServer.hpp
*/

#include "IServerClient.hpp"
#pragma once

class IServer {
    public:
        virtual ~IServer()
        {

        };
        virtual void listenOnPort(const int &port) = 0;
        virtual IServerClient *acceptClient() = 0;
};
