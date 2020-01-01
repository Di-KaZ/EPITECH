#include "ECSPlayer.hpp"
#include <iostream>

ECSPlayer::ECSPlayer()
{
    _pos = sf::Vector2f(0, 0);
}

ECSPlayer::~ECSPlayer()
{

}

void ECSPlayer::init()
{
    _sprite.setTexture(_data->assets.GetTexture("Player"));
    _sprite.setPosition(sf::Vector2f(20, 20));
}

void ECSPlayer::draw()
{
    _data->window.draw(_sprite);
}

void ECSPlayer::executeCommand(const Command &command)
{
    if (command.getCommand() == ECS::command::SETPOS) {
        std::cout << "yooo" << std::endl;
        _sprite.setPosition(command.getPos());
    }
}

void ECSPlayer::move(const Move &direction)
{
    switch (direction)
    {
        case Move::UP:
            if (checkMove(direction))
                _pos.y -= 5;
            break;
        case Move::DOWN:
            if (checkMove(direction))
                _pos.y += 5;
            break;
        case Move::LEFT:
            if (checkMove(direction))
                _pos.x -= 5;
            break;
        case Move::RIGHT:
            if (checkMove(direction))
                _pos.x += 5;
            break;
        default:
            break;
    }
}

std::string ECSPlayer::toString() const
{
    return std::string(std::to_string(_id) + " SHIP SETPOS " + std::to_string(_pos.x) + " " + std::to_string(_pos.y));
}