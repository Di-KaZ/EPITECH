/*
** EPITECH PROJECT, 2019
** CCP_plazza_2018
** File description:
** Clock
*/

#include "Clock.hpp"

Clock::Clock()
{
    _begin = std::chrono::steady_clock::now();
}

float Clock::getElapsedTime(unit_t unit)
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

void Clock::reset()
{
    _begin = std::chrono::steady_clock::now();
}

Clock::~Clock()
{
}
