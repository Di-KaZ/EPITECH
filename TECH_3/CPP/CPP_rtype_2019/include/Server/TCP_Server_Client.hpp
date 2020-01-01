/*
** EPITECH PROJECT, 2019
** CPP_babel_2019
** File description:
** TCP_Server_Client.hpp
*/

#include <boost/asio.hpp>
#include <boost/array.hpp>
#include <iostream>
#include "IServerClient.hpp"

class TCP_Server_Client : public IServerClient {
    public:
        TCP_Server_Client();
        ~TCP_Server_Client();
        void readClient(void *data);
        void writeClient(void *data);
        /*
        ** Set socket to communicate with client
        */
        void setSocket(boost::asio::ip::tcp::socket *socket);
    private:
        boost::asio::ip::tcp::socket *_socket;
};