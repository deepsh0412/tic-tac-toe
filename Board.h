#pragma once
#include <iostream>
#include <vector>
using namespace std;

class GameClass;

class Board
{
	int size;
	vector<vector<char>> board;
	int emptySpaces;
	bool isFinished;
	bool isWon;
	bool checkValidity(vector<int>);
	bool checkRows();
	bool checkColumns();
	bool checkDiagonals();
	bool boardWon();

	public:
	
	Board();
	~Board();
	bool isBoardFinished();
	bool isBoardWon();
	void showBoard();
	bool updateBoard(vector<int> p, char marker);
};
