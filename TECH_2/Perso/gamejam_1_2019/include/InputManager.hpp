#pragma once
#include <SFML/Graphics.hpp>

namespace Gengine
{
    class InputManager {
    public:
	bool isSpriteClicked(const sf::Sprite &object, sf::Mouse::Button button, const sf::RenderWindow &window);
	sf::Vector2i GetMousePosition(sf::RenderWindow &window);
    };
}
