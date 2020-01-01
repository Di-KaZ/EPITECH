#include <iostream>

#include "Client.hpp"
#include "IClient.hpp"

int main(int argc, char const *argv[])
{
    unsigned int width(1920);
    unsigned int height(1080);

    IClient *client = new Client();

    try
    {
        if (argc != 4)
        {
            std::cerr << "Usage: client <host> <port> <client_nb>" << std::endl;
            return 1;
        } else
            client->init(argv[2], argv[1], std::stoi(argv[3]));
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    client->run();
    delete client;

    return 0;
}