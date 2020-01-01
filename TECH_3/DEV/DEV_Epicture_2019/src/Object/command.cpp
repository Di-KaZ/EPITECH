#include "Command.hpp"

Command::Command(const std::string &command)
{
    std::vector<std::string> words;
    std::stringstream ss(command);

    while (ss) {
        std::string word;
        ss >> word;
        words.push_back(word);
    }
    _id = std::stoi(words[0]);
    _type = convertType(words[1]);
    _command = convertCommand(words[2]);
    _pos = sf::Vector2f(std::stoi(words[3]), std::stoi(words[4]));
}

Command::~Command()
{

}

const int &Command::getID() const
{
    return _id;
}

const ECS::command &Command::getCommand() const
{
    return _command;
}

const sf::Vector2f &Command::getPos() const
{
    return _pos;
}

const ECS::type &Command::getType() const
{
    return _type;
}


ECS::type Command::convertType(const std::string &yay)
{
    if (yay == "SHIP")
        return ECS::type::SHIP;
    if (yay == "ENEMY")
        return ECS::type::ENEMY;
    if (yay == "BULLET")
        return ECS::type::BULLET;
    return ECS::type::BULLET;
}

ECS::command Command::convertCommand(const std::string &yay)
{
    if (yay == "DEL")
        return ECS::command::DEL;
    if (yay == "SETPOS")
        return ECS::command::SETPOS;
    return ECS::command::SETPOS;
}