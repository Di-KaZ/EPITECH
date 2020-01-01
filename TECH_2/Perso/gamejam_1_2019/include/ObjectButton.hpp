#pragma once

#include "GameObject.hpp"

namespace Gengine
{
	class ObjectButton : public GameObject
	{
		public:
			ObjectButton(const std::string &type, sf::Texture &texture);
			~ObjectButton();
			void ObjectDisplay(sf::RenderWindow &window);
			void Initialize(const sf::Font &font, const std::string &text);
		private:
			sf::Text _text;
	};
}