/*
** EPITECH PROJECT, 2019
** CPP_babel_2019
** File description:
** BabelTcpServerClient.hpp
*/

#include <boost/asio.hpp>
#include <boost/array.hpp>
#include <iostream>
#include "IServerClient.hpp"

class BabelTcpServerClient : public IServerClient {
    public:
        BabelTcpServerClient();
        ~BabelTcpServerClient();
        void readClient(void *data, long unsigned int &size);
        void writeClient(void *data, long unsigned int &size);
        /*
        ** Set socket to communicate with client
        */
        void setSocket(boost::asio::ip::tcp::socket *socket);
    private:
        boost::asio::ip::tcp::socket *_socket;
};