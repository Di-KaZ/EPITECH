#pragma once

#include <SFML/Graphics.hpp>
#include "IClient.hpp"
#include "UDPClient.hpp"
#include "IGame.hpp"
#include "Game.hpp"
#include <memory>
#include <thread>

class Client : virtual public IClient
{
    private:
        IGame *_game;
        UDPClient *_udp_client;
    public:
        Client() {}
        ~Client();

        void init(std::string port, std::string host, int client_nb);
        void run();
};