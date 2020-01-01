/*
** EPITECH PROJECT, 2018
** OOP_arcade_2018
** File description:
** NcursesGraphicalHandler.cpp
*/

#include "NcursesGraphicalHandler.hpp"

namespace arcade {
    static int getColor(const color_t &color)
    {
        switch (color)
        {
            case color_t::BLACK :
                return (COLOR_PAIR(1));
            case color_t::BLUE :
                return (COLOR_PAIR(4));
            case color_t::GREEN :
                return (COLOR_PAIR(3));
            case color_t::RED :
                return (COLOR_PAIR(2));
            case color_t::WHITE :
                return (COLOR_PAIR(5));
            case color_t::YELLOW :
                return (COLOR_PAIR(7));
            case color_t::MAGENTA :
                return (COLOR_PAIR(6));
            case color_t::CYAN :
                return (COLOR_PAIR(8));
        }
        return (COLOR_WHITE);
    }
    NcursesGraphicalHandler::NcursesGraphicalHandler()
    {

    }

    void NcursesGraphicalHandler::initialize(const std::string &window_name)
    {
        _window_name = window_name;
        initscr();
        start_color();
        init_pair(1 , COLOR_BLACK, COLOR_BLACK);
        init_pair(2, COLOR_RED, COLOR_RED);
        init_pair(3, COLOR_GREEN, COLOR_GREEN);
        init_pair(4, COLOR_BLUE, COLOR_BLUE);
        init_pair(5, COLOR_WHITE, COLOR_WHITE);
        init_pair(6, COLOR_MAGENTA, COLOR_MAGENTA);
        init_pair(7, COLOR_YELLOW, COLOR_YELLOW);
        init_pair(8, COLOR_CYAN, COLOR_CYAN);
        keypad(stdscr, TRUE);
        _win = newwin(20, 50, 0, 0);
        wtimeout(_win, 30);
        noecho();
        keypad(_win, TRUE);
        curs_set(0);
    }

    void NcursesGraphicalHandler::free_ressources()
    {
        delwin(_win);
        endwin();
    }

    void NcursesGraphicalHandler::drawShape(shape_t type, color_t color, vector_t pos, vector_t size, const std::string)
    {
        for (int i = 1; i != size.y + 1; i += 1) {
            for (int j = 1; j != size.x + 1; j += 1) {
                mvwaddch(_win, pos.x + i, pos.y + j, '#' | getColor(color));
            }
        }
    }

    void NcursesGraphicalHandler::clear()
    {
        wrefresh(_win);
        wclear(_win);
        box(_win, 0, 0);
    }

    keys_t NcursesGraphicalHandler::getInput()
    {
        int key = wgetch(_win);

        for (size_t i = 0; i != keyboard_key_g.size(); i += 1)
            if (key == keyboard_key_g[i].key)
                return (keyboard_key_g[i].key_r);
        return (keys_t::NO_KEY_PRESSED);
    }

    void NcursesGraphicalHandler::drawText(vector_t pos, const std::string &text)
    {
       mvwprintw(_win, pos.x + 1, pos.y + 1, text.c_str());
    }

    void NcursesGraphicalHandler::setWindowSize(vector_t size)
    {
        wclear(_win);
        wrefresh(_win);
        wresize(_win, size.y + 1, size.x + 1);
    }

    menu_handle_t NcursesGraphicalHandler::runArcadeMenu(std::string current_game, std::string current_lib)
    {
        menu_handle_t lol = {type_t::GAME, "[none]"};
        int key;
        static bool change = true;
        std::vector<std::string> lib_games_paths = getLibsPaths("./games/");
        std::vector<std::string> lib_graph_paths = getLibsPaths("./libs/");
        static int c_game = 0;
        static int c_graph = 0;
        std::string tmp;
        wtimeout(_win, 60);

        while (lol.path != "[QUIT]") {
            key = wgetch(_win);

//              DISPLAY GAME CHOOSING
            if (change) {
                lol.type = type_t::GAME;
                if (key == KEY_LEFT) {
                    c_game -= 1;
                    if (c_game < 0)
                        c_game = lib_games_paths.size() - 1;
                }
                if (key == KEY_RIGHT) {
                    c_game += 1;
                    if (c_game >= lib_games_paths.size())
                        c_game = 0;
                }
                if (key == 'q') {
                    lol.path = "[QUIT]";
                    delwin(_win);
                    endwin();
                    return(lol);
                }
                if (key == KEY_UP) {
                    change = false;
                }
                if (key == ' ') {
                    tmp = lib_games_paths[c_game].substr(lib_games_paths[c_game].find_last_of('/') + 4);
                    std::replace(tmp.begin(), tmp.end(), '_', ' ');
                    if (current_game == tmp) {
                        lol.path = "[none]";
                        return (lol);
                    }
                    lol.path = lib_games_paths[c_game];
                    return (lol);
                }
                wrefresh(_win);
                wclear(_win);
                box(_win, 0, 0);
                mvwprintw(_win, 1, 19, "Now playing :");
                tmp = current_game.substr(current_game.find_last_of('/') + 1, current_game.find_last_of('.'));
                mvwprintw(_win, 2, 25 - tmp.size() / 2, tmp.c_str());
                mvwprintw(_win, 10, 22, "Play");
                tmp =  "\"" + lib_games_paths[c_game].substr(lib_games_paths[c_game].find_last_of('/') + 1, lib_games_paths[c_game].find_last_of('.')) + "\"";
                mvwprintw(_win, 11, 25 - tmp.size() / 2, tmp.c_str());
                mvwprintw(_win, 15, 8, "Press [SPACE] or [UP/DOWN] to switch mode");
            }
//              DISPLAY GRAPHICAL CHOOSING
            if (!change) {
                lol.type = type_t::GRAPHICAL;
                if (key == KEY_LEFT) {
                    c_graph -= 1;
                    if (c_graph < 0)
                        c_graph = lib_graph_paths.size() - 1;
                }
                if (key == KEY_RIGHT) {
                    c_graph += 1;
                    if (c_graph >= lib_graph_paths.size())
                        c_graph = 0;
                }
                if (key == 'q') {
                    lol.path = "[QUIT]";
                    delwin(_win);
                    endwin();
                    return(lol);
                }
                if (key == KEY_DOWN) {
                    change = true;
                }
                if (key == ' ') {
                    tmp = lib_graph_paths[c_graph].substr(lib_graph_paths[c_graph].find_last_of('/') + 4);
                    std::cout << tmp + " = " + current_lib << std::endl;
                    if (current_lib == tmp) {
                        lol.path = "[none]";
                        return (lol);
                    }
                    lol.path = lib_graph_paths[c_graph];
                    return (lol);
                }
                wrefresh(_win);
                wclear(_win);
                box(_win, 0, 0);
                mvwprintw(_win, 1, 19, "Now using :");
                tmp = current_lib.substr(current_lib.find_last_of('/') + 1, current_lib.find_last_of('.'));
                mvwprintw(_win, 2, 25 - tmp.size() / 2, tmp.c_str());
                mvwprintw(_win, 10, 22, "Change for :");
                tmp =  "\"" + lib_graph_paths[c_graph].substr(lib_graph_paths[c_graph].find_last_of('/') + 1, lib_graph_paths[c_graph].find_last_of('.')) + "\"";
                mvwprintw(_win, 11, 25 - tmp.size() / 2, tmp.c_str());
                mvwprintw(_win, 15, 8, "Press [SPACE] or [UP/DOWN] to switch mode");
            }
        }
            return (lol);
    };

}

extern "C" arcade::IGraphicalHandler *entryPoint()
{
    return (new arcade::NcursesGraphicalHandler);
}