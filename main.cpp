#include <iostream>
#include "GameClass.h"
#include "Board.h"
#include "Player.h"
#include "utility.h"
using namespace std;

int main(int argc, char** argv)
{
	GameClass game;

	Board* b = new Board();
	game.addBoard(b);

	utility *util1 = new utility();
	Player *p1 = new Player("Player1",util1);
	utility *util2 = new utility();
	Player *p2 = new Player("Player2",util2);
	game.addPlayer(p1);
	game.addPlayer(p2);

	game.start();

	return 0;
}
