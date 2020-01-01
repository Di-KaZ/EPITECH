/*
** EPITECH PROJECT, 2019
** CPP_babel_2019
** File description:
** UDP_Server_Client.cpp
*/

#include "IServerClient.hpp"
#include <boost/asio.hpp>
#include <boost/array.hpp>
#include <boost/bind.hpp>
#include <iostream>

#pragma once

class UDP_Server_Client : public IServerClient {
    public:
        UDP_Server_Client();
        ~UDP_Server_Client();
        void readClient(void *data);
        void writeClient(void *data);
        /*
        ** register the end point associated with the client to communicate with
        */
        void setRemoteEndPoint(boost::asio::ip::udp::socket *master_socket, boost::asio::ip::udp::endpoint *remote_endpoint);
    private:
        boost::asio::ip::udp::socket *_master_socket;
        boost::asio::ip::udp::endpoint *_remote_endpoint;
};