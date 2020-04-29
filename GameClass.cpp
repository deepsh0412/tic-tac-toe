#include "GameClass.h"

GameClass::GameClass()
{
	cout << "GameClass instance created" << endl;
}

GameClass::~GameClass()
{
	delete board;
	for(auto i: players)
		delete i;
	players.clear();
	cout << "GameClass instance destroyed" << endl;
}

bool GameClass::validateGame()
{
	cout << "Validating game" << endl;
	
	if(players.size() != 2)
	{
		cout << "insufficient or more players" << players.size() << endl;
		return false;
	}

	if(!board)
	{
		cout << "Board not created" << endl;
		return false;
	}
	
	return true;
}

void GameClass::start()
{
	cout << "Starting game" << endl;
	boardStatus = BOARD_STATUS::GAME_ONGOING;
	
	if(validateGame())
	{
		cout << "valid game" << endl;
		play();
	}
	else
	{
		cout << "invalid game" << endl;
		stop();
		return;
	}

	return;
}

void GameClass::stop()
{
	cout << "Game stopped" << endl;
	boardStatus = BOARD_STATUS::GAME_STOPPED;
	return;
}

void GameClass::play()
{
	cout << "Started playing" << endl;
	cout << "Please enter row,column where you need to mark" << endl;
	
	while(1)
	{
		showBoard();
		Player* p = whoShouldPlayNext();
		
		if(!board->updateBoard(p->placeMarker(), p->getMarker()))
		{
			cout << "Invalid index updated, try again " << p->getName() << " !!!" << endl;
			continue;
		}
		boardStatus = checkBoard();
		
		if(boardStatus == BOARD_STATUS::GAME_DRAW)
		{
			showBoard();
			cout << "Game draw" << endl;
			break;
		}
		else if(boardStatus == BOARD_STATUS::GAME_WON)
		{
			showBoard();
			cout << p->getName() << " won the game" << endl;
			break;
		}
		moveToNextPlayer();
	}
	stop();
	return;
}

BOARD_STATUS GameClass::checkBoard()
{
	if(board->isBoardWon())
		return BOARD_STATUS::GAME_WON;
	else if(board->isBoardFinished())
		return BOARD_STATUS::GAME_DRAW;
	else
		return BOARD_STATUS::GAME_ONGOING;
}

void GameClass::addBoard(Board* b)
{
	board = b;
}

void GameClass::addPlayer(Player* p)
{
	if(players.size() == 0)
	{
		p->setMarker('O');
	}
	else
	{
		p->setMarker('X');
	}
	players.push_back(p);
}

void GameClass::showBoard()
{
	board->showBoard();
}

Player* GameClass::whoShouldPlayNext()
{
	return players[playerInTurn];
}

void GameClass::moveToNextPlayer()
{
	playerInTurn++;
	playerInTurn %= 2;
}
