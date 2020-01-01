#pragma once

#include "GameObject.hpp"
#include <SFML/Graphics.hpp>
#include <string>
#include "sprite_manipulation.hpp"
#include "Poele.hpp"

namespace Gengine
{
    class Player : public GameObject
    {
    public:
	Player(const std::string &type, sf::Texture &texture, sf::Texture &arm);
	void setOrigin(float x, float y);
	void setPosition(float x, float y);
	int getDistance() const;
	void extend_arm();
	void draw(sf::RenderWindow &window);
	void update(sf::RenderWindow &window);
	sf::Sprite getArm() const;
	// void fire(sf::Vector2i direction, std::vector<GameObject> &objs, sf::Texture &text);
    private:
	sf::Sprite _arm;
	int _distance;
    };
}
