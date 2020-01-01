#pragma once
#include <SFML/Graphics.hpp>
#include <sstream>

namespace Gengine
{
    class Score {
    public:
	Score();
	void setPosition(int x, int y);
	void setFont(sf::Font &font);
	void setScore(int score);
	int getScore() const;
	void display(sf::RenderWindow &window);
	void update();
	int _score;
    private:
	sf::Text _text;
    };
}
