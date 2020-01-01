#pragma once

#include "GameObject.hpp"
#include <SFML/Graphics.hpp>
#include <string>
#include "sprite_manipulation.hpp"

namespace Gengine
{
    class Bailiff : public GameObject
    {
    public:
	Bailiff(const std::string &type, sf::Texture &texture);
	void setOrigin(float x, float y);
	void setPosition(float x, float y);
	int getDistance() const;
	int getSpeed() const;
	void reduceDistance(int val = -1);
	double getAngle() const;
    private:
	int _distance;
	int _speed;
    };
}
