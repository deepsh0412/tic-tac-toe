#pragma once
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include "utility.h"
using namespace std;

class GameClass;

class Player
{
	string name;
	char marker;
	utility* util;
	bool validateInput(vector<int> (&input));
	bool parseInput(string s,vector<int> (&parsedInput));
	string getUserInput();

	public:
	
	Player(string playerName,utility* utils);
	~Player();
	string getName();
	char getMarker();
	void setMarker(char marker);
	bool placeMarker(vector<int> (&parsedInput));
};
