#include <sstream>
#include <iostream>
#include "GameState.hpp"

GameState::GameState(GameDataRef data, UDPClient *udp_client, int client_nb) : _data(data), _udp_client(udp_client), _client_nb(client_nb)
{
}

void GameState::Init()
{
    this->_data->assets.LoadTexture("Land", "./sprites/background.jpg");
	this->_data->assets.LoadTexture("Player", "./sprites/r-typesheet42.gif", sf::IntRect(0, 0, 33, 17));

    // _background.setTexture(this->_data->assets.GetTexture("Game Background"));

    _land = new Land(_data);
    _player = new Player(_data);
}

void GameState::HandleInput()
{
    sf::Event event;

    while (this->_data->window.pollEvent(event)) {

        if (sf::Event::Closed == event.type) {
			this->_data->window.close();
		}
        _player->move(this->_data->input.GetDirectionInput());
	}
}

void GameState::Update(float dt)
{
	_land->MoveLand(dt);
    int x = _player->getPosX();
    int y = _player->getPosY();

    // if (_clock.getElapsedTime().asSeconds() > 0.2) {
        std::string pos = std::to_string(_client_nb) + " " + std::to_string(x) + " " + std::to_string(y);
        _udp_client->handleSend(pos);
        std::string recv(_udp_client->handleReceive());
        std::cout << recv << std::endl;
        // _clock.restart();
    // }
    // udp SERVER -> PLAYER [name] [x] [y] [life]

}

void GameState::Draw(float dt)
{
    this->_data->window.clear(sf::Color::Red);

    // this->_data->window.draw(this->_background);
	_land->DrawLand();
    _player->Draw();


    this->_data->window.display();
}