#include "Player.h"

Player::Player(string playerName,utility* utils):name(playerName),util(utils)
{
	cout << "Player named " << name << " created" << endl;
	marker = '\0';
}

Player::~Player()
{
	cout << "Player named " << name << " destroyed" << endl;
}

string Player::getName()
{
	return name;
}

char Player::getMarker()
{
	return marker;
}

void Player::setMarker(char mark)
{
	if(mark == 'O' || mark == 'X')
	marker = mark;
}

bool Player::parseInput(string s, vector<int> (&input))
{
	char delimeter = ',';
	string token;
	istringstream tokenStream(s);
	while(getline(tokenStream, token, delimeter))
	{
		try
		{
			int int_token = stoi(token);
			input.push_back(int_token-1);
		}
		catch(...)
		{
			cout << "Error" << endl;
			return false;
		}
	}
	
	return true;
}

bool Player::validateInput(vector<int> (&input))
{
	if(input.size() != 2)
		return false;

	if((input[0] < 0 || input[0] > 2) || (input[1] < 0 || input[1] > 2))
		return false;

	return true;
}

bool Player::placeMarker(vector<int> (&parsedInput))
{
	cout << name << " please enter index to be updated" << endl;
	string input = util->getStringInput();

	if(!parseInput(input, parsedInput))
	{
		cout << "parsing failed, retry with correct format" << endl;
		return false;
	}

	if(!validateInput(parsedInput))
	{
		cout << "Invalid Input, retry with correct format" << endl;
		return false;
	}
	return true;
}

/*
string Player::getUserInput()
{
	string input;
	cin >> input;
	return input;
}*/
