#pragma once

#include <SFML/Graphics.hpp>
#include "Move.hpp"
#include "Game.hpp"

class Player
{
public:
    Player(GameDataRef data);
    ~Player();
    void move(Move);
    bool checkMove(Move) {return true;}

    float getPosX() {return _playerSprite.getPosition().x;}
    float getPosY() {return  _playerSprite.getPosition().y;}
    void setPos(float x, float y) { _playerSprite.setPosition(x, y); }

	void Draw();

private:
	GameDataRef _data;
    sf::Vector2f _pos;
	sf::Sprite _playerSprite;


};