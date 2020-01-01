#include "sprite_manipulation.hpp"
#include <math.h>

namespace Gengine
{
	void rotateSprite(sf::Sprite &sprite, sf::Clock &clock, float period, float speed)
	{
		if (clock.getElapsedTime().asSeconds() > period) {
			sprite.rotate(speed);
			clock.restart();
		}
	}

	void fadeInSprite(sf::Sprite &sprite, sf::Clock &clock)
	{
		auto temp_color = sprite.getColor();
		
		if (clock.getElapsedTime().asSeconds() > 0.01f && temp_color.a < 255) {
			temp_color.a += 1;
			sprite.setColor(temp_color);
			clock.restart();
		}
	}

	void fadeOutSprite(sf::Sprite &sprite, sf::Clock &clock)
	{
		auto temp_color = sprite.getColor();
		
		if (clock.getElapsedTime().asSeconds() > 0.01f && temp_color.a != 0) {
			temp_color.a -= 1;
			sprite.setColor(temp_color);
			clock.restart();
		}
	}
	
	void rotateToMouse(sf::Sprite &sprite, sf::Vector2i mouse_pos)
	{
		float xDistance = mouse_pos.x - sprite.getPosition().x;
		float yDistance = mouse_pos.y - sprite.getPosition().y;

		double rotationAngle = atan2(yDistance, xDistance) * (180/3.14159);

		sprite.setRotation(rotationAngle);
	}

	void animate(sf::Sprite &sprite, anim_t &anim)
	{
		if (anim.i != anim.anim_rect.end() && anim.clock.getElapsedTime().asSeconds() > 0.1f ) {
			anim.i += 1;
			anim.clock.restart();
		}
		else 
			anim.i = anim.anim_rect.begin();
		sprite.setTextureRect(*anim.i);
	}

	bool is_colliding(sf::Sprite &sprite, sf::Sprite & sprite2)
	{
		return (sprite.getGlobalBounds().intersects(sprite2.getGlobalBounds()));
	}
}