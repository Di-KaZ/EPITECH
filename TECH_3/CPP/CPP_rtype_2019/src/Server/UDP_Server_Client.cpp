/*
** EPITECH PROJECT, 2019
** CPP_babel_2019
** File description:
** UDP_Server_Client.cpp
*/

#include "UDP_Server_Client.hpp"

UDP_Server_Client::UDP_Server_Client() : _master_socket(nullptr), _remote_endpoint(nullptr)
{

}

UDP_Server_Client::~UDP_Server_Client()
{
    delete _remote_endpoint;
}


void UDP_Server_Client::readClient(void *data)
{
    boost::system::error_code error;

    _master_socket->receive_from(boost::asio::buffer(*(std::string *)data), *_remote_endpoint);
}

void UDP_Server_Client::writeClient(void *data)
{
        boost::system::error_code error;
        _master_socket->send_to(boost::asio::buffer(*(std::string *)data), *_remote_endpoint, 0, error);    
}

void UDP_Server_Client::setRemoteEndPoint(boost::asio::ip::udp::socket *master_socket, boost::asio::ip::udp::endpoint *remote_endpoint)
{
    _remote_endpoint = remote_endpoint;
    _master_socket = master_socket;
}