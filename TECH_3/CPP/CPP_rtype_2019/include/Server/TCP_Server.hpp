/*
** EPITECH PROJECT, 2019
** CPP_babel_2019
** File description:
** TCP_Server.hpp
*/

#include <boost/asio.hpp>
#include <boost/array.hpp>
#include <iostream>
#include "IServer.hpp"

class TCP_Server : public IServer {
    public:
        TCP_Server();
        ~TCP_Server();
        void listenOnPort(const int &port);
        IServerClient *acceptClient();
    private:
        boost::system::error_code _error;
        boost::asio::ip::tcp::acceptor *_acceptor;
        boost::asio::io_service _io_service;
};