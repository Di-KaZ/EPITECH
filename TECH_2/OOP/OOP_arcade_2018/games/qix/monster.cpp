/*
** EPITECH PROJECT, 2019
** player.cpp
** File description:
** qix->monster.cpp
*/

#include "qix.hpp"

namespace arcade
{
    monster::monster(int speed) :
	_speed(speed),
	_direction(BR)
    {}

    void monster::changeDir(Direction dir)
    {
	this->_direction = dir;
    }

    void monster::changeSpeed(int speed)
    {
	this->_speed = speed;
    }

    int monster::getSpeed() const
    {
	return (this->_speed);
    }

    void monster::move(int board[HEIGHT][WIDTH])
    {
	// Déplacement génériques
	if (this->_direction == BR) {
	    if (board[this->_position.x + 1][this->_position.y + 1] == 0) {
		this->_position.x += 1;
		this->_position.y += 1;
	    } else {
		if (board[this->_position.x + 1][this->_position.y] != 0 &&
                board[this->_position.x][this->_position.y + 1] == 0)
		    this->_direction = TR;
		else if (board[this->_position.x][this->_position.y + 1] != 0 &&
                board[this->_position.x + 1][this->_position.y] == 0)
		    this->_direction = BL;
		else
		    this->_direction = TL;
	    }
	}
	if (this->_direction == BL) {
	    if (board[this->_position.x + 1][this->_position.y - 1] == 0) {
		this->_position.x += 1;
		this->_position.y -= 1;
	    } else {
		if (board[this->_position.x + 1][this->_position.y] != 0 &&
                board[this->_position.x][this->_position.y - 1] == 0)
                    this->_direction = TL;
                else if (board[this->_position.x][this->_position.y - 1] != 0 &&
                board[this->_position.x + 1][this->_position.y] == 0)
                    this->_direction = BR;
		else
		    this->_direction = TR;
	    }
        }
	if (this->_direction == TR) {
	    if (board[this->_position.x - 1][this->_position.y + 1] == 0) {
		this->_position.x -= 1;
		this->_position.y += 1;
	    } else {
		if (board[this->_position.x - 1][this->_position.y] != 0 &&
                board[this->_position.x][this->_position.y + 1] == 0)
                    this->_direction = BR;
                else if (board[this->_position.x][this->_position.y + 1] != 0 &&
                board[this->_position.x - 1][this->_position.y] == 0)
                    this->_direction = TL;
		else
		    this->_direction = BL;
	    }
        }
	if (this->_direction == TL) {
            if (board[this->_position.x - 1][this->_position.y - 1] == 0) {
		this->_position.x -= 1;
		this->_position.y -= 1;
	    } else {
		if (board[this->_position.x - 1][this->_position.y] != 0 &&
                board[this->_position.x][this->_position.y - 1] == 0)
                    this->_direction = BL;
                else if (board[this->_position.x][this->_position.y - 1] != 0 &&
                board[this->_position.x - 1][this->_position.y] == 0)
                    this->_direction = TR;
		else
		    this->_direction = BR;
	    }
        }

	// Touche trainée
	if (board[this->_position.x][this->_position.y] == 2) {
	    vector_t pos = {HEIGHT / 2, WIDTH / 2};
	    this->_direction = NO;
        }

	// // Arrivée à un bord
	// if (board[this->_position.x][this->_position.y] == 2 && this->_cross == true) {
	//     updateZone(board);
	//     this->_direction = NO;
	//     this->_cross = false;
        // }
    }

    vector_t monster::getPos() const
    {
	return (this->_position);
    }
}
