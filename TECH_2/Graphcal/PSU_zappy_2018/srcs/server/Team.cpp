/*
** EPITECH PROJECT, 2019
** PSU_zappy_2018
** File description:
** Team
*/

#include "zappy_server.hpp"

namespace Zappy
{
    Team::Team(std::string name, int total_slot) : _name(name), _total_slot(total_slot), _used_slot(0)
    {

    }

    Team::~Team()
    {
    }

    int Team::getRemainingSlot()
    {
        return (_total_slot - _used_slot);
    }

    void Team::setMaxSlot(int slots)
    {
        _total_slot = slots;
        std::cout << _name + " max slot = " << _total_slot << std::endl;
    }

    const std::string &Team::getName() const
    {
        return (_name);
    }

    void Team::newPlayerAccepted()
    {
        std::string info = "a new player joined the team " + _name;
        PRINT_INFO_MSG(info.c_str());
        _used_slot += 1;
    }
}