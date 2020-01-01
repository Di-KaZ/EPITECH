#include "StateScoreboard.hpp"
#include <sstream>
#include "Definition.hpp"
#include <iostream>
#include "sprite_manipulation.hpp"
#include "StateMenu.hpp"

namespace Gengine
{
	StateScoreboard::StateScoreboard(GameDataRef data) : _data(data)
	{

	}

	void StateScoreboard::Init()
	{
		this->_data->assets.LoadTexturesFromFile(END_R_PATH);
		this->_background.setTexture(this->_data->assets.GetTexture("gameOver"));
		this->_retry_button.setPosition(0, 700);
		this->_quit_button.setTexture(this->_data->assets.GetTexture("Button_Quit"));
		this->_retry_button.setTexture(this->_data->assets.GetTexture("Button_Retry"));
	}

	void StateScoreboard::HandleInput()
	{
		sf::Event event;

		while (_data->window.pollEvent(event))
		{
			if (sf::Event::Closed == event.type)
				this->_data->window.close();
		}
		if (this->_data->input.isSpriteClicked(this->_quit_button, sf::Mouse::Left, _data->window)) {
			this->_data->window.close();
		}
		if (this->_data->input.isSpriteClicked(this->_retry_button, sf::Mouse::Left, _data->window)) {
			_data->machine.AddState(StateRef(new StateMenu(_data)));
		}
	}

	void StateScoreboard::Update(float dt)
	{

	}

	void StateScoreboard::Draw(float dt)
	{
		this->_data->window.clear();
		this->_data->window.draw(_background);
		this->_data->window.draw(this->_retry_button);
		this->_data->window.draw(this->_quit_button);
		this->_data->window.display();
	}
}