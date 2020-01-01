#include "Player.hpp"

namespace Gengine
{
    Player::Player(const std::string &type, sf::Texture &texture, sf::Texture &arm)
	: GameObject::GameObject(type, texture),
	_distance(150)
    {
		this->_arm.setTexture(arm);
		this->_arm.setTextureRect(sf::IntRect(0,0,16,29));
		this->_arm.setOrigin(sf::Vector2f(0, 29));
    }

    void Player::setOrigin(float x, float y)
    {
	this->_sprite.setOrigin(x, y);
    }

    void Player::setPosition(float x, float y)
    {
	this->_sprite.setPosition(x, y);
    }

	void Player::draw(sf::RenderWindow &window)
	{
		window.draw(this->_sprite);
		window.draw(this->_arm);
	}

    int Player::getDistance() const
    {
	return (this->_distance);
    }

	void Player::update(sf::RenderWindow &window)
	{
		rotateToMouse(this->_arm, sf::Mouse::getPosition(window));
		if (!sf::Mouse::isButtonPressed(sf::Mouse::Left))
			this->_arm.setTextureRect(sf::IntRect(0,0,16,29));
		this->_arm.setPosition(this->_sprite.getPosition().x, this->_sprite.getPosition().y - 4);
	}

	void Player::extend_arm()
	{
		sf::IntRect lol = this->_arm.getTextureRect();
		lol.left = 28;
		lol.width = 21;
		this->_arm.setTextureRect(lol);
	}

    sf::Sprite Player::getArm() const
    {
	return (this->_arm);
    }

	// void Player::fire(sf::Vector2i direction, std::vector<GameObject> &objs, sf::Texture &text)
	// {
	// 	Poele *temp = new Poele(text);

	// 	objs.push_back(*temp);
	// }
}
