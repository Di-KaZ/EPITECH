/*
** EPITECH PROJECT, 2019
** CPP_babel_2019
** File description:
** PortAudio.cpp
*/

#include "PortAudio.hpp"
#include <iostream>

PortAudioClass::PortAudioClass()
{
    Pa_Initialize();
    _input.device = Pa_GetDefaultInputDevice();
    _input.channelCount = _NUM_CHANNEL_;
    _input.sampleFormat = paFloat32;
    _input.suggestedLatency = Pa_GetDeviceInfo(_input.device)->defaultLowInputLatency;
    _input.hostApiSpecificStreamInfo = nullptr;
    _output.device = Pa_GetDefaultOutputDevice();
    _output.channelCount = _NUM_CHANNEL_;
    _output.sampleFormat = paFloat32;
    _output.suggestedLatency = Pa_GetDeviceInfo(_output.device)->defaultLowOutputLatency;
    _output.hostApiSpecificStreamInfo = nullptr;
    _data.frame_index = 0;
    _data.sound_buffer = (float *)malloc(_BYTE_NUM_);
    if (_data.sound_buffer == nullptr)
        throw std::string("waaaaaaa");
}

PortAudioClass::~PortAudioClass()
{
}

float *PortAudioClass::record()
{
    float *to_send_data = (float *)malloc(_TOTAL_FRAMES_);
    for (int i = 0; i < _TOTAL_FRAMES_; i ++)
        _data.sound_buffer[i] = 0;
    Pa_OpenStream(&_in_stream, &_input, nullptr, _SAMPLE_RATE_, _FRAMES_PER_BUFFER_, paClipOff, PortAudioClass::recordCallback, &_data);
    Pa_StartStream(_in_stream);
    while(Pa_IsStreamActive(_in_stream) == 1)
        Pa_Sleep(1000);
    Pa_CloseStream(_in_stream);
    memcpy(to_send_data, _data.sound_buffer, sizeof(*to_send_data));
    return to_send_data;
}

void PortAudioClass::play(float *buff)
{
    record_data_t data;
    data.frame_index = 0;
    data.last_frame = _RECORD_TIME_ * _SAMPLE_RATE_;
    data.sound_buffer = buff;
    Pa_OpenStream(&_out_stream, nullptr, &_output, _SAMPLE_RATE_, _FRAMES_PER_BUFFER_, paClipOff, PortAudioClass::playCallback, &data);
    Pa_StartStream(_out_stream);
    while(Pa_IsStreamActive(_out_stream) == 1)
        Pa_Sleep(100);
    Pa_CloseStream(_out_stream);
}

int PortAudioClass::recordCallback(const void *input_buffer, void *output_buffer,
                            unsigned long frame_pet_buffer,
                            const PaStreamCallbackTimeInfo *timeInfo,
                            PaStreamCallbackFlags statusFlags,
                            void *userData)
{
    record_data_t *data = (record_data_t *)userData;
    const float *rptr = (const float *)input_buffer;
    float *wptr = &data->sound_buffer[data->frame_index * _NUM_CHANNEL_];
    long frames_to_calc;
    long i;
    int finished;
    unsigned long frames_left = data->last_frame - data->frame_index;


    if (frames_left < frame_pet_buffer) {
        frames_to_calc = frames_left;
        finished = paComplete;
    }
    else {
        frames_to_calc = frame_pet_buffer;
        finished = paContinue;
    }
    if (input_buffer == nullptr) {
        for (i = 0; i < frames_to_calc; i ++) {
            *wptr++ = 0.0f;
            *wptr++ = 0.0f;
        }
    }
    else {
        for (i = 0; i < frames_to_calc; i ++) {
            *wptr++ = *rptr++;
            *wptr++ = *rptr++;
        }
    }
    data->frame_index += frames_to_calc;
    return finished;
}

int PortAudioClass::playCallback(const void *input_buffer, void *output_buffer,
                        unsigned long frames_per_buffer,
                        const PaStreamCallbackTimeInfo *time_info,
                        PaStreamCallbackFlags status,
                        void *user_data)
{
    record_data_t *data = (record_data_t *)user_data;
    float *rptr = &data->sound_buffer[data->frame_index * _NUM_CHANNEL_];
    float *wptr = (float *)output_buffer;
    unsigned int i;
    int finished;
    unsigned int frame_left = data->last_frame - data->frame_index;

    if (frame_left < frames_per_buffer) {
        for (i = 0; i < frame_left; i ++) {
            *wptr++ = *rptr++;
            *wptr++ = *rptr++;
        }
        for (; i < frames_per_buffer; i ++) {
            *wptr++ = 0;
            *wptr++ = 0;
        }
        data->frame_index += frame_left;
        finished = paComplete;
    }
    else {
        for (i = 0; i < frames_per_buffer; i ++) {
            for (i = 0; i < frames_per_buffer; i ++) {
                *wptr++= *rptr++;
                *wptr++= *rptr++;
            }
        }
        data->frame_index += frames_per_buffer;
        finished = paContinue;
    }
    return finished;
}