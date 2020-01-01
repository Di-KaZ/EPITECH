/*
** EPITECH PROJECT, 2019
** CCP_plazza_2018
** File description:
** Clock
*/

#include <stdio.h>
#include <chrono>

class Clock {
    public:
        enum class unit_t {
            SECOND,
            MINUTE,
            MILLISECOND
        };
        Clock();
        ~Clock();
        float getElapsedTime(unit_t unit = unit_t::SECOND);
        void reset();
    private:
        std::chrono::steady_clock::time_point _begin;
};