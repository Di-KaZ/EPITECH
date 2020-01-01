#pragma once

#include <SFML/Graphics.hpp>
#include "State.hpp"
#include "Game.hpp"
#include "sprite_manipulation.hpp"
#include <SFML/Audio.hpp>

namespace Gengine
{
	class StateMenu : public State {
		public:
			StateMenu(GameDataRef data);
			void Init();
			void HandleInput();
			void Update(float dt);
			void Draw(float dt);
		private:
			void yoo();
			sf::Sprite _play_button;
			sf::Sprite _background;
			sf::Sprite _yoo;
			sf::Sprite _quit_button;
			sf::Sprite _planet;
			sf::Music _music;
			GameDataRef _data;
			sf::Clock _clock;
			sf::Sprite test;
			anim_t test_a;
	};
}