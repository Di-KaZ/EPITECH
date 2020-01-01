#include "CoreClient.hpp"

CoreClient::CoreClient(std::string ip, int port)
{
    _i_client = new BabelUdpClient();

    _i_client->connectToServer(ip, port);
}

CoreClient::~CoreClient()
{

}

void CoreClient::run()
{
    unsigned long read_len = _BYTE_NUM_;
    unsigned long write_len = _BYTE_NUM_;
    float *sample = nullptr;
    // std::vector<float *> samples_recived;
    float *recived = nullptr;

    while (true) {
        recived = (float *)malloc(_BYTE_NUM_);
        if (!recived)
            throw "shiet happens";
        _i_client->readData(&recived, read_len);
        audio.play(recived);
        free(recived);
        sample = audio.record();
        _i_client->sendData(sample, write_len);
    }
}