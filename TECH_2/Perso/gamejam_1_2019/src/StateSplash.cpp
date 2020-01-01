#include "StateSplash.hpp"
#include <sstream>
#include "Definition.hpp"
#include <iostream>
#include "sprite_manipulation.hpp"
#include "StateMenu.hpp"

namespace Gengine
{
	StateSplash::StateSplash(GameDataRef data) : _data(data)
	{

	}

	void StateSplash::Init()
	{
		this->_data->assets.LoadTexturesFromFile(SLPASH_R_PATH);
		this->_background.setTexture(this->_data->assets.GetTexture("Slpash_Background"));
		this->_bg.setTexture(this->_data->assets.GetTexture("BG"));
		this->_background.setColor(sf::Color(255,255,255, 0));
	}

	void StateSplash::HandleInput()
	{
		sf::Event event;

		while (_data->window.pollEvent(event))
		{
			if (sf::Event::Closed == event.type)
				this->_data->window.close();
			if (sf::Event::KeyPressed == event.type)
				_data->machine.AddState(StateRef(new StateMenu(_data)));
		}
	}

	void StateSplash::Update(float dt)
	{
		if (this->_clock.getElapsedTime().asSeconds() > SPLASH_TIME) {
			_data->machine.AddState(StateRef(new StateMenu(_data)));	
		}
		fadeInSprite(this->_background, this->_clock);
	}

	void StateSplash::Draw(float dt)
	{
		this->_data->window.clear();
		this->_data->window.draw(_bg);
		this->_data->window.draw(_background);
		this->_data->window.display();
	}
}