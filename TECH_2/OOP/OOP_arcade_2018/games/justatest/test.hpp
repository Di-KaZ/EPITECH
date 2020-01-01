/*
** EPITECH PROJECT, 2018
** OOP_arcade_2018
** File description:
** test.hpp
*/

#pragma once
#include "IGameHandler.hpp"
#include "IGraphicalLibHandler.hpp"
#include <sstream>

namespace arcade
{
    class testgame : public IGameHandler {
        public:
            testgame() {};
            void initialize(IGraphicalHandler *);
            void displayScreen();
            void inputs();
            void gameLogic();
            void free_ressources();
        private:
            vector_t _squarre_pos = {0, 0};
    };
}