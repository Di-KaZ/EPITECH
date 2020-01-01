#include "Client.hpp"
#include "UDPClient.hpp"

Client::~Client()
{
}

void Client::init(std::string port, std::string host, int client_nb)
{
    _game = new Game();
    _udp_client = new UDPClient(host, port, client_nb);

    unsigned int width(1920);
    unsigned int height(1080);

    _game->init(width, height, "R-Type", _udp_client);
    // _udp_client->handleSend();
    // _udp_client->handleReceive();

}

void Client::run()
{
    _game->run();
}