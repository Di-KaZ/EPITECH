#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>
#include <array>
#include "State.hpp"
#include "Game.hpp"
#include "GameObject.hpp"
#include "Player.hpp"
#include "Bailiff.hpp"
#include "Score.hpp"

namespace Gengine
{
    class StateLvl1 : public State {
    public:
	StateLvl1(GameDataRef data);
	void Init();
	void HandleInput();
	void Update(float dt);
	void Draw(float dt);
	GameObject *getPlayer();
    private:
	sf::Sprite _house;
	sf::Sprite _background;
	std::vector<Bailiff> _objectList;
	std::vector<Poele> _poeleList;
	Player *_player;
	sf::Sprite _stars;
	GameDataRef _data;
	sf::Clock _clock;
	sf::Clock _clockSpawn;
	sf::Clock _clockTic;
	sf::Clock _clockFire;
	Score _score;
	std::array<sf::SoundBuffer, 4> _buffer;
	std::array<sf::Sound, 4> _sound;
    };
}
