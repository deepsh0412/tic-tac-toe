#include "Board.h"

Board::Board():size(3),board(size, vector<char>(size, '\0'))
{
	cout << "Board created" << endl;
	isFinished = false;
	isWon = false;
	emptySpaces = size*size;
}

Board::~Board()
{
	cout << "Board destroyed" << endl;
}

bool Board::isBoardFinished()
{
	return isFinished;
}

bool Board::isBoardWon()
{
	return isWon;
}

void Board::showBoard()
{
	cout << endl;
	for(int i = 0; i < 3; i++)
	{
		cout << "\t\t";
		for(int j = 0; j < 6; j++)
		{
			cout << '_';
		}
		cout << endl <<  "\t\t|";
		for(int j = 0; j < 3; j++)
		{
			cout << ((board[i][j] == '\0')?'_':board[i][j]) << "|";
		}
		cout << endl;
	}
}

bool Board::checkValidity(vector<int> input)
{
	if(board[input[0]][input[1]] != '\0')
	{
		return false;
	}
	return true;
}

bool Board::checkRows()
{
	for(int i = 0; i < 3; i++)
	{
		if(board[i][0] && board[i][1] && board[i][2] && (board[i][0] == board[i][1]) && (board[i][1] == board[i][2]))
			return true;
	}
	return false;
}

bool Board::checkColumns()
{
	for(int i = 0; i < 3; i++)
	{
		if(board[0][i] && board[1][i] && board[2][i] && (board[0][i] == board[1][i]) && (board[1][i]  == board[2][i]))
			return true;
	}
	return false;
}

bool Board::checkDiagonals()
{
	if(board[0][0] && board[1][1] && board[2][2] && (board[0][0] == board[1][1]) && (board[1][1] == board[2][2]))
		return true;
	
	if(board[0][2] && board[1][1] && board[2][0] && (board[0][2] == board[1][1]) && (board[1][1] == board[2][0]))
		return true;

	return false;
}

bool Board::boardWon()
{
	if(checkRows())
		return true;
	
	if(checkColumns())
		return true;

	if(checkDiagonals())
		return true;
	
	return false;
}

bool Board::updateBoard(vector<int> input, char marker)
{
	if(!checkValidity(input))
		return false;	

	board[input[0]][input[1]] = marker;
	emptySpaces--;
	
	if(emptySpaces == 0)
	{
		isFinished = true;
	}
	
	if(boardWon())
	{
		isWon = true;
	}
	
	return true;
}
