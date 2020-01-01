/*
<** EPITECH PROJECT, 2018
** OOP_arcade_2018
** File description:
** qix.hpp
*/

#pragma once
#include "IGameHandler.hpp"
#include "IGraphicalLibHandler.hpp"
#include <sstream>

#define WIDTH 50
#define HEIGHT 30

namespace arcade
{
    enum Direction
    {
	NO,
	TOP,
	BOT,
	LEFT,
	RIGHT,
	TL,
	TR,
	BL,
	BR
    };

    class monster {
    public:
        monster(int speed = 1);
	void changeDir(Direction dir = NO);
	void changeSpeed(int speed = 0);
	int getSpeed() const;
        void move(int board[HEIGHT][WIDTH]);
	vector_t getPos() const;

    private:
        Direction _direction;
        int _speed;
	vector_t _position = {HEIGHT / 2, WIDTH / 2 - 1};
    };

    class player {
    public:
        player(int speed = 1);
        void changeDir(Direction dir = NO);
        void changeSpeed(int speed = 0);
        int getSpeed() const;
        void move(int board[HEIGHT][WIDTH], monster *monster);
	vector_t getPos() const;

    private:
        Direction _direction;
        int _speed;
        vector_t _position = {0, WIDTH / 2 - 1};
	bool _cross = false;
    };

    class qixgame : public IGameHandler {
    public:
	qixgame() {};
	void initialize(IGraphicalHandler *);
	void displayScreen();
	void inputs();
	void gameLogic();
	void free_ressources();
	void drawBoard();
	int getScore() const;

    private:
	Clock _timePlayer;
	player *_player;
	monster *_monster;
	int _board[HEIGHT][WIDTH];
	int _score = 0;
    };

    void changeMonsterZone(int board[HEIGHT][WIDTH], vector_t pos);
    void updateZone(int board[HEIGHT][WIDTH], monster *monster);
}
