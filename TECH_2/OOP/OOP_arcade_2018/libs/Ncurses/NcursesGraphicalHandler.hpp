/*
** EPITECH PROJECT, 2018
** OOP_arcade_2018
** File description:
** NcursesGraphicalHandler.hpp
*/

#pragma once
#include "IGraphicalLibHandler.hpp"
#include <curses.h>
#include <algorithm>

namespace arcade
{
    class NcursesGraphicalHandler : public IGraphicalHandler {
        public:
            NcursesGraphicalHandler();
            void initialize(const std::string &window_name);
            void drawShape(shape_t shape_type, color_t color, vector_t pos, vector_t size, const std::string path_to_file = "[none]");
            void drawText(vector_t pos, const std::string &text);
            void clear();
            void free_ressources();
            keys_t getInput();
            menu_handle_t runArcadeMenu(std::string, std::string currently);
            void setWindowSize(vector_t size);
        private:
            WINDOW *_win;
            int _border_x_pos = 0;
            int _border_y_pos = 0;
    };

typedef struct keys_combi_s {
    int key;
    keys_t key_r;
} keys_combi_t;

    std::vector<keys_combi_t> keyboard_key_g =
    {
        {'a', keys_t::KEYBOARDKEY_A},
        {'b', keys_t::KEYBOARDKEY_B},
        {'c', keys_t::KEYBOARDKEY_C},
        {'d', keys_t::KEYBOARDKEY_D},
        {'e', keys_t::KEYBOARDKEY_E},
        {'f', keys_t::KEYBOARDKEY_F},
        {'g', keys_t::KEYBOARDKEY_G},
        {'h', keys_t::KEYBOARDKEY_H},
        {'i', keys_t::KEYBOARDKEY_I},
        {'j', keys_t::KEYBOARDKEY_J},
        {'k', keys_t::KEYBOARDKEY_K},
        {'l', keys_t::KEYBOARDKEY_L},
        {'m', keys_t::KEYBOARDKEY_M},
        {'n', keys_t::KEYBOARDKEY_N},
        {'o', keys_t::KEYBOARDKEY_O},
        {'p', keys_t::KEYBOARDKEY_P},
        {'q', keys_t::KEYBOARDKEY_Q},
        {'r', keys_t::KEYBOARDKEY_R},
        {'s', keys_t::KEYBOARDKEY_S},
        {'t', keys_t::KEYBOARDKEY_T},
        {'u', keys_t::KEYBOARDKEY_U},
        {'v', keys_t::KEYBOARDKEY_V},
        {'w', keys_t::KEYBOARDKEY_W},
        {'x', keys_t::KEYBOARDKEY_X},
        {'y', keys_t::KEYBOARDKEY_Y},
        {'z', keys_t::KEYBOARDKEY_Z},
        {KEY_LEFT, keys_t::KEYBOARDKEY_LEFT},
        {KEY_RIGHT, keys_t::KEYBOARDKEY_RIGHT},
        {KEY_UP, keys_t::KEYBOARDKEY_UP},
        {KEY_DOWN, keys_t::KEYBOARDKEY_DOWN},
        {'\0', keys_t::NO_KEY_PRESSED}
    };
};