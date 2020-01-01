/*
** EPITECH PROJECT, 2018
** OOP_arcade_2018
** File description:
** ArcadeHandler.hpp
*/

#pragma once
#include <string>
#include <vector>
#include <map>
#include <string>
#include <iostream>
#include <utility>
#include <dlfcn.h>
#include <memory>
#include <dirent.h>
#include "IGraphicalLibHandler.hpp"
#include "IGameHandler.hpp"

namespace arcade
{
    typedef void *(*handler_t)();
/*

    TODO : en fait pour le menu de arcade c'est la lib graphique qui doit la géré ti 
    va crée un efonction qui va display le menu pour chaque lib  de cette facon chquae 
    lib auras son menu  et des que le jeu seras en pause tu bascule sur le display du menu
*/
    class Core {
        public:
            Core();
            void loadDynamicLib(const std::string &path, type_t type);
            void unloadDynamicLib(void *handler);
            std::map<std::string, std::string> getLibsInDir(const std::string &path);
            void run();
        private:
            void *_game_handler = nullptr;
            std::map<std::string, std::string> _libs_games_location;
            std::map<std::string, std::string> _libs_graph_location;
            void *_lib_ptr = nullptr;
            IGraphicalHandler *_current_lib_obj_ptr = nullptr;
            IGameHandler *_current_game_obj_ptr = nullptr;
            std::string _current_game = "[none]";
            std::string _current_lib = "[none]";
    };
}