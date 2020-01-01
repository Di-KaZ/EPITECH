#include "Definition.hpp"
#include "Bailiff.hpp"
#include <ctgmath>
#include <iostream>

namespace Gengine
{
    Bailiff::Bailiff(const std::string &type, sf::Texture &texture)
	: GameObject::GameObject(type, texture),
	_distance(800),
	_speed(20)
    {
    }

    void Bailiff::setOrigin(float x, float y)
    {
	this->_sprite.setOrigin(x, y);
    }

    void Bailiff::setPosition(float x, float y)
    {
	this->_sprite.setPosition(x, y);
    }

    int Bailiff::getDistance() const
    {
	return (this->_distance);
    }

    int Bailiff::getSpeed() const
    {
	return (this->_speed);
    }

    void Bailiff::reduceDistance(int val)
    {
	if (val == -1) {
	    if (this->_speed >= 10 || this->_speed <= -10)
		this->_distance = this->_distance - this->_speed / 10;
	} else {
	    if (val >= 10 || val <= -10)
		this->_distance = this->_distance - val / 10;
	}
    }

    double Bailiff::getAngle() const
    {
	double posx = this->_sprite.getPosition().x - (WIDTH / 2);
	double posy = this->_sprite.getPosition().y - (HEIGHT / 2);
	double posz = sqrt(pow(posx, 2) + pow(posy, 2));

	double angle = asin(posx / posz);

	return (angle);
    }
}
