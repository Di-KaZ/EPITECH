/*
** EPITECH PROJECT, 2018
** OOP_arcade_2018
** File description:
** SFMLGraphicalHandler.cpp
*/

#include "SFMLGraphicalHandler.hpp"

namespace arcade
{
    static sf::Color get_color(const color_t &color)
    {
        switch (color)
        {
            case color_t::BLACK :
                return (sf::Color::Black);
            case color_t::BLUE :
                return (sf::Color::Blue);
            case color_t::GREEN :
                return (sf::Color::Green);
            case color_t::RED :
                return (sf::Color::Red);
            case color_t::WHITE :
                return (sf::Color::White);
            case color_t::YELLOW :
                return (sf::Color::Yellow);
            case color_t::MAGENTA :
                return (sf::Color::Magenta);
            case color_t::CYAN :
                return (sf::Color::Cyan);
        }
        return (sf::Color::White);
    }

    SFMLGraphicalHandler::SFMLGraphicalHandler()
    {
        if (!_font.loadFromFile("./libs/sfml/font.ttf")) {
            std::cerr << "[ERROR] : unable to load font for sfml handler." << std::endl;
            exit (84);
        }
        _text.setFont(_font);
    }

    void SFMLGraphicalHandler::initialize(const std::string &window_name) 
    {
        if (!_win.isOpen()) {
            _win.create(sf::VideoMode(1280, 720),"Arcade");
            return;
        }
        _win.setSize(sf::Vector2u(1280, 720));
        _win.setTitle(window_name);
        _win.setView(sf::View(sf::FloatRect(0, 0, 1280, 720)));
    }

    void SFMLGraphicalHandler::drawSquare(color_t color, vector_t pos, vector_t size, const std::string path_to_file, sf::RenderWindow &win) 
    {
            _rectangle.setSize(sf::Vector2f(size.x * 32, size.y * 32));
            if (path_to_file != "[none]") {
                if (_texture_map.find(path_to_file) == _texture_map.end()) {
                    sf::Texture *text = new sf::Texture;
                    if (!text->loadFromFile(path_to_file)) {
                        _rectangle.setFillColor(get_color(color));
                        std::cerr << "[ERROR] : could not load texture \"" << path_to_file << "\" please verify the path." << std::endl;
                    } else {
                        _texture_map[path_to_file] = text;
                        _rectangle.setTexture(text);
                    }
                }
                _rectangle.setTexture(_texture_map[path_to_file]);
            } else {
                _rectangle.setFillColor(get_color(color));
            }
                _rectangle.setPosition(sf::Vector2f(pos.y * 32, pos.x * 32));
            win.draw(_rectangle);
    }
    void SFMLGraphicalHandler::drawCircle(color_t color, vector_t pos, vector_t size, const std::string path_to_file, sf::RenderWindow &win) 
    {
            _circle.setRadius(size.x * 16);
            if (path_to_file != "[none]") {
                if (_texture_map.find(path_to_file) == _texture_map.end()) {
                    sf::Texture *text = new sf::Texture;
                    if (!text->loadFromFile(path_to_file)) {
                        _circle.setFillColor(get_color(color));
                        std::cerr << "[ERROR] : could not load texture \"" << path_to_file << "\" please verify the path." << std::endl;
                    } else {
                        _texture_map[path_to_file] = text;
                        _circle.setTexture(text);
                    }
                }
                _circle.setTexture(_texture_map[path_to_file]);
            } else {
                _circle.setFillColor(get_color(color));
            }
            _circle.setPosition(sf::Vector2f(pos.y * 32, pos.x * 32));
            win.draw(_circle);
    }
    void SFMLGraphicalHandler::drawShape(shape_t shape_type, color_t color, vector_t pos, vector_t size, const std::string path_to_file) 
    {
        _rectangle.setTexture(nullptr);
        _circle.setTexture(nullptr);
        if (shape_type == shape_t::SQUARE)
        {
            drawSquare(color, pos, size, path_to_file, _win);
            return;
        }
        if (shape_type == shape_t::CIRCLE)
        {
            drawCircle(color, pos, size, path_to_file, _win);
            return;
        }
    }
    void SFMLGraphicalHandler::drawText(vector_t pos, const std::string &text) 
    {
        pos.x = pos.x * 32;
        pos.y = pos.y * 32;
        _text.setPosition(sf::Vector2f(pos.y, pos.x));
        _text.setString(text);
        _win.draw(_text);
    }
    void SFMLGraphicalHandler::clear() 
    {
        _win.display();
        _win.clear(sf::Color::Black);
    }
    keys_t SFMLGraphicalHandler::getInput() 
    {
        sf::Event event;
        while (_win.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                return (keys_t::EXIT_SIGNAL);
            }
            if (event.type == sf::Event::KeyPressed)
                for (int i = 0; i != 30; i += 1)
                    if (event.key.code == keyboard_key_g[i].key)
                        return (keyboard_key_g[i].key_r);
        }
        return (keys_t::NO_KEY_PRESSED);
    }
    
    void SFMLGraphicalHandler::free_ressources() 
    {
        _win.close();
        std::cerr << "[SFMLlib] " << _texture_map.size() << " texture(s) loaded and freed." << std::endl;
        for (auto i = _texture_map.begin(); i != _texture_map.end(); i++) {
            delete(i->second);
        }
    }

    void SFMLGraphicalHandler::setWindowSize(vector_t size)
    {
        _win.setSize(sf::Vector2u(size.x * 32 - 2, size.y * 32 - 2));
        _win.setView(sf::View(sf::FloatRect(0, 0, size.x * 32 - 2, size.y * 32 - 2)));
    }

    menu_handle_t SFMLGraphicalHandler::runArcadeMenu(std::string currently, std::string currently2)
    {
        sf::Event event;
        int c_lib = 0;
        static bool status = true;
        std::string path_return;
        menu_handle_t handle = {type_t::GAME, "[none]"};
        sf::Text current_text;
        std::vector<std::string> lib_games_paths = getLibsPaths("./games/");
        std::vector<std::string> lib_graph_paths = getLibsPaths("./libs/");
        static int c_game = 0;
        std::string tmp;

        current_text.setFont(_font);
        _win.create(sf::VideoMode(1280, 720),"Arcade");
        _win.setFramerateLimit(60);
        while (_win.isOpen()) {
            _win.display();
            if (status) {
                handle.type = type_t::GAME;
                while (_win.pollEvent(event)) {
                    if (event.type == sf::Event::Closed) {
                        _win.close();
                        handle.path = "[QUIT]";
                    }
                    if (event.type == sf::Event::KeyPressed) {
                        if (event.key.code == sf::Keyboard::Key::Left) {
                                c_game -= 1;
                                if (c_game < 0)
                                    c_game = lib_games_paths.size() - 1;
                        }
                        if (event.key.code == sf::Keyboard::Key::Right) {
                                c_game += 1;
                                if (c_game >= lib_games_paths.size())
                                    c_game = 0;
                        }
                        if (event.key.code == sf::Keyboard::Space) {
                                tmp = lib_games_paths[c_game].substr(lib_games_paths[c_game].find_last_of('/') + 4);
                                std::replace(tmp.begin(), tmp.end(), '_', ' ');
                                if (currently == tmp) {
                                    handle.path = "[none]";
                                    return (handle);
                                }
                                handle.path = lib_games_paths[c_game];
                                return (handle);
                        }
                        if (event.key.code == sf::Keyboard::Up)
                                 status = false;
                        if (event.key.code == sf::Keyboard::Key::Escape) {
                                handle.path = "[QUIT]";
                                return (handle);
                        }
                    }
                }
                    _win.clear(sf::Color::Black);
                    std::replace(currently.begin(), currently.end(), '_', ' ');
                    current_text.setString("Now playing : " + currently.substr(currently.find_last_of('/') + 1, currently.find_last_of('.')));
                    current_text.setOrigin(sf::Vector2f(current_text.getGlobalBounds().width / 2, current_text.getGlobalBounds().height / 2));
                    current_text.setPosition(sf::Vector2f(1280 / 2, 50));
                    _win.draw(current_text);
                    current_text.setString("Play \"" + lib_games_paths[c_game].substr(lib_games_paths[c_game].find_last_of('/') + 1, lib_games_paths[c_game].find_last_of('.')) + "\"");
                    current_text.setOrigin(sf::Vector2f(current_text.getGlobalBounds().width / 2, current_text.getGlobalBounds().height / 2));
                    current_text.setPosition(sf::Vector2f(1280 / 2, 600));
                    _win.draw(current_text);
                    current_text.setString("Press [SPACE] or [UP/DOWN] to switch mode");
                    current_text.setOrigin(sf::Vector2f(current_text.getGlobalBounds().width / 2, current_text.getGlobalBounds().height / 2));
                    current_text.setPosition(sf::Vector2f(1280 / 2, 650));
                    _win.draw(current_text);
            }
            // DISPLAY GRAPHICAL MENU
            if (!status) {
                handle.type = type_t::GRAPHICAL;
                while (_win.pollEvent(event)) {
                    if (event.type == sf::Event::Closed)
                        _win.close();
                    if (event.type == sf::Event::KeyPressed) {
                        if (event.key.code == sf::Keyboard::Key::Left) {
                                c_lib -= 1;
                                if (c_lib < 0)
                                    c_lib = lib_graph_paths.size() - 1;
                        }
                        if (event.key.code == sf::Keyboard::Key::Right) {
                                c_lib += 1;
                                if (c_lib >= lib_graph_paths.size())
                                    c_lib = 0;
                        }
                        if (event.key.code == sf::Keyboard::Space) {
                                tmp = lib_graph_paths[c_lib].substr(lib_graph_paths[c_lib].find_last_of('/') + 4);
                                if (currently2 == tmp) {
                                    handle.path = "[none]";
                                    return (handle);
                                }
                                handle.path = lib_graph_paths[c_lib];
                                return (handle);
                        }
                        if (event.key.code == sf::Keyboard::Down)
                                 status = true;
                        if (event.key.code == sf::Keyboard::Key::Escape) {
                                handle.path = "[QUIT]";
                                return (handle);
                        }
                    }
                }
                    _win.clear(sf::Color::Black);
                    std::replace(currently.begin(), currently.end(), '_', ' ');
                    current_text.setString("Now using : " + currently.substr(currently.find_last_of('/') + 1, currently.find_last_of('.')));
                    current_text.setOrigin(sf::Vector2f(current_text.getGlobalBounds().width / 2, current_text.getGlobalBounds().height / 2));
                    current_text.setPosition(sf::Vector2f(1280 / 2, 50));
                    _win.draw(current_text);
                    current_text.setString("Change for : " + lib_graph_paths[c_lib].substr(lib_graph_paths[c_lib].find_last_of('/') + 1, lib_graph_paths[c_lib].find_last_of('.')) + "\"");
                    current_text.setOrigin(sf::Vector2f(current_text.getGlobalBounds().width / 2, current_text.getGlobalBounds().height / 2));
                    current_text.setPosition(sf::Vector2f(1280 / 2, 600));
                    _win.draw(current_text);
                    current_text.setString("Press [SPACE] or [UP/DOWN] to switch mode");
                    current_text.setOrigin(sf::Vector2f(current_text.getGlobalBounds().width / 2, current_text.getGlobalBounds().height / 2));
                    current_text.setPosition(sf::Vector2f(1280 / 2, 650));
                    _win.draw(current_text);
            }
        }
        return (handle);
    }
} // arcade

extern "C" arcade::IGraphicalHandler *entryPoint()
{
    return (new arcade::SFMLGraphicalHandler);
}
