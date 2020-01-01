#pragma once

#include <SFML/Graphics.hpp>
#include "State.hpp"
#include "Game.hpp"

namespace Gengine
{
	class StateScoreboard : public State {
		public:
			StateScoreboard(GameDataRef data);
			void Init();
			void HandleInput();
			void Update(float dt);
			void Draw(float dt);
		private:
			 GameDataRef _data;
			 sf::Clock _clock;
			 sf::Sprite _background;
			 sf::Sprite _retry_button;
			 sf::Sprite _quit_button;
	};
}