#include <iostream>
#include "GameClass.h"
#include "Board.h"
#include "Player.h"
using namespace std;

int main(int argc, char** argv)
{
	GameClass game;

	Board* b = new Board();
	game.addBoard(b);

	Player *p1 = new Player("Player1");
	Player *p2 = new Player("Player2");
	game.addPlayer(p1);
	game.addPlayer(p2);

	game.start();

	return 0;
}
