/*
** EPITECH PROJECT, 2019
** PSU_zappy_2018
** File description:
** client
*/

#include "zappy_client.hpp"

namespace ZappyClient
{
    Client::Client(const char **av)
    {
        _serv_adrr.sin_family = AF_INET;

        for (size_t i = 0; av[i]; i += 1) {
            if (strcmp(av[i], "-p") == 0 && av[i + 1] && strlen(av[i + 1]) == 4)
                try {
                    _port = std::stoi(av[i + 1]);
                } catch (const std::exception &e) {
                    std::cerr << e.what() << std::endl;
                    exit(84);
                }
            if (strcmp(av[i], "-n") == 0 && av[i + 1])
                _name = av[i + 1];
            if (strcmp(av[i], "-h") == 0 && av[i + 1])
                _machine = av[i + 1];
        }
        if (_name == "[None]" || _port == -1) {
            std::cerr << "error ine params" << std::endl;
            exit(84);
        }
        _font.loadFromFile("srcs/client/Minecrafter.Reg.ttf");
        _title_info.setFont(_font);
        _title_info.setColor(sf::Color::White);
        _map_info.setFont(_font);
        _map_info.setColor(sf::Color::White);
    }

    Client::~Client()
    {

    }

    int Client::runAI()
    {
        _window.create(sf::VideoMode(_width * 30 + 200, _height * 30), "Zappy Client", sf::Style::Titlebar);

        iniGraphMap();
        while(_window.isOpen()) {
            sf::Event event;
            _window.clear(sf::Color::Black);
            while(_window.pollEvent(event)) {
                if (event.type == sf::Event::Closed)
                    _window.close();
            }
            for (auto i : _map) {
                for (auto j : i) {
                    _window.draw(*j);
                }
            }
            if (_clock.getElapsedTime().asSeconds() > 0.5) {
                updateInfoOnTitle();
                updateMapInfo();
                _clock.restart();
            }
            _window.draw(_title_info);
            _window.draw(_map_info);
            _window.display();
        }
        return (0);
    }

    void Client::updateInfoOnTitle()
    {
        std::string send = "bct ";
        char buf[1024] = {0};

        int x = 0;
        int y = 0;

        for (auto i : _map) {
            for (auto j : i) {
                if (j.get()->getGlobalBounds().contains(sf::Mouse::getPosition(_window).x, sf::Mouse::getPosition(_window).y) == true) {
                    send += std::to_string(x);
                    send += " ";
                    send += std::to_string(y);
                    send += "\n";
                    dprintf(_fd, send.c_str());
                    read(_fd, &buf, 1024);
                    send = buf;
                    std::cout << "bct recived = " << send << std::endl;
                    _title_info.setString(parse_bct(send));
                    _title_info.setPosition(_width * 30 + 10, 0);
                }
                x += 1;
            }
            x = 0;
            y += 1;
        }
    }

    int Client::iniGraphMap()
    {
        std::shared_ptr<sf::RectangleShape> title;
        int y = 0;
        int x = 0;
        std::vector<std::shared_ptr<sf::RectangleShape>> line;
        

        for (int i = 0; i < _height; i += 1) {
            for (int j = 0; j < _width; j += 1) {
                title = std::shared_ptr<sf::RectangleShape>(new sf::RectangleShape(sf::Vector2f(30, 30)));
                title->setFillColor(sf::Color::Green);
                title->setOutlineThickness(1);
                title->setOutlineColor(sf::Color::Black);
                title->setPosition(x,y);
                line.push_back(title);
                x += 30;
            }
            _map.push_back(line);
            line.clear();
            x = 0;
            y += 30;
        }
        return (0);
    }

    void Client::updateMapInfo()
    {
        char buf[1024] = {0};
        std::string bct_output;
        std::string info;
        int temp;

        dprintf(_fd, "mct\n");
        read(_fd, &buf, 1024);
        bct_output = buf;
        if (bct_output.find_first_of(' ') == std::string::npos)
            return;
        bct_output = bct_output.substr(bct_output.find_first_of(' '));
        std::istringstream stream(bct_output);
        info = "Map total\n";
        stream >> temp;
        info += "Food : " + std::to_string(temp) + "\n";
        stream >> temp;
        info += "Linemate : " + std::to_string(temp) + "\n";
        stream >> temp;
        info += "Deraumere : " + std::to_string(temp) + "\n";
        stream >> temp;
        info += "Sibur : " + std::to_string(temp) + "\n";
        stream >> temp;
        info += "Mendiane : " + std::to_string(temp) + "\n";
        stream >> temp;
        info += "Phiras : " + std::to_string(temp) + "\n";
        stream >> temp;
        info += "Thystame : " + std::to_string(temp) + "\n";
        _map_info.setString(info);
        _map_info.setPosition(_width * 30 + 10, 200);
    }

    int Client::connectToServer()
    {
        char buf[1024] = {0};
        _fd = socket(AF_INET, SOCK_STREAM, 0);
        std::string num;
        if (_fd < 0)
            exit(84);
        _serv_adrr.sin_port = htons(_port);
        if (inet_pton(AF_INET, _machine.c_str(), &_serv_adrr.sin_addr) <= 0) {
            std::cerr << "error inet" << std::endl;
            exit(84);
        }
        if (connect(_fd, (struct sockaddr *)&_serv_adrr, sizeof(struct sockaddr_in)) < 0) {
            std::cerr << "error connect" << std::endl;
            exit(84);
        }
        read(_fd, &buf, 1024);
        if (strcmp(buf, "WELCOME\n") != 0) {
            std::cerr << "error welcome" << std::endl;
            exit(84);
        }
        dprintf(_fd, "%s\n", _name.c_str());
        read(_fd, &buf, 1024);
        std::istringstream stream(buf);
        std::cout << buf << std::endl;
        stream >> num;
        std::cout << "remaining place in [" + _name + "] : " << num << std::endl;
        if (std::stoi(num) == 0) {
            std::cout << "Team " + _name + " is full, exiting" << std::endl;
            exit(84);
        }
        stream >> _width;
        stream >> _height;
        std::cout << "map size : (" << _width << ", " << _height << ")" << std::endl;
        return (0);
    }
}