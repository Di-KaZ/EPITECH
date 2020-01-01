#include <boost/asio.hpp>
#include "IClientnew.hpp"
#pragma once
class BabelUdpClient : public IClient {
    public:
        BabelUdpClient();
        ~BabelUdpClient();
        void sendData(void *data, long unsigned int &size);
        void readData(void *data, long unsigned int &size);
        void connectToServer(std::string ip, int port);
    private:
        //boost::asio::ip::udp::resolver *_resolver;
        boost::asio::ip::udp::resolver::query *_query;
        boost::asio::ip::udp::endpoint *_receiver_endpoint;
        boost::asio::ip::udp::socket *_socket;
        boost::asio::io_service _io_service;
};
