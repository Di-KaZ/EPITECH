/*
** EPITECH PROJECT, 2018
** OOP_arcade_2018
** File description:
** Utils.hpp
*/

#pragma once
#include <stdio.h>
#include <chrono>

namespace arcade
{

    class Clock {
        public:
            enum class unit_t {
                SECOND,
                MINUTE,
                MILLISECOND
            };
            Clock()
            {
                _begin = std::chrono::steady_clock::now();
            }
            float getElapsedTime(unit_t unit = unit_t::SECOND)
            {
                std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
                std::chrono::duration<float, std::milli> diff = end - _begin;
                float return_val = 0;
                if (unit == unit_t::SECOND)
                    return_val = diff.count() / 1000;
                else if (unit == unit_t::MILLISECOND)
                    return_val = diff.count();
                else
                    return_val = diff.count() / 1000 / 60;
                return (return_val);
            }
            void reset()
            {
                _begin = std::chrono::steady_clock::now();
            }
        private:
            std::chrono::steady_clock::time_point _begin;
    };
    //used to simulate a 2D vector
    typedef struct vector_s {
        int x;
        int y;
    } vector_t;
    //used to define what shape to draw
    enum class shape_t {
        SQUARE,
        CIRCLE
    };
    //used to define color we want
    enum class color_t {
        BLACK,
        WHITE,
        RED,
        BLUE,
        GREEN,
        MAGENTA,
        YELLOW,
        CYAN
    };

    enum class type_t {
        GRAPHICAL,
        GAME
    };

    enum class status_t {
            PAUSE,
            RUN,
            QUIT
        };
    // get current key pressed
    enum class keys_t {
        KEYBOARDKEY_A,
        KEYBOARDKEY_B,
        KEYBOARDKEY_C,
        KEYBOARDKEY_D,
        KEYBOARDKEY_E,
        KEYBOARDKEY_F,
        KEYBOARDKEY_G,
        KEYBOARDKEY_H,
        KEYBOARDKEY_I,
        KEYBOARDKEY_J,
        KEYBOARDKEY_K,
        KEYBOARDKEY_L,
        KEYBOARDKEY_M,
        KEYBOARDKEY_N,
        KEYBOARDKEY_O,
        KEYBOARDKEY_P,
        KEYBOARDKEY_Q,
        KEYBOARDKEY_R,
        KEYBOARDKEY_S,
        KEYBOARDKEY_T,
        KEYBOARDKEY_U,
        KEYBOARDKEY_V,
        KEYBOARDKEY_W,
        KEYBOARDKEY_X,
        KEYBOARDKEY_Y,
        KEYBOARDKEY_Z,
        KEYBOARDKEY_LEFT,
        KEYBOARDKEY_RIGHT,
        KEYBOARDKEY_UP,
        KEYBOARDKEY_DOWN,
        NO_KEY_PRESSED = -1,
        EXIT_SIGNAL = -2
    };
} // arcade
