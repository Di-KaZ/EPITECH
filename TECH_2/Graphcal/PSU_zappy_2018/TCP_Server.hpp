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
#include "RegisteredClient.hpp"

class TCP_Server {
        public:
            TCP_Server();
            ~TCP_Server();
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
            int executeClientCommand();
            std::vector<std::unique_ptr<RegisteredClient>> _clients;
            int _port = 0;
            int _fd = 0;
            int _last_fd = 0;
            int _nb_slot_per_team = 0;
            int _width = 0;
            int _height = 0;
            int _freq = 0;
            struct sockaddr_in _sockaddr;
            size_t _sockaddr_size = sizeof(struct sockaddr_in);
            fd_set _readfds;
            struct timeval _timeout;
            Clock _update;
};

#define ERR_SOCK "unable to create socket."
#define ERR_BIND "unable to bind socket."
#define ERR_LISTEN "unable to listen socket."
#define ERR_SEL "unable to select fds."
#define ERR_TEAM "team is full or client send wrong info."
#define ERR_ACCEPT "unable to accept incoming client connection."
#define INFO_CON_CLI "Connection from : %s:%d."
#define ERR_TEAMS "need at least two team."