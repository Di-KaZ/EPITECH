/*
** EPITECH PROJECT, 2019
** CPP_babel_2019
** File description:
** BabelTcpServer.cpp
*/

#include "BabelTcpServer.hpp"
#include "BabelTcpServerClient.hpp"

BabelTcpServer::BabelTcpServer()
{

}

BabelTcpServer::~BabelTcpServer()
{

}

void BabelTcpServer::listenOnPort(const int &port)
{
    _acceptor = new boost::asio::ip::tcp::acceptor(_io_service, boost::asio::ip::tcp::endpoint(boost::asio::ip::tcp::v4(), port));
}

IServerClient *BabelTcpServer::acceptClient()
{
    boost::asio::ip::tcp::socket *socket = new boost::asio::ip::tcp::socket(_io_service);
    _acceptor->accept(*socket);
    BabelTcpServerClient *new_client = new BabelTcpServerClient();
    new_client->setSocket(socket);
    return (new_client);
}