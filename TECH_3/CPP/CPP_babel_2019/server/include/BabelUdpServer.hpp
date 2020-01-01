/*
** EPITECH PROJECT, 2019
** CPP_babel_2019
** File description:
** BabelUdpServer.hpp
*/

#include <boost/asio.hpp>
#include <boost/array.hpp>
#include <iostream>
#include "IServer.hpp"
#include "BabelUdpServerClient.hpp"

#pragma once
class BabelUdpServer : public IServer {
    public:
        BabelUdpServer();
        ~BabelUdpServer();
        void listenOnPort(const int &port);
        IServerClient *acceptClient();
    private:
        boost::asio::io_service _io_service;
        boost::system::error_code _error;
        boost::asio::ip::udp::socket *_socket;
};