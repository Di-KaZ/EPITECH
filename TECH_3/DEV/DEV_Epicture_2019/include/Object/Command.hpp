#pragma once
#include "IObject.hpp"
#include <sstream>
class Command {
    public:
        Command(const std::string &);
        ~Command();
        const int &getID() const;
        const ECS::command &getCommand() const;
        const ECS::type &getType() const;
        const sf::Vector2f &getPos() const;
    private:
        ECS::command convertCommand(const std::string &);
        ECS::type convertType(const std::string &);
        sf::Vector2f _pos;
        int _id;
        ECS::command _command;
        ECS::type _type;
};