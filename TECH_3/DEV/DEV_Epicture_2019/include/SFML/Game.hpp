#pragma once

#include <SFML/Graphics.hpp>
#include <memory>
#include "IGame.hpp"
#include "StateMachine.hpp"
#include "AssetManager.hpp"
#include "InputManager.hpp"
#include "UDPClient.hpp"

struct GameData {
    StateMachine machine;
    sf::RenderWindow window;
    AssetManager assets;
    InputManager input;
};

typedef std::shared_ptr<GameData> GameDataRef;

class Game : virtual public IGame {
    private:
        unsigned int _width;
        unsigned int _height;
        const float dt = 1.0f / 60.0f;
        sf::Clock _clock;
        GameDataRef _data = std::make_shared<GameData>();
        std::shared_ptr<UDPClient> _udp_client;
    public:
        Game();
        ~Game() {}
        void init(unsigned int width, unsigned int height, std::string title, std::shared_ptr<UDPClient> udp_client);
        void run() final;
};