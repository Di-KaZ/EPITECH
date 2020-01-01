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
    // for (unsigned short int i = 0; i < _landSprites.size(); i++)
    // {
    //     sf::Vector2f position = _landSprites.at(i).getPosition();
    //     _landSprites.at(i).move(-movement, 0.0f);

    //     if (_landSprites.at(i).getPosition().x < 0 - _landSprites.at(i).getLocalBounds().width)
    //     {
    //         sf::Vector2f position(_data->window.getSize().x, _landSprites.at(i).getPosition().y);
    //         _landSprites.at(i).setPosition(position);
    //     }
    // }

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
//     for (unsigned short int i = 0; i < _landSprites.size(); i++)
//     {
//         this->_data->window.draw(_landSprites.at(i));
//     }
    _data->window.draw(*land2);
    _data->window.draw(*land1);
}