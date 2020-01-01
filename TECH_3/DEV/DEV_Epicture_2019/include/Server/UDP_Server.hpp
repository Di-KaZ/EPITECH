/*
** EPITECH PROJECT, 2019
** CPP_babel_2019
** File description:
** UDP_Server.hpp
*/

#pragma once
#include <boost/asio.hpp>
#include <boost/array.hpp>
#include <boost/bind.hpp>
#include <boost/shared_ptr.hpp>
#include <string>
#include <ctime>
#include <iostream>
#include "Clock.hpp"

#pragma once

using boost::asio::ip::udp;

class UDP_Server /*: public IServer*/ {
    public:
        UDP_Server(boost::asio::io_service& io_service, short int port);
        ~UDP_Server();
        void startReceive();
        void handleReceive(const boost::system::error_code &error, std::size_t size);
        void handleSend(boost::shared_ptr<std::string> msg, const boost::system::error_code &error, std::size_t size);
        std::string dumpScreenInfo();
        std::string dumpKeyPressed();
    private:
        bool isPast(const udp::endpoint &);
        boost::asio::io_service _io_service;
        boost::system::error_code _error;
        boost::asio::ip::udp::socket _socket;
        udp::endpoint _remote_endpoint;
        std::vector<udp::endpoint> _past_endpoints;
        boost::array<char, 128> _recv_buffer = {0};
};