/*
** EPITECH PROJECT, 2018
** OOP_arcade_2018
** File description:
** test->cpp
*/

#include "snake.hpp"

namespace arcade
{
    void Snakegame::initialize(IGraphicalHandler *lib_obj_ptr)
    {
        _lib_obj_ptr = lib_obj_ptr;
        _snake.initialize(lib_obj_ptr);
        vector_t size = {25, 25};
        _lib_obj_ptr->setWindowSize(size);
    }

    void Snake::initialize(IGraphicalHandler *lib_obj_ptr)
    {
        _lib_obj_ptr = lib_obj_ptr;
    }

    void Snake::displaySnake()
    {
        vector_t size = {1, 1};
        vector_t pos = {1, 0};
        vector_t pos2 = {2, 0};
        vector_t pos3 = {0, 0};

        if (_is_dead == false) {
            _lib_obj_ptr->drawText(pos3, "Score : " + std::to_string(_snakeBodys.size()));
            _lib_obj_ptr->drawText(pos, "Snake head pos : (" + std::to_string(_pos.x) + ", " + std::to_string(_pos.y) + ")");
            _lib_obj_ptr->drawText(pos2, "Apple pos : (" + std::to_string(_apple.x) + ", " + std::to_string(_apple.y) + ")");
            _lib_obj_ptr->drawShape(shape_t::CIRCLE, color_t::BLUE, _apple, size, "games/snake/apple.png");
            if (_last_key == keys_t::KEYBOARDKEY_UP)
                _lib_obj_ptr->drawShape(shape_t::CIRCLE, color_t::RED, _pos, size, "games/snake/snake_up.png");
            if (_last_key == keys_t::KEYBOARDKEY_DOWN)
                _lib_obj_ptr->drawShape(shape_t::CIRCLE, color_t::RED, _pos, size, "games/snake/snake_down.png");
            if (_last_key == keys_t::KEYBOARDKEY_LEFT)
                _lib_obj_ptr->drawShape(shape_t::CIRCLE, color_t::RED, _pos, size, "games/snake/snake_left.png");
            if (_last_key == keys_t::KEYBOARDKEY_RIGHT)
                _lib_obj_ptr->drawShape(shape_t::CIRCLE, color_t::RED, _pos, size, "games/snake/snake_right.png");
            for (size_t i = 0; i < _snakeBodys.size(); i += 1) {
                if (_last_key == keys_t::KEYBOARDKEY_LEFT || _last_key == keys_t::KEYBOARDKEY_RIGHT)
                    _lib_obj_ptr->drawShape(shape_t::SQUARE, color_t::RED, _snakeBodys[i], size, "games/snake/snake_body_left_right.png");
                if (_last_key == keys_t::KEYBOARDKEY_UP || _last_key == keys_t::KEYBOARDKEY_DOWN)
                    _lib_obj_ptr->drawShape(shape_t::SQUARE, color_t::RED, _snakeBodys[i], size, "games/snake/snake_body_up_down.png");
            }
        }
        else {
            _lib_obj_ptr->drawText(pos, "You loose ! sake size was : " + std::to_string(_snakeBodys.size()));
            _lib_obj_ptr->drawText(pos2, "Press R to restart...");
        }
    }

    void Snake::moveSnake(keys_t key)
    {
        if (_is_dead == false) {
            if (key == keys_t::KEYBOARDKEY_UP && _last_key != keys_t::KEYBOARDKEY_DOWN)
                _last_key = key;
            if (key == keys_t::KEYBOARDKEY_LEFT && _last_key != keys_t::KEYBOARDKEY_RIGHT) {
                _last_key = key;
            }
            if (key == keys_t::KEYBOARDKEY_DOWN && _last_key != keys_t::KEYBOARDKEY_UP)
                _last_key = key;
            if (key == keys_t::KEYBOARDKEY_RIGHT && _last_key != keys_t::KEYBOARDKEY_LEFT)
                _last_key = key;
            if (_movement.getElapsedTime() > 0.1) {
                addBody();
                isDead();
                _pos.x += _dir[_last_key].x;
                _pos.y += _dir[_last_key].y;
                if (_total == _snakeBodys.size()) {
                    for (int i = 0; i < _snakeBodys.size(); i += 1) {
                        _snakeBodys[i] = _snakeBodys[i + 1];
                    }
                }
                _snakeBodys.push_back(_pos);
                if (_snakeBodys.size() > _total)
                    _snakeBodys.erase(std::prev(_snakeBodys.end(), 1));
                _movement.reset();
            }
        } else {
            if (key == keys_t::KEYBOARDKEY_R)
                restart();
        }
    }

    void Snake::restart()
    {
        _is_dead = false;
        _snakeBodys.clear();
        _pos.x = rand() % 10; 
        _pos.y = rand() % 10; 
        _apple.y = rand() % 25; 
        _apple.y = rand() % 25; 
    }

    void Snake::addBody()
    {
        if (_pos.x == _apple.x && _pos.y == _apple.y) {
            _total += 1;
            vector_t temp = {rand() % 25, rand() % 25};
            _apple = temp;
        }
    }

    void Snakegame::displayScreen()
    {
        _snake.displaySnake();
    }
    
     void Snakegame::inputs()
    {
        keys_t key_pressed = _lib_obj_ptr->getInput();
         if (key_pressed == keys_t::KEYBOARDKEY_Q)
            status = status_t::QUIT;
        // if (key_pressed == keys_t::KEYBOARDKEY_DOWN)
        //     _squarre_pos.x += 1;
        // if (key_pressed == keys_t::KEYBOARDKEY_UP)
        //     _squarre_pos.x -= 1;
        // if (key_pressed == keys_t::KEYBOARDKEY_LEFT)
        //     _squarre_pos.y -= 1;
        // if (key_pressed == keys_t::KEYBOARDKEY_RIGHT)
        //     _squarre_pos.y += 1;
        _snake.moveSnake(key_pressed);
    }

    void Snake::isDead()
    {
        bool first = true;
        for (auto j = _snakeBodys.begin(); j != _snakeBodys.end(); j++) {
            if (first == true)
                first = false;
            if (first = false && _pos.x == j->x && _pos.y == j->y)
                _is_dead = true;
        }
    }

    void Snakegame::gameLogic()
    {
    }

    void Snakegame::free_ressources()
    {

    }
}
extern "C" arcade::IGameHandler *entryPoint()
{
    return (new arcade::Snakegame);
}