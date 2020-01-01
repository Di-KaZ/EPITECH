#include "GameObject.hpp"

namespace Gengine
{
    GameObject::GameObject(const std::string &type, sf::Texture &texture)
	: _type(type)
    {
	this->_sprite.setTexture(texture);
    }

    void GameObject::ObjectDisplay(sf::RenderWindow &window)
    {
	window.draw(this->_sprite);
    }

    sf::Vector2f GameObject::getObjectPosition() const
    {
	return (this->_sprite.getPosition());
    }

    std::string GameObject::getType() const
    {
        return (this->_type);
    }

    void GameObject::setObjectPosition(sf::Vector2i pos)
    {
	this->_sprite.setPosition(pos.x, pos.y);
    }

    sf::Sprite &GameObject::getSprite()
    {
     	return (this->_sprite);
    }
}
