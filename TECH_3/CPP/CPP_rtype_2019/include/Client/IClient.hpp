#pragma once

#include <string>
class IClient
{
    private:
        /* data */
    public:
        // virtual ~IClient() {};
        virtual void init(std::string port, std::string host , int client_nb) = 0;
        virtual void run() = 0;

};