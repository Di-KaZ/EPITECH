/*
** EPITECH PROJECT, 2019
** CPP_babel_2019
** File description:
** TCP_Server_Client.cpp
*/

#include "TCP_Server_Client.hpp"

TCP_Server_Client::TCP_Server_Client()
{

}

TCP_Server_Client::~TCP_Server_Client()
{

}

void TCP_Server_Client::readClient(void *data)
{
    _socket->read_some(boost::asio::buffer(*(std::string *)data));
}

void TCP_Server_Client::writeClient(void *data)
{
    _socket->write_some(boost::asio::buffer(*(std::string *)data));    
}

void TCP_Server_Client::setSocket(boost::asio::ip::tcp::socket *socket)
{
    _socket = socket;
}