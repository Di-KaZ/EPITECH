/*
** EPITECH PROJECT, 2019
** temp_zappy
** File description:
** zappy_client
*/

#include <stdlib.h>
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
#include <stdio.h>
#include <string.h>
#include "unistd.h"
#include <string>
#include <vector>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <memory>
#include <iomanip>
#include <iostream>

namespace ZappyClient
{
    class Client {
        public:
            Client(const char **av);
            ~Client();
            int connectToServer();
            int runAI();
        private:
            int param_p(const char **av);
            int param_n(const char **av);
            int param_h(const char **av);
            void updateInfoOnTitle();
            void updateMapInfo();
            void getTeamsName();
            int iniGraphMap();
            int _port = -1;
            std::string _name = "[None]";
            std::string _machine = "127.0.0.1";
            int _fd = -1;
            struct sockaddr_in _serv_adrr;
            int _width = - 1;
            int _height = -1;
            std::vector<std::vector<std::shared_ptr<sf::RectangleShape>>> _map;
            std::vector<std::string> _teams_name;
            sf::Font _font;
            sf::RenderWindow _window;
            sf::Text _title_info;
            sf::Text _map_info;
            sf::Clock _clock;
    };
}
std::string parse_bct(std::string bct_output);
int getnextline(int fd, std::string &line);