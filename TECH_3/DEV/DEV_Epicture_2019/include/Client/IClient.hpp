#pragma once

#include <string>
class IClient
{
    private:
    public:
        virtual void init(std::string port, std::string host , int client_nb) = 0;
        virtual void run() = 0;

};