/*
** EPITECH PROJECT, 2019
** CPP_babel_2019
** File description:
** IServerClient.hpp
*/

#include <string>
#pragma once

class IServerClient {
    public:
        virtual ~IServerClient()
        {

        };
        /*
        ** Read data sent by client
        */
        virtual void readClient(void *data) = 0;
        /*
        ** Write data to client
        */
        virtual void writeClient(void *data) = 0;
};