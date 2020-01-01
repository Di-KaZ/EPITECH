#include "Game.hpp"
#include "GameState.hpp"

Game::Game()
{
}

void Game::init(unsigned int width, unsigned int height, std::string title, UDPClient *udp_client)
{
    _width = width;
    _height = height;
    _udp_client = udp_client;
    _data->window.create(sf::VideoMode(_width, _height), title, sf::Style::Default);
    _data->window.setFramerateLimit(59);
    _data->machine.AddState(StateRef(new GameState(_data, udp_client, _udp_client->getHost())));
}

void Game::run()
{
    float newTime, frameTime, interpolation;
    float currentTime = _clock.getElapsedTime().asSeconds();
    float accumulator = 0.0f;

    while (_data->window.isOpen())
    {
        _data->machine.ProcessStateChanges();
        newTime = _clock.getElapsedTime().asSeconds();
        frameTime = newTime - currentTime;

        if (frameTime > 0.25f)
            frameTime = 0.25f;

        currentTime = newTime;
        accumulator += frameTime;

        while (accumulator >= dt) {
				this->_data->machine.GetActiveState()->HandleInput();
				this->_data->machine.GetActiveState()->Update(dt);

				accumulator -= dt;
		}
        interpolation = accumulator / dt;
        _data->machine.GetActiveState()->Draw(interpolation);
    }
}