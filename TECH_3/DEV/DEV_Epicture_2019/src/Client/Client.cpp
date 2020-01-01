#include "Client.hpp"
#include "UDPClient.hpp"

Client::~Client()
{
}

void Client::init(std::string port, std::string host, int client_nb)
{
    _game = new Game();
    _udp_client = std::make_shared<UDPClient>(UDPClient(host, port, client_nb));

    unsigned int width = 1920;
    unsigned int height = 1080;

    _game->init(width, height, "R-Type", _udp_client);
}

void Client::run()
{
    _game->run();
}