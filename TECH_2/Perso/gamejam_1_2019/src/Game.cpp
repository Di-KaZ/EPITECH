#include "Game.hpp"
#include "StateSplash.hpp"

namespace Gengine
{
	Game::Game(int width, int height, const std::string &title)
	{
		this->_data->window.create(sf::VideoMode(width, height, sf::Style::Titlebar | sf::Style::Close), title);
		this->_data->machine.AddState(StateRef(new StateSplash(this->_data)));
		this->_data->window.setFramerateLimit(60);
		this->Run();
	}

	void Game::Run()
	{
		float newTime;
		float frameTime;
		float interpolation;

		float currentTime = this->_clock.getElapsedTime().asSeconds();
		float accumulator = 0.0f;

		while (this->_data->window.isOpen()) {
			this->_data->machine.ProcessStateChanges();
			newTime = this->_clock.getElapsedTime().asSeconds();
			frameTime = newTime - currentTime;
			if (frameTime > 0.25f) {
				frameTime = 0.25f;
			}
			currentTime = newTime;
			accumulator += frameTime;
			while (accumulator >= dt) {
				this->_data->machine.GetActiveState()->HandleInput();
				this->_data->machine.GetActiveState()->Update(dt);
				accumulator -= dt;
			}
			interpolation = accumulator / dt;
			this->_data->machine.GetActiveState()->Draw(interpolation);
		}
	}
}