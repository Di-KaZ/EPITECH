#include "Land.hpp"

#define PIPE_MOVEMENT_SPEED 200.0f

Land::Land(GameDataRef data) : _data(data)
{
    land1  = std::make_shared<sf::Sprite>(sf::Sprite(this->_data->assets.GetTexture("Land")));
    land2  = std::make_shared<sf::Sprite>(sf::Sprite(this->_data->assets.GetTexture("Land")));

    land1->setPosition(0, this->_data->window.getSize().y - land1->getLocalBounds().height);
    land2->setPosition(land1->getLocalBounds().width, this->_data->window.getSize().y - land1->getLocalBounds().height);
}

void Land::MoveLand(float dt)
{
    float movement = PIPE_MOVEMENT_SPEED * dt;
    land1->move(-movement, 0.0f);
    land2->setPosition(land1->getPosition().x + land1->getLocalBounds().width, 0);
    if (land1->getPosition().x + land1->getLocalBounds().width < 0) {
        auto temp = land1;
        land1 = land2;
        land2 = temp;
    }
}

void Land::DrawLand()
{
    _data->window.draw(*land2);
    _data->window.draw(*land1);
}