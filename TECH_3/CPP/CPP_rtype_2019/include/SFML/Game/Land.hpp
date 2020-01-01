#pragma once

#include <SFML/Graphics.hpp>
#include "Game.hpp"
#include <vector>
#include <memory>
class Land
	{
	public:
		Land(GameDataRef data);

		void MoveLand(float dt);
		void DrawLand();

	private:
		GameDataRef _data;
		std::shared_ptr<sf::Sprite> land1;
		std::shared_ptr<sf::Sprite> land2;
	};