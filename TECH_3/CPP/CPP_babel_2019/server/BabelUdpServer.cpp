/*
** EPITECH PROJECT, 2019
** CPP_babel_2019
** File description:
** BabelUdpServer.cpp
*/

#include "BabelUdpServer.hpp"

BabelUdpServer::BabelUdpServer()
{
}

BabelUdpServer::~BabelUdpServer()
{
    delete _socket;
}

void BabelUdpServer::listenOnPort(const int &port)
{
    _socket = new boost::asio::ip::udp::socket(_io_service, boost::asio::ip::udp::endpoint(boost::asio::ip::udp::v4(), port));
}

IServerClient *BabelUdpServer::acceptClient()
{
    boost::asio::ip::udp::endpoint remote_endpoint;

    boost::asio::ip::udp::endpoint *remote = new boost::asio::ip::udp::endpoint(boost::asio::ip::address::from_string(remote_endpoint.address().to_string()), remote_endpoint.port());
    BabelUdpServerClient *new_client =  new BabelUdpServerClient();
    new_client->setRemoteEndPoint(_socket, remote);
    return (new_client);
}