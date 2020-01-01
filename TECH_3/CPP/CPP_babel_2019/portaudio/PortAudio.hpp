/*
** ordCallbEPITECH PROJECT, 2019
** CPP_babel_2019
** File description:
** PortAudio.hpp
*/

#include <iostream>
#include <boost/array.hpp>
#include <boost/asio.hpp>
#include "portaudio.h"
#include <stdlib.h>
#include <vector>

#pragma once

#ifndef _SAMPLE_RATE_
#define _SAMPLE_RATE_ 44100
#endif

#ifndef _RECORD_TIME_
#define _RECORD_TIME_ 5
#endif

#ifndef _NUM_CHANNEL_
#define _NUM_CHANNEL_ 2
#endif

#ifndef _FRAMES_PER_BUFFER_
#define _FRAMES_PER_BUFFER_ 512
#endif

#ifndef _TOTAL_FRAMES_
#define _TOTAL_FRAMES_ _RECORD_TIME_ * _SAMPLE_RATE_
#endif

#ifndef _NUM_SAMPLE_
#define  _NUM_SAMPLE_ _TOTAL_FRAMES_ * _NUM_CHANNEL_
#endif

#ifndef _BYTE_NUM_
#define _BYTE_NUM_ _NUM_SAMPLE_ * sizeof(float)
#endif

// ok tu doit cre un seule callback qui va read et write en mm temp comme ca plus de pb de delais entre les deux

typedef struct {
    int frame_index;
    int last_frame;
    float *sound_buffer;
} record_data_t;

class PortAudioClass {
    public:
        PortAudioClass();
        ~PortAudioClass();
        float *record();
        void play(float *);
    private:
        static int recordCallback(const void *input_buffer, void *output_buffer,
                            unsigned long frames_per_buffer,
                            const PaStreamCallbackTimeInfo *time_info,
                            PaStreamCallbackFlags status,
                            void *user_data);
        static int playCallback(const void *input_buffer, void *output_buffer,
                        unsigned long frames_per_buffer,
                        const PaStreamCallbackTimeInfo *time_info,
                        PaStreamCallbackFlags status,
                        void *user_data);
        PaStreamParameters _input;
        PaStreamParameters _output;
        PaStream *_in_stream;
        PaStream *_out_stream;
        record_data_t _data;
};