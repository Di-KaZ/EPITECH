#pragma once
#include <string>
#include <memory>
#include "Game.hpp"

class Command;
namespace ECS
{
    enum type {
        SHIP,
        BULLET,
        ENEMY
    };
    enum command {
        DEL,
        SETPOS
    };
};
class IObject {
    public:
        ~IObject() {};
        void setGameDataRef(GameDataRef data) {_data = data;};
        virtual void init() = 0;
        virtual void executeCommand(const Command &) = 0;
        virtual void draw() = 0;
        virtual std::string toString() const = 0;
        const int &getID() const { return _id;};
        void setID(const int &id) { _id = id;};
        IObject() {};
    protected:
        int _id;
        GameDataRef _data;
};