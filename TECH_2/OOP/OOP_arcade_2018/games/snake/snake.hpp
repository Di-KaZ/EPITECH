/*
** EPITECH PROJECT, 2018
** OOP_arcade_2018
** File description:
** test.hpp
*/

#pragma once
#include <stdlib.h>
#include "IGameHandler.hpp"
#include "IGraphicalLibHandler.hpp"
#include <map>
#include <sys/types.h>
#include <unistd.h>

namespace arcade
{
    class Snake {
        public:
        Snake() {
            srand(getpid()); 
            // _snakeBodys.push_back(pos);
        };
        void initialize(IGraphicalHandler *);
        void displaySnake();
        void addBody();
        void moveApple();
        void isDead();
        void restart();
        keys_t _last_key = keys_t::KEYBOARDKEY_RIGHT;
        void moveSnake(keys_t key);
        private:
        bool _is_dead = false;
        int _total = 0;
        vector_t _pos = {rand() % 10, rand() % 10};
        vector_t _apple = {rand() % 25, rand() % 25};
        IGraphicalHandler *_lib_obj_ptr;
        Clock _movement;
        std::map<keys_t, vector_t> _dir =
        {
            {keys_t::KEYBOARDKEY_UP, {-1, 0}},
            {keys_t::KEYBOARDKEY_RIGHT, {0, 1}},
            {keys_t::KEYBOARDKEY_LEFT, {0, -1}},
            {keys_t::KEYBOARDKEY_DOWN, {1, 0}}
        };
        std::vector<vector_t> _snakeBodys;
    };

    class Snakegame : public IGameHandler {
        public:
            Snakegame() {};
            void initialize(IGraphicalHandler *);
            void displayScreen();
            void inputs();
            void gameLogic();
            void free_ressources();
        private:
            int _score = 0;
            Snake _snake;
    };

}