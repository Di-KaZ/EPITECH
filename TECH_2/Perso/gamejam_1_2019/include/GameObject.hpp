#pragma once

#include <SFML/Graphics.hpp>
#include <string>

namespace Gengine
{
    class GameObject {
    public:
	GameObject(const std::string &type, sf::Texture &texture);
	virtual void ObjectDisplay(sf::RenderWindow &window);
	sf::Vector2f getObjectPosition() const;
	void setObjectPosition(sf::Vector2i);
	sf::Sprite &getSprite();
	std::string getType() const;
    protected:
	sf::Sprite _sprite;
	std::string _type;
    };
}
