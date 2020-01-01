#pragma once
#include "IObject.hpp"
#include "Player.hpp"

class ObjectFactory {
    public:
        static std::shared_ptr<IObject> createObject(const std::string &);
    private:
        static std::shared_ptr<IObject> createplayer(const std::string &);
};