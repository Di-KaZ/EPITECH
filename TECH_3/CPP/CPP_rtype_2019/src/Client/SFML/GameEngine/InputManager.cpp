#include <iostream>
#include "InputManager.hpp"

bool InputManager::IsSpriteClicked(sf::Sprite object, sf::Mouse::Button button, sf::RenderWindow &window)
{
    if (sf::Mouse::isButtonPressed(button)) {
        sf::IntRect tempRect(object.getPosition().x, object.getPosition().y, object.getGlobalBounds().width, object.getGlobalBounds().height);
        if (tempRect.contains(sf::Mouse::getPosition(window)))
            return true;
    }
    return false;
}

sf::Vector2i InputManager::GetMousePosition(sf::RenderWindow &window)
{
    return sf::Mouse::getPosition(window);
}

Move InputManager::GetDirectionInput()
{
    std::cout << "get direction input" << std::endl;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        return Move::LEFT;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        return Move::RIGHT;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        std::cout << "up" << std::endl;
        return Move::UP;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        return Move::DOWN;
    return Move::Null;
}