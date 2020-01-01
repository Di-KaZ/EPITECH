/*
** EPITECH PROJECT, 2019
** board.cpp
** File description:
**
*/

#include "qix.hpp"

namespace arcade
{
    void changeMonsterZone(int board[HEIGHT][WIDTH], vector_t pos)
    {
	board[pos.x][pos.y] = 3;
	if (board[pos.x][pos.y - 1] == 0) {
	    vector_t tmp = {pos.x, pos.y - 1};
	    changeMonsterZone(board, tmp);
	}
	if (board[pos.x - 1][pos.y] == 0) {
	    vector_t tmp = {pos.x - 1, pos.y};
	    changeMonsterZone(board, tmp);
	}
	if (board[pos.x][pos.y + 1] == 0) {
            vector_t tmp = {pos.x, pos.y + 1};
            changeMonsterZone(board, tmp);
        }
        if (board[pos.x + 1][pos.y] == 0) {
            vector_t tmp = {pos.x + 1, pos.y};
            changeMonsterZone(board, tmp);
        }
    }

    void updateZone(int board[HEIGHT][WIDTH], monster *monster)
    {
	// 1 - Mise en tampon de la zone ennemie
	changeMonsterZone(board, monster->getPos());
	// 2 - Echange des zones vides
	for (int i = 0; i < HEIGHT - 1; i++) {
	    for (int j = 0; j < WIDTH - 1; j++) {
		if (board[i][j] == 0)
		    board[i][j] = -2;
	    }
	}
	// 3 - Changement des bordures
	for (int i = 0; i < HEIGHT - 1; i++) {
            for (int j = 0; j < WIDTH - 1; j++) {
                if (board[i][j] == 2)
                    board[i][j] = 1;
            }
        }
	for (int i = 0; i < HEIGHT - 1; i++) {
            for (int j = 0; j < WIDTH - 1; j++) {
                if (board[i][j] == 1 &&
		    (j == 0 || board[i][j - 1] != 3) &&
		    (j == WIDTH || board[i][j + 1] != 3) &&
		    (i == 0 || board[i - 1][j] != 3) &&
		    (i == 29  || board[i + 1][j] != 3))
		    board[i][j] = -1;
            }
        }
	// 4 - Remise en ligne de la zone de jeu
	for (int i = 0; i < HEIGHT - 1; i++) {
            for (int j = 0; j < WIDTH - 1; j++) {
                if (board[i][j] == 3)
                    board[i][j] = 0;
            }
        }
    }
}
