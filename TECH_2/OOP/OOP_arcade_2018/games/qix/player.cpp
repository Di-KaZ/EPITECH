/*
** EPITECH PROJECT, 2019
** player.cpp
** File description:
** qix->player.cpp
*/

#include "qix.hpp"

namespace arcade
{
    player::player(int speed) :
	_speed(speed),
	_direction(NO)
    {}

    void player::changeDir(Direction dir)
    {
	this->_direction = dir;
    }

    void player::changeSpeed(int speed)
    {
	this->_speed = speed;
    }

    int player::getSpeed() const
    {
	return (this->_speed);
    }

    void player::move(int board[HEIGHT][WIDTH], monster *monster)
    {
	// Déplacement génériques
	if (this->_direction == TOP && this->_position.y > 0) {
	    if (board[this->_position.x][this->_position.y] == 0)
		board[this->_position.x][this->_position.y] = 2;
	    this->_position.y -= 1;
	}
	if (this->_direction == BOT && this->_position.y < WIDTH - 1) {
	    if (board[this->_position.x][this->_position.y] == 0)
		board[this->_position.x][this->_position.y] = 2;
            this->_position.y += 1;
	}
	if (this->_direction == LEFT && this->_position.x > 0) {
	    if (board[this->_position.x][this->_position.y] == 0)
		board[this->_position.x][this->_position.y] = 2;
            this->_position.x -= 1;
	}
	if (this->_direction == RIGHT && this->_position.x < HEIGHT - 1) {
	    if (board[this->_position.x][this->_position.y] == 0)
		board[this->_position.x][this->_position.y] = 2;
            this->_position.x += 1;
	}

	// Traversée
	if (board[this->_position.x][this->_position.y] == 0) {
            this->_cross = true;
        }

	// Arrivée à un bord
	if (board[this->_position.x][this->_position.y] != 0 && this->_cross == true) {
	    updateZone(board, monster);
	    this->_direction = NO;
	    this->_cross = false;
        }
    }

    vector_t player::getPos() const
    {
	return (this->_position);
    }
}
