/*
** EPITECH PROJECT, 2018
** OOP_arcade_2018
** File description:
** IGraphicalLibHandler.hpp
*/

#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <dirent.h>
#include "Utils.hpp"

namespace arcade {

    typedef struct menu_handle_s {
        type_t type;
        std::string path;
    } menu_handle_t;

    class IGraphicalHandler {
        public:
            IGraphicalHandler() {};
            virtual void initialize(const std::string &window_name) = 0;
            virtual void drawShape(shape_t shape_type, color_t color, vector_t pos, vector_t size, const std::string path_to_file = "[none]") = 0;
            virtual void drawText(vector_t pos, const std::string &text) = 0;
            virtual void clear() = 0;
            virtual keys_t getInput() = 0;
            virtual void free_ressources() = 0;
            virtual menu_handle_t runArcadeMenu(std::string currently, std::string currently2) = 0;
            virtual void setWindowSize(vector_t size) = 0;
            const std::string &getName() const { return (_name); };
            std::vector<std::string> getLibsPaths(std::string path)
            {
                DIR *dir;
                struct dirent *rent;
                std::vector<std::string> libs_path;
                if ((dir = opendir(path.c_str())) != nullptr) {
                  while ((rent = readdir (dir)) != nullptr) {
                        std::string full_path = rent->d_name;
                        if (full_path.find_last_of('.') != std::string::npos && full_path.substr(full_path.find_last_of('.')) == ".so") {
                            full_path = path;
                            full_path.append(rent->d_name);
                            libs_path.push_back(full_path);
                        }
                    }
                }
                return (libs_path);
            }
        protected:
            vector_t _window_size;
            std::string _window_name;
            std::string _name;
    };
};