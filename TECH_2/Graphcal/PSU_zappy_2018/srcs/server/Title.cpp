/*
** EPITECH PROJECT, 2019
** PSU_zappy_2018
** File description:
** Title
*/

#include "zappy_server.hpp"

namespace Zappy {
    Title::Title()
    : _food(0), _linemate(0), _deraumere(0), _sibur(0), _mendiane(0), _phiras(0), _thystame(0)
    {
    }

    Title::~Title()
    {
    }

    void Title::addRessources()
    {
        _food += rand() % 5 == 1 ? 1 : 0;
        _linemate += rand() % 5 == 1 ? 1 : 0;
        _deraumere += rand() % 5 == 1 ? 1 : 0;
        _sibur += rand() % 5 == 1 ? 1 : 0;
        _mendiane += rand() % 5 == 1 ? 1 : 0;
        _phiras += rand() % 5 == 1 ? 1 : 0;
        _thystame += rand() % 5 == 1 ? 1 : 0;
    }

    std::string Title::getTitleInfo()
    {
        std::string info = std::to_string(_food) + " " +
                            std::to_string(_linemate) + " " +
                            std::to_string(_deraumere) + " " +
                            std::to_string(_sibur) + " " +
                            std::to_string(_mendiane) + " " +
                            std::to_string(_phiras) + " " +
                            std::to_string(_thystame) + " ";
        return (info);
    }
}
