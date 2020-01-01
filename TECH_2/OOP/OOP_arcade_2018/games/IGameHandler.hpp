/*
** EPITECH PROJECT, 2018
** OOP_arcade_2018
** File description:
** IGamehandler.hpp
*/

#pragma once
#include "IGraphicalLibHandler.hpp"

namespace arcade
{
    class IGameHandler {
        public:
            status_t status = status_t::RUN;
            virtual void initialize(IGraphicalHandler *lib_obj_ptr) = 0;
          //  void switchGraphicalLib(IGraphicalHandler *lib_obj_ptr) { _lib_obj_ptr = lib_obj_ptr; };
            virtual void displayScreen() = 0;
            virtual void inputs() = 0;
            virtual void gameLogic() = 0;
            virtual void free_ressources() = 0;
        protected:
            IGraphicalHandler *_lib_obj_ptr = nullptr;
    };
}