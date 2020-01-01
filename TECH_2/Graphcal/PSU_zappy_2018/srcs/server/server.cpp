/*
** EPITECH PROJECT, 2019
** PSU_zappy_2018
** File description:
** server
*/

#include "zappy_server.hpp"

namespace Zappy
{
    Server::Server()
    {

    }

    Server::~Server()
    {

    }

    int Server::getPort(const char *line)
    {
        int port = 1;
        try {
            port = std::atoi(line);
        } catch (const std::exception &e) {
            return (-1);
        }
        return (port);
    }

    int Server::getClientNb(const char *line)
    {
        int client_nb = 1;
        try {
            client_nb = std::atoi(line);
        } catch (const std::exception &e) {
            return (-1);
        }
        return (client_nb);
    }

    int Server::getWidth(const char *line)
    {
        int width = 1;
        try {
            width = std::atoi(line);
        } catch (const std::exception &e) {
            return (-1);
        }
        return (width);
    }

    int Server::getHeight(const char *line)
    {
        int height = 1;
        try {
            height = std::atoi(line);
        } catch (const std::exception &e) {
            return (-1);
        }
        return (height);
    }

    void Server::getTeamsName(const char **av, int i)
    {
        static std::vector<std::string> teams_name;
        
        if (!av) {
            if (teams_name.size() < 2) {
                PRINT_INFO_MSG(ERR_TEAMS);
                throw std::string("shiet \n");
            }
            for (auto i : teams_name)
                _teams.push_back(Team(i, _nb_slot_per_team));
            teams_name.clear();
        }
        i += 1;
        while (av && av[i]) {
            if (av[i][0] == '-' || av[i][0] == '\0')
                return;
            teams_name.push_back(av[i]);
            i+= 1;
        }
    }

    int Server::getFreq(const char *line)
    {
        int freq = 1;
        try {
            freq = std::atoi(line);
        } catch (const std::exception &e) {
            return (-1);
        }
        return (freq);
    }

    int Server::checkParameters()
    {
        if (_port && _nb_slot_per_team &&
            _width && _height && _freq) {
            for (auto i : _teams) {
                i.setMaxSlot(_nb_slot_per_team);
            }
            return (0);
        }
        return (-1);
    }

    int Server::initializeServer()
    {
        srand(getpid());
        _sockaddr.sin_family = AF_INET;
        _sockaddr.sin_addr.s_addr = INADDR_ANY;
        _sockaddr.sin_port = htons(_port);
        _fd = socket(AF_INET, SOCK_STREAM | SOCK_NONBLOCK, 0);
        if (_fd < 0) {
            PRINT_ERROR_MSG(ERR_SOCK, -1);
        }
        if (bind(_fd, (struct sockaddr *)&_sockaddr, _sockaddr_size) < 0) {
            PRINT_ERROR_MSG(ERR_BIND, -1);
        }
        if (listen(_fd, 3) < 0) {
            PRINT_ERROR_MSG(ERR_LISTEN, -1);
        }
        _last_fd = _fd;
        _map.setMapHeight(_height);
        _map.setMapWidth(_width);
        _map.generateMap();
        return (0);
    }


    void Server::registerStepTeam()
    {
            for (auto i : _clients) {

            }
    }

    int Server::registerNewClient()
    {
        int id;
        char buf[1024] = {0};
        struct sockaddr_in sockaddr;
        std::string team;
        size_t socket_size = sizeof(struct sockaddr_in);
        id = accept(_fd, (struct sockaddr *)&sockaddr, (socklen_t *)&socket_size);

        if (id < 0) {
            PRINT_ERROR_MSG(ERR_ACCEPT, -1);
        }
        team = "connection from ";
        team += inet_ntoa(sockaddr.sin_addr);
        team += ":" + std::to_string(ntohs(sockaddr.sin_port)); 
        PRINT_INFO_MSG(team.c_str());
        FD_SET(id, &_readfds);
        fcntl(id, F_SETFL, fcntl(id, F_GETFL, 0) | O_NONBLOCK);
        dprintf(id, WELCOME);
        read(id, &buf, 1024);
        std::string getted = buf;
        getted = getted.substr(0, getted.find_first_of('\n'));
        for (auto i : _teams) {
            if (i.getName() == getted && i.getRemainingSlot() != 0) {
                dprintf(id, "%d\n%d %d\n", i.getRemainingSlot(), _width, _height);
                i.newPlayerAccepted();
                return (0);
                _clients.push_back(Player(i.getName(), id, sockaddr, std::make_pair(rand() % _width, rand() % _height)));
            }
        }
        shutdown(id, SHUT_RDWR);
        close(id);
        PRINT_ERROR_MSG(ERR_TEAM, -1);
    }

    int Server::commandMct(Zappy::Player &player, std::string line)
    {
        std::string info;

        if (line != "mct\n")
            return(0);
        dprintf(player.getID(), _map.getMapInfo().c_str());
        return (0);
    }

    int Server::commandMsz(Player &player, std::string line)
    {
        if (line != "msz\n")
            return (0);
        dprintf(player.getID(), "msz %d %d\n", player.getPosition().first, player.getPosition().second);
        return (0);
    }

    int Server::commandTna(Zappy::Player &player, std::string line)
    {
        std::string info;

        if (line != "tna\n")
            return (0);
        for (auto i : _teams) {
            info += "tna ";
            info += i.getName();
            info += '\n';
        }
        dprintf(player.getID(), info.c_str());
        return (0);
    }

    int Server::commandPpo(Zappy::Player &player, std::string line)
    {
        if (line != "ppo\n")
            return (0);
        dprintf(player.getID(), player.getInfoPosition().c_str());
        return (0);
    }

    int Server::commandBct(Zappy::Player &player, std::string line)
    {
        std::istringstream stream(line);
        std::pair<int, int> coord(0, 0);
        std::string temp;

        if (line.substr(0, line.find_first_of(' ')) == "bct") {
            stream >> temp;
            stream >> coord.first;
            stream >> coord.second;
            dprintf(player.getID(), "%s", _map.getTitleInfo(coord).c_str());
            return (1);
        }
        return (0);
    }

    void Server::gameLogic()
    {
        if (_update.getElapsedTime() > _freq) {
            _map.addRessources();
            _update.reset();
        }
    }

    int Server::registerClientCommand()
    {
        char buf[1024] = {0};
        std::string command;

        for (auto i : _clients) {
            if (!FD_ISSET(i.getID(), &_readfds))
                continue;
            if (read(i.getID(), &buf, 1024) < 0) {
                PRINT_ERROR_MSG("idk", 84);
            }
            i.registerNewCommad(buf);
            command = i.executeFirstCommand();
            if (command == "[NO COMMAND]")
                return (0);
            if (!commandBct(i, command))
                dprintf(i.getID(), "ko\n");
        }
        return (0);
    }

    void Server::infoPnw(Player &player)
    {
        for(auto i : _clients) {
            dprintf(i.getID(), "%d %d %d %d %s", player.getPosition().first, player.getPosition().second, player.getOrientation(), player.getIncantationLevel(), player.getTeam().c_str());
        }
    }

    int Server::run()
    {
        getTeamsName(nullptr, 0);
        PRINT_INFO_MSG(std::string("opened server on port : " + std::to_string(_port)).c_str());
        while (true) {
            FD_ZERO(&_readfds);
            FD_SET(_fd, &_readfds);
            for (auto i : _clients) {
                FD_SET(i.getID(), &_readfds);
                if (i.getID() > _last_fd)
                    _last_fd = i.getID();
            }
            _timeout.tv_sec = 2;
            _timeout.tv_usec = 0;
            if (select(_last_fd + 1, &_readfds, nullptr, nullptr, &_timeout) <0) {
                PRINT_ERROR_MSG(ERR_SEL, 84);
            }
            if (FD_ISSET(_fd, &_readfds))
                registerNewClient();
            registerClientCommand();
            gameLogic();
        }
        return (0);
    }

    int Server::initializeParam(const char **av)
    {
        for (int i = 0; av[i]; i += 1) {
            if (std::string(av[i]) == "-p" && av[i + 1])
                _port = getPort(av[++i]);
            else if (std::string(av[i]) == "-c" && av[i + 1])
                _nb_slot_per_team = getClientNb(av[++i]);
            else if (std::string(av[i]) == "-n" && av[i + 1])
                getTeamsName(av, i);
            else if (std::string(av[i]) == "-x" && av[i + 1])
                _width = getWidth(av[++i]);
            else if (std::string(av[i]) == "-y" && av[i + 1])
                _height = getHeight(av[++i]);
            else if (std::string(av[i]) == "-f" && av[i + 1])
                _freq = getFreq(av[++i]);
        }
        return (checkParameters());
    }
}