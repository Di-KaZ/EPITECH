#pragma once

#include <string>
#include "UDPClient.hpp"

class IGame {
    public:
        virtual void init(unsigned int width, unsigned int height, std::string title, std::shared_ptr<UDPClient> udp_client) = 0;
        virtual void run() = 0;
};