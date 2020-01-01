/*
** EPITECH PROJECT, 2019
** CPP_babel_2019
** File description:
** BabelUdpClient.cpp
*/

#include "include/BabelUdpClient.hpp"
#define _MAX_READ_WRITE_ 2000

BabelUdpClient::BabelUdpClient()
{
    
}

BabelUdpClient::~BabelUdpClient()
{
}

void BabelUdpClient::sendData(void *data, long unsigned int &size)
{
    boost::system::error_code error;
        // const char *data_to_send = reinterpret_cast<const char*>(&data);

        _socket->send_to(boost::asio::buffer(data, size), *_receiver_endpoint, 0, error);
}

void BabelUdpClient::readData(void *data, long unsigned int &size)
{
    boost::system::error_code error;
    // const char *data_to_send = reinterpret_cast<const char*>(&data);

    size_t len = _socket->receive_from(boost::asio::buffer(data, size), *_receiver_endpoint);
    size = len;
}

void BabelUdpClient::connectToServer(std::string ip, int port)
{
    boost::asio::ip::udp::resolver resolver(_io_service);
    _query = new boost::asio::ip::udp::resolver::query(boost::asio::ip::udp::v4(), ip, std::to_string(port));
    _receiver_endpoint = new boost::asio::ip::udp::endpoint(*resolver.resolve(*_query));
    _socket = new boost::asio::ip::udp::socket(_io_service);
    _socket->open(boost::asio::ip::udp::v4());
}