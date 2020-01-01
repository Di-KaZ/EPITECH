#include "Poele.hpp"

namespace Gengine
{
    Poele::Poele(sf::Texture &text, int x, int y, int xDest, int yDest) :
	GameObject("Poele", text),
	_distance(0),
	_speed(200),
	_xOrigin(x),
	_yOrigin(y)
    {
	this->_sprite.setOrigin(this->_sprite.getGlobalBounds().width / 2, this->_sprite.getGlobalBounds().height / 2);
    }

    void Poele::draw(sf::RenderWindow &window)
    {
	window.draw(this->_sprite);
    }

    void Poele::update()
    {
	rotateSprite(this->_sprite, this->clock, 0.2f, 0.1f);
	// this->_sprite.move(this->_direction);
    }

    int Poele::getDistance() const
    {
        return (this->_distance);
    }

    int Poele::getSpeed() const
    {
        return (this->_speed);
    }

    void Poele::augmentDistance(int val)
    {
        if (val == -1) {
            if (this->_speed >= 10 || this->_speed <= -10)
                this->_distance = this->_distance + this->_speed / 10;
        } else {
            if (val >= 10 || val <= -10)
                this->_distance = this->_distance + val / 10;
        }
    }

    sf::Vector2f Poele::getOriginPosition() const
    {
	sf::Vector2f vect;

	vect.x = this->_xOrigin;
	vect.y = this->_yOrigin;
	return (vect);
    }
}
