#pragma once
#include <SFML/Graphics.hpp>

namespace Gengine
{
	typedef struct s_anim {
		sf::Clock clock;
		std::vector<sf::IntRect> anim_rect;
		std::vector<sf::IntRect>::iterator i;
	}	anim_t;
	void rotateSprite(sf::Sprite &sprite, sf::Clock &clock, float period, float speed);
	void fadeInSprite(sf::Sprite &sprite, sf::Clock &clock);
	void fadeOutSprite(sf::Sprite &sprite, sf::Clock &clock);
	void rotateToMouse(sf::Sprite &sprite, sf::Vector2i mouse_pos);
	void animate(sf::Sprite &sprite, anim_t &anim);
	bool is_colliding(sf::Sprite &sprite, sf::Sprite &sprite2);
}