#include "TCP_Server.hpp"

TCP_Server::TCP_Server()
{

}

TCP_Server::~TCP_Server()
{

}

int TCP_Server::initializeServer()
{
    srand(getpid());
    _sockaddr.sin_family = AF_INET;
    _sockaddr.sin_addr.s_addr = INADDR_ANY;
    _sockaddr.sin_port = htons(_port);
    _fd = socket(AF_INET, SOCK_STREAM | SOCK_NONBLOCK, 0);
    if (_fd < 0) {
        std::cerr << ERR_SOCK << std::endl;
        return -1;
    }
    if (bind(_fd, (struct sockaddr *)&_sockaddr, _sockaddr_size) < 0) {
        std::cerr << ERR_BIND << std::endl;
        return -1;
    }
    if (listen(_fd, 3) < 0) {
        std::cerr << ERR_LISTEN << std::endl;
        return -1;
    }
    _last_fd = _fd;
    return (0);
}


std::vector<std::string> parseString(const std::string &str)
{
    std::vector<std::string> words;
    std::istringstream ss(str);

    do {
        std::string word;
        ss >> word;
        words.push_back(word);
    } while (ss);
    return words;
}

int TCP_Server::registerNewClient()
{
    int id;
    char buf[1024] = {0};
    struct sockaddr_in sockaddr;
    std::string team;
    size_t socket_size = sizeof(struct sockaddr_in);
    id = accept(_fd, (struct sockaddr *)&sockaddr, (socklen_t *)&socket_size);
    if (id < 0) {
        std::cerr << ERR_ACCEPT << std::endl;
        return (-1);
    }
    team = "connection from ";
    team += inet_ntoa(sockaddr.sin_addr);
    team += ":" + std::to_string(ntohs(sockaddr.sin_port)); 
    std::cout << team.c_str() << std::endl;
    FD_SET(id, &_readfds);
    fcntl(id, F_SETFL, fcntl(id, F_GETFL, 0) | O_NONBLOCK);
    read(id, &buf, 1024);
    std::string getted = buf;
    auto parsedbuf = parseString(getted);
    if (parsedbuf[0] == "REGISTER") {
        _clients.push_back(std::make_unique<RegisteredClient>(RegisteredClient(parsedbuf[2], parsedbuf[1], id)));
    }
    shutdown(id, SHUT_RDWR);
    close(id);
    std::cerr << ERR_TEAM << std::endl;
    return (-1);
}

int TCP_Server::run()
{
    std::cout << std::string("opened server on port : " << std::to_string(_port) << std::endl;
    while (true) {
        FD_ZERO(&_readfds);
        FD_SET(_fd, &_readfds);
        for (size_t i = 0; i < _clients.size(); i ++) {
            FD_SET(_clients[i]->getId(), &_readfds);
            if (_clients[i]->getId() > _last_fd)
                _last_fd = _clients[i]->getId();
        }
        _timeout.tv_sec = 2;
        _timeout.tv_usec = 0;
        if (select(_last_fd + 1, &_readfds, nullptr, nullptr, &_timeout) <0) {
            std::cerr << ERR_SEL << std::endl;
            return 84;
        }
        if (FD_ISSET(_fd, &_readfds))
            registerNewClient();
        registerClientCommand();
    }
    return (0);
}

int TCP_Server::executeClientCommand()
{
    char buf[1024] = {0};
    std::string command;

    for (size_t i = 0; i < _clients.size(); i++) {
        if (!FD_ISSET(_clients[i]->getId(), &_readfds))
                continue;
            if (read(_clients[i]->getId(), &buf, 1024) < 0) {
                PRINT_ERROR_MSG("idk", 84);
            }
            i.registerNewCommad(buf);
            command = i.executeFirstCommand();
            if (command == "[NO COMMAND]")
                return (0);
        // execute command here
    }
}