#pragma once
#include "IObject.hpp"
#include "Command.hpp"
#include "Move.hpp"

class ECSPlayer : public IObject {
    public:
        ECSPlayer();
        ~ECSPlayer();
        void draw();
        void init();
        void move(const Move &dir);
        bool checkMove(const Move &dir) {return true;}
        void executeCommand(const Command &);
        std::string toString() const;
    private:
        sf::Sprite _sprite;
        sf::Vector2f _pos;
};