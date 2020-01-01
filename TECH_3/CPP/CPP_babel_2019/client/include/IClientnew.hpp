#include <string>
#pragma once
class IClient {
    public:
        virtual ~IClient()
            {
        
            };
        /*
        ** Send data to Server
        */
            virtual void sendData(void *data, long unsigned int &size) = 0;
        /*
        ** Read data from Server
        */
            virtual void readData(void *data, long unsigned int &size) = 0;
        /*
        ** Connect client to Server
        */
            virtual void connectToServer(std::string ip, int port) = 0;
};