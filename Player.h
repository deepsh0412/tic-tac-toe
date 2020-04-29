#pragma once
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

class GameClass;

class Player
{
	string name;
	char marker;
	bool validateInput(vector<int> input);
	vector<int> parseInput(string s);
	string getUserInput();

	public:
	
	Player(string playerName);
	~Player();
	string getName();
	char getMarker();
	void setMarker(char marker);
	vector<int> placeMarker();
};
