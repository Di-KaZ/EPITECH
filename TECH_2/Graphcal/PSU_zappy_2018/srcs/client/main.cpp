/*
** EPITECH PROJECT, 2019
** temp_zappy
** File description:
** main
*/

#include "zappy_client.hpp"

int main (int, const char **av)
{
    ZappyClient::Client client(av);
    
    client.connectToServer();
    client.runAI();
    return (0);
}