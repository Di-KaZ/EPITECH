#pragma once

#include "GameObject.hpp"
#include "sprite_manipulation.hpp"

namespace Gengine
{
    class Poele : public GameObject {
    public:
	Poele(sf::Texture &texture, int x, int y, int xDest, int yDest);
	void draw(sf::RenderWindow &window);
	void update();
	int getDistance() const;
	int getSpeed() const;
	void augmentDistance(int val = -1);
	sf::Vector2f getOriginPosition() const;
    private:
	int _xOrigin;
	int _yOrigin;
	int _speed;
	int _distance;
	sf::Clock clock;
    };
}
