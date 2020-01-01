/*
** EPITECH PROJECT, 2018
** OOP_arcade_2018
** File description:
** qix->cpp
*/

#include "qix.hpp"

namespace arcade
{
    void qixgame::drawBoard()
    {
	vector_t pos;
	vector_t size = {1, 1};

	for (int i = 0; i < HEIGHT; i++) {
            for (int j = 0; j < WIDTH; j++) {
		pos.x = i + 2;
		pos.y = j;
		if (_board[i][j] == 1)
		    _lib_obj_ptr->drawShape(shape_t::SQUARE, color_t::BLUE, pos, size);
		else if (_board[i][j] == 2)
		    _lib_obj_ptr->drawShape(shape_t::SQUARE, color_t::GREEN, pos, size);
		else if (_board[i][j] == 3)
		    _lib_obj_ptr->drawShape(shape_t::SQUARE, color_t::CYAN, pos, size);
		else if (_board[i][j] == -1)
                    _lib_obj_ptr->drawShape(shape_t::SQUARE, color_t::MAGENTA, pos, size);
		else if (_board[i][j] == -2)
		    _lib_obj_ptr->drawShape(shape_t::SQUARE, color_t::YELLOW, pos, size);
		else
		    _lib_obj_ptr->drawShape(shape_t::SQUARE, color_t::WHITE, pos, size);
            }
        }
    }

    int qixgame::getScore() const
    {
	return (this->_score);
    }

    void qixgame::initialize(IGraphicalHandler *lib_obj_ptr)
    {
	player *player = new arcade::player();
	monster *monster = new arcade::monster();
        vector_t size = {WIDTH + 1, HEIGHT + 3};

	this->_player = player;
	this->_monster = monster;

	for (int i = 0; i < HEIGHT - 1; i++) {
            for (int j = 0; j < WIDTH - 1; j++) {
                this->_board[i][j] = 0;
            }
        }
	for (int i = 0; i < WIDTH; i++) {
	    this->_board[0][i] = 1;
	    this->_board[HEIGHT - 1][i] = 1;
        }
	for (int i = 0; i < HEIGHT; i++) {
            this->_board[i][0] = 1;
            this->_board[i][WIDTH - 1] = 1;
        }

        _lib_obj_ptr = lib_obj_ptr;
        _lib_obj_ptr->setWindowSize(size);
    }

    void qixgame::displayScreen()
    {
	vector_t pos = {0, 0};
	vector_t size = {1, 1};

        static int increment = 0;
        static Clock clock;
        float time = clock.getElapsedTime();

	vector_t newpos = {(this->_player->getPos().x + 2), (this->_player->getPos().y)};
	vector_t newposMonster = {(this->_monster->getPos().x + 2), (this->_monster->getPos().y)};

        _lib_obj_ptr->drawText(pos, "score = " + std::to_string(this->_score));
	//_lib_obj_ptr->drawText(pos, "x: " + std::to_string(this->_player->getPos().y) + " y: " + std::to_string(this->_player->getPos().x));
	this->drawBoard();

	_lib_obj_ptr->drawShape(shape_t::SQUARE, color_t::BLACK, newposMonster, size);
	_lib_obj_ptr->drawShape(shape_t::SQUARE, color_t::RED, newpos, size);
    }

    void qixgame::inputs()
    {
        keys_t key_pressed = _lib_obj_ptr->getInput();
        if (key_pressed == keys_t::EXIT_SIGNAL)
            status = status_t::QUIT;
        if (key_pressed == keys_t::KEYBOARDKEY_Q)
            status = status_t::QUIT;
        if (key_pressed == keys_t::KEYBOARDKEY_P)
            status = status_t::PAUSE;
        if (key_pressed == keys_t::KEYBOARDKEY_DOWN)
            this->_player->changeDir(RIGHT);
        if (key_pressed == keys_t::KEYBOARDKEY_UP)
            this->_player->changeDir(LEFT);
        if (key_pressed == keys_t::KEYBOARDKEY_LEFT)
            this->_player->changeDir(TOP);
        if (key_pressed == keys_t::KEYBOARDKEY_RIGHT)
            this->_player->changeDir(BOT);
	if (key_pressed == keys_t::KEYBOARDKEY_V)
	    this->_player->changeDir(NO);
    }

    void qixgame::gameLogic()
    {
	if (this->_timePlayer.getElapsedTime() > 0.1) {
	    this->_player->move(this->_board, this->_monster);
	    this->_monster->move(this->_board);
	    this->_timePlayer.reset();
	}
    }

    void qixgame::free_ressources()
    {

    }
}

// arcade
extern "C" arcade::IGameHandler *entryPoint()
{
    return (new arcade::qixgame);
}
