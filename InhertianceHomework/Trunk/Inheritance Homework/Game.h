//Blake Sullivan - Game.h
#ifndef GAME
#define GAME

#include <iostream>
using namespace std;

class Game
{
protected:
	int m_iPlayers;
public:
	Game();

	void Init(int);
	void Display(bool);
};
#endif