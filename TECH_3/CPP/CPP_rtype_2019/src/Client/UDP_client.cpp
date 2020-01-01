#include "UDPClient.hpp"

using boost::asio::ip::udp;

UDPClient::UDPClient(std::string host, std::string port, int is_host) : _is_host(is_host)
{
    boost::asio::io_service io_service;

    udp::resolver resolver(io_service);
    udp::resolver::query query(udp::v4(), host, port);
    _receiver_endpoint = new udp::endpoint(*resolver.resolve(query));

    _socket = new udp::socket(io_service);
    _socket->open(udp::v4());
}

UDPClient::~UDPClient()
{
}

std::string UDPClient::handleReceive()
{

    boost::array<char, 128> recv_buf = {0};
    udp::endpoint sender_endpoint;

    size_t len = _socket->receive_from(
        boost::asio::buffer(recv_buf), sender_endpoint);

    // std::cout.write(recv_buf.data(), len);
    return recv_buf.data();
}

void UDPClient::handleSend(std::string msg)
{
    // boost::array<char, 128> send_buf = msg ;

    _socket->send_to(boost::asio::buffer(msg), *_receiver_endpoint);
}