/*
** EPITECH PROJECT, 2019
** PSU_zappy_2018
** File description:
** parse_bct
*/

#include "zappy_client.hpp"

std::string parse_bct(std::string bct_output)
{
    std::string info = "Title (";
    int temp;
    if (bct_output.find_first_of(' ') == std::string::npos)
            return("ko\n");
    bct_output = bct_output.substr(bct_output.find_first_of(' '));
    std::istringstream stream(bct_output);

    stream >> temp;
    info += std::to_string(temp + 1) + ", ";
    stream >> temp;
    info += std::to_string(temp + 1) + ")\n"; 
    stream >> temp;
    info += "Food : " + std::to_string(temp) + "\n";
    stream >> temp;
    info += "Linemate : " + std::to_string(temp) + "\n";
    stream >> temp;
    info += "Deraumere : " + std::to_string(temp) + "\n";
    stream >> temp;
    info += "Sibur : " + std::to_string(temp) + "\n";
    stream >> temp;
    info += "Mendiane : " + std::to_string(temp) + "\n";
    stream >> temp;
    info += "Phiras : " + std::to_string(temp) + "\n";
    stream >> temp;
    info += "Thystame : " + std::to_string(temp) + "\n";
    return (info);
}