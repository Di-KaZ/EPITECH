#include <iostream>
#include "Player.hpp"

Player::Player(GameDataRef data) : _data(data)
{
	_playerSprite.setTexture(this->_data->assets.GetTexture("Player"));

}

Player::~Player() {}

void Player::move(Move direction)
{
    std::cout << "PlayerMove" << std::endl;

    switch (direction)
    {
    case Move::UP:
        if (checkMove(direction))
            _playerSprite.setPosition(_playerSprite.getPosition().x, _playerSprite.getPosition().y - 5);
        break;
    case Move::DOWN:
        if (checkMove(direction))
            _playerSprite.setPosition(_playerSprite.getPosition().x, _playerSprite.getPosition().y + 5);
        break;
    case Move::LEFT:
        if (checkMove(direction))
            _playerSprite.setPosition(_playerSprite.getPosition().x - 5, _playerSprite.getPosition().y);
        break;
    case Move::RIGHT:
        if (checkMove(direction))
            _playerSprite.setPosition(_playerSprite.getPosition().x + 5, _playerSprite.getPosition().y);
        break;
    default:
        break;
    }
}

void Player::Draw()
{
	_data->window.draw(_playerSprite);
}
