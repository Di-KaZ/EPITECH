/*
** EPITECH PROJECT, 2018
** OOP_arcade_2018
** File description:
** SFMLGraphicalHandler.hpp
*/

#pragma once
#include "IGraphicalLibHandler.hpp"
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <algorithm>

namespace arcade
{
    class SFMLGraphicalHandler : public IGraphicalHandler {
        public:
            SFMLGraphicalHandler();
            void initialize(const std::string &window_name);
            void drawShape(shape_t shape_type, color_t color, vector_t pos, vector_t size, const std::string path_to_file = "");
            void drawText(vector_t pos, const std::string &text);
            void clear();
            keys_t getInput();
            void free_ressources();
            menu_handle_t runArcadeMenu(std::string, std::string currently);
            void setWindowSize(vector_t size);
        private:
            void drawSquare(color_t color, vector_t pos, vector_t size, const std::string path_to_file, sf::RenderWindow &win);
            void drawCircle(color_t color, vector_t pos, vector_t size, const std::string path_to_file, sf::RenderWindow &win);
            sf::RenderWindow _win;
            std::map<std::string, sf::Texture *> _texture_map;
            sf::Font _font;
            sf::Text _text;
            sf::CircleShape _circle;
            sf::RectangleShape _rectangle;
            type_t _menu_status = type_t::GAME;
    };

    typedef struct keys_combi_s {
        sf::Keyboard::Key key;
        keys_t key_r;
    } keys_combi_t;

    std::vector<keys_combi_t> keyboard_key_g =
    {
        {sf::Keyboard::A, keys_t::KEYBOARDKEY_A},
        {sf::Keyboard::B, keys_t::KEYBOARDKEY_B},
        {sf::Keyboard::C, keys_t::KEYBOARDKEY_C},
        {sf::Keyboard::D, keys_t::KEYBOARDKEY_D},
        {sf::Keyboard::E, keys_t::KEYBOARDKEY_E},
        {sf::Keyboard::F, keys_t::KEYBOARDKEY_F},
        {sf::Keyboard::G, keys_t::KEYBOARDKEY_G},
        {sf::Keyboard::H, keys_t::KEYBOARDKEY_H},
        {sf::Keyboard::I, keys_t::KEYBOARDKEY_I},
        {sf::Keyboard::J, keys_t::KEYBOARDKEY_J},
        {sf::Keyboard::K, keys_t::KEYBOARDKEY_K},
        {sf::Keyboard::L, keys_t::KEYBOARDKEY_L},
        {sf::Keyboard::M, keys_t::KEYBOARDKEY_M},
        {sf::Keyboard::N, keys_t::KEYBOARDKEY_N},
        {sf::Keyboard::O, keys_t::KEYBOARDKEY_O},
        {sf::Keyboard::P, keys_t::KEYBOARDKEY_P},
        {sf::Keyboard::Q, keys_t::KEYBOARDKEY_Q},
        {sf::Keyboard::R, keys_t::KEYBOARDKEY_R},
        {sf::Keyboard::S, keys_t::KEYBOARDKEY_S},
        {sf::Keyboard::T, keys_t::KEYBOARDKEY_T},
        {sf::Keyboard::U, keys_t::KEYBOARDKEY_U},
        {sf::Keyboard::V, keys_t::KEYBOARDKEY_V},
        {sf::Keyboard::W, keys_t::KEYBOARDKEY_W},
        {sf::Keyboard::X, keys_t::KEYBOARDKEY_X},
        {sf::Keyboard::Y, keys_t::KEYBOARDKEY_Y},
        {sf::Keyboard::Z, keys_t::KEYBOARDKEY_Z},
        {sf::Keyboard::Left, keys_t::KEYBOARDKEY_LEFT},
        {sf::Keyboard::Right, keys_t::KEYBOARDKEY_RIGHT},
        {sf::Keyboard::Up, keys_t::KEYBOARDKEY_UP},
        {sf::Keyboard::Down, keys_t::KEYBOARDKEY_DOWN}
    };
}