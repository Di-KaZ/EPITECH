/*
** EPITECH PROJECT, 2019
** PSU_zappy_2018
** File description:
** Player
*/

#include "zappy_server.hpp"

namespace Zappy {
    Player::Player(std::string team, int id, struct sockaddr_in socket, std::pair<int, int> pos)
    : _team(team), _id(id), _sockaddr(socket), _pos(pos)
    {
    }

    Player::~Player()
    {
    }

    const int &Player::getID() const
    {
        return (_id);
    }

    void Player::setPosition(std::pair<int, int> pos)
    {
        _pos = pos;
    }

    const bool &Player::isRegistered() const
    {
        return (_is_registered);
    }

    void Player::registerPlayer()
    {
        _is_registered = true;
    }

    const std::pair<int, int> &Player::getPosition() const
    {
        return (_pos);
    }

    const int &Player::getIncantationLevel() const
    {
        return (_incantation_level);
    }

    int Player::getOrientation()
    {
        switch (_o)
        {
            case orientation_t::NORTH :
                return (1);
            case orientation_t::EAST :
                return (2);
            case orientation_t::WEST :
                return (4);
            case orientation_t::SOUTH :
                return (3);
        }
        return (0);
    }

    const std::string &Player::getTeam() const
    {
        return (_team);
    }

    std::string Player::getInfoPosition()
    {
        std::string info = "ppo ";

        info += std::to_string(_pos.first) + " " + std::to_string(_pos.second) + " ";
        switch (_o)
        {
            case orientation_t::NORTH :
                info += "1\n";
                break;
            case orientation_t::EAST :
                info += "2\n";
                break;
            case orientation_t::WEST :
                info += "4\n";
                break;
            case orientation_t::SOUTH :
                info += "3\n";
                break;
        }
        return (info);
    }

    std::string Player::executeFirstCommand()
    {
        std::string command;

        if (_command_queue.size() != 0) {
            command = _command_queue[0];
            _command_queue.erase(_command_queue.begin());    
            return (command);
        }
        return ("[NO COMMAND]");
    }

    void Player::registerNewCommad(std::string command)
    {
        _command_queue.push_back(command);
        while (_command_queue.size() > 10)
            _command_queue.erase(_command_queue.end());
            
    }
}
