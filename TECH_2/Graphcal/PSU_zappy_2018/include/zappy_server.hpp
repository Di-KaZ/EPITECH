/*
** EPITECH PROJECT, 2019
** PSU_zappy_2018
** File description:
** zappy_server
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "unistd.h"
#include <time.h>
#include <stdio.h>
#include <string>
#include <vector>
#include <iomanip>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <dirent.h>
#include <sys/ioctl.h>
#include<fcntl.h>
#include <sys/time.h>
#include <sys/sendfile.h>
#include <sys/stat.h>
#include <map>
#include <iostream>
#include "Clock.hpp"
#include <memory>

#pragma once

namespace Zappy
{
    class Title {
        public:
            Title();
            ~Title();
            void addRessources();
            std::string getTitleInfo();
        private:
            int _food;
            int _linemate;
            int _deraumere;
            int _sibur;
            int _mendiane;
            int _phiras;
            int _thystame;
    };

    class Map {
        public:
            Map();
            Map(int width, int height);
            ~Map();
            std::string getTitleInfo(std::pair<int, int> pos);
            std::string getMapInfo();
            void addRessources();
            void setMapWidth(int);
            void generateMap();
            void setMapHeight(int);
        private:
            int _width = 0;
            int _height = 0;
            std::map<std::pair<int, int>, std::shared_ptr<Title>> _map;
    };

    class Team {
        public:
            Team(std::string name, int total_slot);
            ~Team();
            int getRemainingSlot();
            void setMaxSlot(int slots);
            const std::string &getName() const;
            void newPlayerAccepted();
        private:
            std::string _name;
            int _total_slot;
            int _used_slot;
    };

    class Player {
        enum class orientation_t {
            NORTH,
            SOUTH,
            EAST,
            WEST
        };
        public:
            Player(std::string team, int id, struct sockaddr_in, std::pair<int, int> pos);
            ~Player();
            const int &getID() const;
            void setPosition(std::pair<int, int> pos);
            const std::pair<int, int> &getPosition() const;
            const int &getIncantationLevel() const;
            int getOrientation();
            const std::string &getTeam() const;
            std::string getInfoPosition();
            const bool &isRegistered() const;
            void registerPlayer();
            std::string executeFirstCommand();
            void registerNewCommad(std::string command);
        private:
            std::string _team;
            int _id;
            struct sockaddr_in _sockaddr;
            std::pair<int, int> _pos;
            size_t _sockaddr_size = sizeof(struct sockaddr_in);
            orientation_t _o;
            int _incantation_level = 0;
            int _food = 0;
            int _linemate = 0;
            int _deraumere = 0;
            int _sibur = 0;
            int _mendiane = 0;
            int _phiras = 0;
            int _thystame = 0;
            bool _is_registered = false;
            std::vector<std::string> _command_queue;
    };

    class Server {
        public:
            Server();
            ~Server();
            int initializeParam(const char **av);
            int initializeServer();
            int run();
            int registerNewClient();
        private:
            int getPort(const char *);
            int getClientNb(const char *);
            int getFreq(const char *);
            int getWidth(const char *);
            int getHeight(const char *);
            void getTeamsName(const char **, int i);
            void getGreaterID();
            int checkParameters();
            int registerClientCommand();
            void gameLogic();
            int commandBct(Zappy::Player &, std::string);
            int commandMct(Zappy::Player &, std::string);
            int commandTna(Zappy::Player &, std::string);
            int commandNta(Zappy::Player &, std::string);
            int commandPpo(Zappy::Player &, std::string);
            int commandMsz(Zappy::Player &, std::string);
            void registerStepTeam();
            void infoPnw(Player &player);
            int _port = 0;
            int _fd = 0;
            int _last_fd = 0;
            int _nb_slot_per_team = 0;
            int _width = 0;
            int _height = 0;
            int _freq = 0;
            struct sockaddr_in _sockaddr;
            Map _map;
            size_t _sockaddr_size = sizeof(struct sockaddr_in);
            std::vector<Team> _teams;
            std::vector<Player> _clients;
            fd_set _readfds;
            struct timeval _timeout;
            Clock _update;
    };
}

// DEFINE ERROR MSG

#define PRINT_ERROR_MSG(x, y) dprintf(2, "\x1b[31m[ERROR]\x1b[0m\t%s\n", x); return (y)
#define PRINT_INFO_MSG(x) printf("\x1b[36m[INFO]\x1b[0m\t%s\n", x)
#define ERR_SOCK "unable to create socket."
#define ERR_BIND "unable to bind socket."
#define ERR_LISTEN "unable to listen socket."
#define ERR_SEL "unable to select fds."
#define ERR_TEAM "team is full or client send wrong info."
#define ERR_ACCEPT "unable to accept incoming client connection."
#define INFO_CON_CLI "Connection from : %s:%d."
#define ERR_TEAMS "need at least two team."

#define WELCOME "WELCOME\n"