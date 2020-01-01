#pragma once

#include <ctime>
#include <iostream>
#include <string>
#include <boost/array.hpp>
#include <boost/bind.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/asio.hpp>
#include <thread>
#include <memory>
#define PORT 8080

using boost::asio::ip::udp;

class UDPClient
{
public:
    UDPClient(std::string host, std::string port, int is_host);
    ~UDPClient();
    std::string handleReceive();
    void handleSend(std::string msg);
    int getHost() { return _is_host; }

private:
    udp::endpoint *_receiver_endpoint;
    udp::socket *_socket;
    int _is_host;
};
