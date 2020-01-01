/*
** EPITECH PROJECT, 2018
** OOP_arcade_2018
** File description:
** ArcadeHandler.cpp
*/

#include "ArcadeHandler.hpp"

namespace arcade
{
    Core::Core()
    {
        _libs_games_location = getLibsInDir("./games/");
        _libs_graph_location = getLibsInDir("./libs/");
    }

    void Core::loadDynamicLib(const std::string &path, type_t type)
    {
        void *handler = nullptr;
        handler_t handler_ptr = nullptr;
        char *error = nullptr;

        if ((handler = dlopen(path.c_str(), RTLD_LAZY)) == nullptr) {
            std::cerr << "[ERROR] : \"" << path << "\" " << dlerror() << std::endl;
            exit(84);
        }
        handler_ptr = (handler_t) dlsym(handler, "entryPoint");
        if ((error = dlerror()) != nullptr) {
            std::cerr << "[ERROR] : \"" << path << "\" " << error << std::endl;
            exit(84);
        }
        if (type == type_t::GRAPHICAL) {
            if (_current_lib_obj_ptr)
                _current_lib_obj_ptr->free_ressources();
            _lib_ptr = handler;
            _current_lib_obj_ptr = (IGraphicalHandler *)handler_ptr();
            _current_lib_obj_ptr->initialize("Arcade");
            _current_lib = path.substr(path.find_last_of("/") + 4, path.find_last_of("."));
        }
        if (type == type_t::GAME) {
            _game_handler = handler;
            _current_game_obj_ptr = (IGameHandler *)handler_ptr();
        }
        std::cerr << "[INFO] : loaded " + path << std::endl;
    }

    void Core::unloadDynamicLib(void *handler)
    {
        if (handler && dlclose(handler) != 0) {
            std::cerr << "[ERROR] : unable to unload dynamic library" << std::endl;
            exit(84);
        }
        handler = nullptr;
        std::cerr << "[INFO] : unloadded graphical library" << std::endl;
    }

    void Core::run()
    {
        menu_handle_t handle = _current_lib_obj_ptr->runArcadeMenu(_current_game, _current_lib);
        void * temp = nullptr;

        if ((handle.type == type_t::GAME && handle.path == "[none]") || handle.path == "[QUIT]")
            return;
        if (handle.type == type_t::GAME) {
            temp = _game_handler;
            loadDynamicLib(_libs_games_location[handle.path.substr(handle.path.find_last_of('/') + 1)], type_t::GAME);
            unloadDynamicLib(temp);
            _current_game = handle.path.substr(handle.path.find_last_of("/") + 4, handle.path.find_last_of("."));
        }
        if (handle.type == type_t::GRAPHICAL && handle.path != "[none]") {
            temp = _lib_ptr;
            loadDynamicLib(_libs_graph_location[handle.path.substr(handle.path.find_last_of('/') + 1)], type_t::GRAPHICAL);
            unloadDynamicLib(temp);
            _current_lib = handle.path.substr(handle.path.find_last_of("/") + 4, handle.path.find_last_of("."));
            run();
            return;
        }
        if (_current_game_obj_ptr == nullptr) {
            _current_lib_obj_ptr->free_ressources();
            run();
            return;
        }
        _current_lib_obj_ptr->initialize(_current_lib_obj_ptr->getName());
        _current_game_obj_ptr->initialize(_current_lib_obj_ptr);
        while (_current_game_obj_ptr->status == status_t::RUN || _current_game_obj_ptr->status == status_t::PAUSE) {
            if (_current_game_obj_ptr->status == status_t::PAUSE) {
                handle = _current_lib_obj_ptr->runArcadeMenu(_current_game, _current_lib);
                if (handle.type == type_t::GAME && handle.path != "[none]") {
                    temp = _game_handler;
                    loadDynamicLib(_libs_games_location[handle.path.substr(handle.path.find_last_of('/') + 1)], type_t::GAME);
                    _current_game_obj_ptr->free_ressources();
                    unloadDynamicLib(temp);
                    _current_game_obj_ptr->initialize(_current_lib_obj_ptr);
                    _current_game = handle.path.substr(handle.path.find_last_of("/") + 4, handle.path.find_last_of("."));
                }
                if (handle.type == type_t::GRAPHICAL && handle.path != "[none]") {
                    temp = _lib_ptr;
                    loadDynamicLib(_libs_graph_location[handle.path.substr(handle.path.find_last_of('/') + 1)], type_t::GRAPHICAL);
                    unloadDynamicLib(temp);
                    _current_lib = handle.path.substr(handle.path.find_last_of("/") + 4, handle.path.find_last_of("."));
                    _current_game_obj_ptr->initialize(_current_lib_obj_ptr);
                }
                if (handle.path == "[QUIT]")
                    break;
                _current_game_obj_ptr->status = status_t::RUN;
            }
            _current_lib_obj_ptr->clear();
            _current_game_obj_ptr->displayScreen();
            _current_game_obj_ptr->inputs();
            _current_game_obj_ptr->gameLogic();
        }
        _current_lib_obj_ptr->free_ressources();
        _current_game_obj_ptr->free_ressources();
    }
    std::map<std::string, std::string> Core::getLibsInDir(const std::string &path)
    {
        DIR *dir;
        struct dirent *rent;
        std::map<std::string, std::string> _libs_path;
        if ((dir = opendir(path.c_str())) != nullptr) {
          while ((rent = readdir (dir)) != nullptr) {
                std::string full_path = rent->d_name;
                if (full_path.find_last_of('.') != std::string::npos && full_path.substr(full_path.find_last_of('.')) == ".so") {
                    full_path = path;
                    full_path.append(rent->d_name);
                    _libs_path[rent->d_name] = full_path;
                }
          }
          closedir(dir);
          return (_libs_path);
        } else {
            std::cerr << "[ERROR] : missing directory \"" << path << "\" please reinstall" << std::endl;
          return (_libs_path);
        }
    }
}