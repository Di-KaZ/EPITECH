#include "StateMenu.hpp"
#include "StateLvl1.hpp"
#include <sstream>
#include "Definition.hpp"
#include <iostream>
#include "sprite_manipulation.hpp"

namespace Gengine
{
	StateMenu::StateMenu(GameDataRef data) : _data(data)
	{

	}

	void StateMenu::Init()
	{
		this->_data->assets.LoadTexturesFromFile(MENU_R_PATH);
		this->_background.setTexture(this->_data->assets.GetTexture("Menu_Background"));
		this->_play_button.setTexture(this->_data->assets.GetTexture("Button_Play"));
		this->_quit_button.setTexture(this->_data->assets.GetTexture("Button_Quit"));
		this->_play_button.setPosition(1400 - this->_play_button.getGlobalBounds().width,
											650 - _play_button.getGlobalBounds().height);
		this->_yoo.setTexture(_data->assets.GetTexture("Yoo"));
		this->_yoo.setPosition(400, 450);
		this->_quit_button.setPosition(1600 - this->_quit_button.getGlobalBounds().width,
											850 - _quit_button.getGlobalBounds().height);
		this->_planet.setTexture(this->_data->assets.GetTexture("Planet"));
		this->_planet.setOrigin(this->_planet.getGlobalBounds().width / 2, this->_planet.getGlobalBounds().height / 2);
		this->_planet.setPosition(0, 740);
		this->_music.openFromFile("Audio/ChoixPerso.ogg");
		this->_music.play();
		this->_music.setLoop(true);
	}

	void StateMenu::HandleInput()
	{
		sf::Event event;

		while (_data->window.pollEvent(event))
		{
			if (sf::Event::Closed == event.type)
				this->_data->window.close();
		}
		if (_data->input.isSpriteClicked(this->_play_button, sf::Mouse::Left, _data->window)) {
			this->_music.stop();
			this->_music.~SoundSource();
		    this->_data->machine.AddState(StateRef(new StateLvl1(this->_data)));
		}
		if (_data->input.isSpriteClicked(this->_quit_button, sf::Mouse::Left, _data->window)) {
			this->_music.stop();
			this->_music.~SoundSource();
		    this->_data->window.close();
		}
	}

	void StateMenu::Update(float dt)
	{
		rotateSprite(this->_planet, this->_clock, 0.05f, 0.2f);
		yoo();
	}

	void StateMenu::Draw(float dt)
	{
		this->_data->window.clear();
		this->_data->window.draw(this->_background);
		this->_data->window.draw(this->_play_button);
		this->_data->window.draw(this->_quit_button);
		this->_data->window.draw(this->_planet);
		this->_data->window.draw(this->test);
		this->_data->window.draw(this->_yoo);
		this->_data->window.display();
	}

	void StateMenu::yoo()
	{
		float scaling = this->_yoo.getScale().x;

		if (scaling != 5)
			this->_yoo.scale(1.001, 1.001);
		this->_yoo.move(1, -1);
	}
}
