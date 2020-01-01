#pragma once

#include <SFML/Graphics.hpp>
#include "State.hpp"
#include "Game.hpp"
#include "Land.hpp"
#include "ECSPlayer.hpp"
#include "UDPClient.hpp"
#include "IObject.hpp"
#include <memory>

class GameState : public State {
    public:
        GameState(GameDataRef data, std::shared_ptr<UDPClient> udp_client, int client_nb);
        ~GameState() {};
        void Init();
        void HandleInput();
        void Update(float dt);
        void Draw(float dt);
    private:
        GameDataRef _data;
        std::shared_ptr<UDPClient> _udp_client;
        int _client_nb;
        sf::Clock _clock;
        std::map<int, IObject*> _objects; // used to store all object on screen
        /* data */
        std::unique_ptr<ECSPlayer> _player;
        std::unique_ptr<Land> _land;
};