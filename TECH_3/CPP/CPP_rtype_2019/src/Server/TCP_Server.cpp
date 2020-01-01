/*
** EPITECH PROJECT, 2019
** CPP_babel_2019
** File description:
** TCP_Server.cpp
*/

#include "TCP_Server.hpp"
#include "TCP_Server_Client.hpp"

TCP_Server::TCP_Server()
{
    _io_service.run();
}

TCP_Server::~TCP_Server()
{

}

void TCP_Server::listenOnPort(const int &port)
{
    _acceptor = new boost::asio::ip::tcp::acceptor(_io_service, boost::asio::ip::tcp::endpoint(boost::asio::ip::tcp::v4(), port));
}

IServerClient *TCP_Server::acceptClient()
{
    boost::asio::ip::tcp::socket *socket = new boost::asio::ip::tcp::socket(_io_service);
    _acceptor->async_accept(*socket);
    TCP_Server_Client *new_client = new TCP_Server_Client();
    new_client->setSocket(socket);
    return (new_client);
}