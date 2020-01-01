#pragma once

#include <SFML/Graphics.hpp>
#include "State.hpp"
#include "Game.hpp"
#include "Land.hpp"
#include "Player.hpp"
#include "UDPClient.hpp"

class GameState : public State
{
public:
    GameState(GameDataRef data, UDPClient *udp_client, int client_nb);
    ~GameState() {};

    void Init();

    void HandleInput();
    void Update(float dt);
    void Draw(float dt);

private:
    GameDataRef _data;
    UDPClient *_udp_client;
    int _client_nb;
    // sf::Sprite _background;
    sf::Clock _clock;
	Player *_player;
	Land *_land;

};