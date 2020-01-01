/*
** EPITECH PROJECT, 2019
** CPP_babel_2019
** File description:
** BabelTcpServerClient.cpp
*/

#include "BabelTcpServerClient.hpp"

BabelTcpServerClient::BabelTcpServerClient()
{

}

BabelTcpServerClient::~BabelTcpServerClient()
{

}

void BabelTcpServerClient::readClient(void *data, long unsigned int &size)
{
    _socket->read_some(boost::asio::buffer(*(boost::array<char, 128> *)data, size));
}

void BabelTcpServerClient::writeClient(void *data, long unsigned int &size)
{
    _socket->write_some(boost::asio::buffer(*(boost::array<char, 128> *)data, size));    
}

void BabelTcpServerClient::setSocket(boost::asio::ip::tcp::socket *socket)
{
    _socket = socket;
}