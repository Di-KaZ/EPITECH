#include <sstream>
#include <iostream>
#include "GameState.hpp"

GameState::GameState(GameDataRef data, std::shared_ptr<UDPClient> udp_client, int client_nb) : _data(data), _udp_client(udp_client), _client_nb(client_nb)
{
}

void GameState::Init()
{
    this->_data->assets.LoadTexture("Land", "./sprites/background.jpg");
	this->_data->assets.LoadTexture("Player", "./sprites/r-typesheet42.gif", sf::IntRect(0, 0, 33, 17));

    _land = std::make_unique<Land>(Land(_data));
    for (int i = 0; i < 4; i += 1) {
        auto temp_player = new ECSPlayer();
        temp_player->setGameDataRef(_data);
        temp_player->init();
        temp_player->setID(i);
        _objects[i] = dynamic_cast<IObject *>(temp_player);
    }
}

void GameState::HandleInput()
{
    sf::Event event;

    while (this->_data->window.pollEvent(event)) {

        if (sf::Event::Closed == event.type) {
			this->_data->window.close();
		}
        dynamic_cast<ECSPlayer *>(_objects[_udp_client->getHost()])->move(this->_data->input.GetDirectionInput());
	}
}

void GameState::Update(float dt)
{
    // !TODO! redseign update function to use ecs
    /*
        le but c'est de pouvoir bouger son player de send c'est info au autres
        et de recevoir la pos des autre player et de les afficher au bon endroit
        le serveur va jsute servir de relais
    */
    _land->MoveLand(dt);
    std::string pos = dynamic_cast<ECSPlayer *>(_objects[_udp_client->getHost()])->toString();
    _udp_client->handleSend(pos);
    Command recv(_udp_client->handleReceive());
    
    _objects[recv.getID()]->executeCommand(recv);
}

void GameState::Draw(float dt)
{
    this->_data->window.clear(sf::Color::Red);

	_land->DrawLand();
    for (auto i : _objects) {
        i.second->draw();
    }

    this->_data->window.display();
}