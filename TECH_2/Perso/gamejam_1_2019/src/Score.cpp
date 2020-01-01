#include "Score.hpp"
#include <iostream>
#include "Definition.hpp"

namespace Gengine
{
    Score::Score() : _score(BEGIN_SCORE)
    {
	this->_text.setCharacterSize(50);
    }

    void Score::setPosition(int x, int y)
    {
	this->_text.setPosition(sf::Vector2f(x, y));
    }

    void Score::setScore(int score)
    {
	this->_score = score;
    }

    int Score::getScore() const
    {
	return (this->_score);
    }

    void Score::setFont(sf::Font &font)
    {
	this->_text.setFont(font);
    }

    void Score::update()
    {
	std::stringstream stream;

	stream << this->_score;
	this->_text.setString("Money : " + stream.str() + " $");
    }

    void Score::display(sf::RenderWindow &window)
    {
	window.draw(this->_text);
    }
}
