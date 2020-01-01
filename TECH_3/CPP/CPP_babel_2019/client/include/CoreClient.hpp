#include "IClientnew.hpp"
#include "BabelUdpClient.hpp"
#include "PortAudio.hpp"

#pragma once
class CoreClient {
    public:
        CoreClient(std::string ip, int port);
        ~CoreClient();
        void run();
    private:
        PortAudioClass audio;
        IClient *_i_client;
};
