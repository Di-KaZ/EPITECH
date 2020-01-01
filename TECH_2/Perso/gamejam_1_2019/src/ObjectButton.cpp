#include "ObjectButton.hpp"

namespace Gengine
{
	ObjectButton::ObjectButton(const std::string &type, sf::Texture &texture) : GameObject(type, texture)
	{

	}

	void ObjectButton::ObjectDisplay(sf::RenderWindow &window)
	{
		window.draw(this->_sprite);
		window.draw(this->_text);
	}

	void Initialize(const sf::Font &font, const std::string &text)
	{
		this->_text.setFont(font);
		this->_text.setString(string);
		this->_text.setScale(2, 2);
	}
}