/*
** EPITECH PROJECT, 2019
** PSU_zappy_2018
** File description:
** Map
*/

#include "zappy_server.hpp"

namespace Zappy {
    Map::Map()
    {

    }
    
    Map::Map(int width, int height)
    : _width(width), _height(height)
    {
        generateMap();
    }

    Map::~Map()
    {

    }

    void Map::generateMap()
    {
        std::pair<int, int> pos;

        while (pos.first < _height) {
            while (pos.second < _width) {
                _map[pos] = std::shared_ptr<Title>(new Title);
                pos.second += 1;
            }
            pos.second = 0;
            pos.first += 1;
        }
    }

    void Map::setMapWidth(int width)
    {
        _width = width; 
    }

    void Map::setMapHeight(int height)
    {
        _height = height; 
    }
    void Map::addRessources()
    {
        for (auto i : _map) {
            i.second->addRessources();
        }
    }

    std::string Map::getTitleInfo(std::pair<int, int> pos)
    {
        std::string info = "bct ";

        info += std::to_string(pos.first) + " " + std::to_string(pos.second) + " ";
        info += _map[pos]->getTitleInfo();
        info += "\n";
        return (info);
    }
    
    std::string Map::getMapInfo()
    {
        std::string infos;
        std::string temp;

        for (auto i : _map) {
            temp = "bct ";
            temp += std::to_string(i.first.first) + " " + std::to_string(i.first.second);
            temp += i.second->getTitleInfo();
            temp += "\n";
            infos += temp;
        }
        return (infos);
    }
}
