/*
** EPITECH PROJECT, 2019
** CPP_babel_2019
** File description:
** BabelUdpServerClient.cpp
*/

#include "BabelUdpServerClient.hpp"

BabelUdpServerClient::BabelUdpServerClient() : _master_socket(nullptr), _remote_endpoint(nullptr)
{

}

BabelUdpServerClient::~BabelUdpServerClient()
{
    delete _remote_endpoint;
}


void BabelUdpServerClient::readClient(void *data, long unsigned int &size)
{
    boost::system::error_code error;
    // const char *data_to_send = reinterpret_cast<const char*>(&data);
    size_t len = _master_socket->receive_from(boost::asio::buffer(data, size), *_remote_endpoint);
    size = len;
}

void BabelUdpServerClient::writeClient(void *data, long unsigned int &size)
{
        boost::system::error_code error;
        // const char *data_to_send = reinterpret_cast<const char*>(&data);

        _master_socket->send_to(boost::asio::buffer(data, size), *_remote_endpoint, 0, error);
}

void BabelUdpServerClient::setRemoteEndPoint(boost::asio::ip::udp::socket *master_socket, boost::asio::ip::udp::endpoint *remote_endpoint)
{
    _remote_endpoint = remote_endpoint;
    _master_socket = master_socket;
}