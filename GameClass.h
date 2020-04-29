#pragma once
#include <iostream>
#include <vector>
#include "Player.h"
#include "Board.h"
using namespace std;

enum class BOARD_STATUS{ GAME_ONGOING, GAME_DRAW, GAME_WON, GAME_STOPPED};

class GameClass
{
	vector<Player*> players;
	BOARD_STATUS boardStatus;
	Board* board = nullptr;
	int playerInTurn = 0;
	bool validateGame();
	Player* whoShouldPlayNext();

	public:
	GameClass();
	~GameClass();
	void start();
	void stop();
	void play();
	void showBoard();
	void moveToNextPlayer();
	BOARD_STATUS checkBoard();
	void addBoard(Board* b);
	void addPlayer(Player* p);
};
