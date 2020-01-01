/*
** EPITECH PROJECT, 2019
** CPP_babel_2019
** File description:
** UDP_Server.cpp
*/

#include "UDP_Server.hpp"

UDP_Server::UDP_Server(boost::asio::io_service &io_service, short int port) : _socket(io_service, udp::endpoint(udp::v4(), port))
{
    _recv_buffer = {0};
    startReceive();
}

UDP_Server::~UDP_Server()
{
    // delete _socket;
}

void UDP_Server::startReceive()
{
    _socket.async_receive_from(boost::asio::buffer(_recv_buffer), _remote_endpoint,
                               boost::bind(&UDP_Server::handleReceive, this,
                                           boost::asio::placeholders::error,
                                           boost::asio::placeholders::bytes_transferred));
    std::cout << "rc: " << _recv_buffer.data() << std::endl;
}

void UDP_Server::handleReceive(const boost::system::error_code &error, std::size_t size)
{
    boost::shared_ptr<std::string> message(new std::string());
    int i = 2;
    while (i)
    {
        _socket.async_send_to(boost::asio::buffer(_recv_buffer), _remote_endpoint,
                              boost::bind(&UDP_Server::handleSend, this, message,
                                          boost::asio::placeholders::error,
                                          boost::asio::placeholders::bytes_transferred));
        i--;
    }
    startReceive();
}

void UDP_Server::handleSend(boost::shared_ptr<std::string> msg, const boost::system::error_code &error, std::size_t size)
{
    boost::shared_ptr<std::string> message(new std::string(dumpScreenInfo()));

    std::cout << "msg receive: " << message << std::endl;

    _socket.async_receive_from(boost::asio::buffer(*message), _remote_endpoint,
                               boost::bind(&UDP_Server::handleSend, this, message,
                                           boost::asio::placeholders::error,
                                           boost::asio::placeholders::bytes_transferred));
    startReceive();
}

std::string UDP_Server::dumpScreenInfo()
{
    // on check tout les objet sur l'ecran et on les transforme en string coord vie ect, puis on envoie la string au 3 autre client pour qu'il puissent affiche r a l'ecran
    return std::string("hohoho");
}

std::string UDP_Server::dumpKeyPressed()
{
    // ici on va recup tte les touches que le client non host presse et on les sauve dans une string pour le que l'host puisse les interprété
    return std::string("ahahaha");
}

// void UDP_Server::listenOnPort(const int &port)
// {
//     _socket = new boost::asio::ip::udp::socket(_io_service, boost::asio::ip::udp::endpoint(boost::asio::ip::udp::v4(), port));
// }

// IServerClient *UDP_Server::acceptClient()
// {
//     boost::asio::ip::udp::endpoint remote_endpoint;

//     boost::asio::ip::udp::endpoint *remote = new boost::asio::ip::udp::endpoint(boost::asio::ip::address::from_string(remote_endpoint.address().to_string()), remote_endpoint.port());
//     UDP_Server_Client *new_client =  new UDP_Server_Client();
//     new_client->setRemoteEndPoint(_socket, remote);
//     return (new_client);
// }