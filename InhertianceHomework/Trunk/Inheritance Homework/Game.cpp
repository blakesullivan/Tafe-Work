//Blake Sullivan - Game.cpp
#include "Game.h"

Game::Game()
{
	m_iPlayers = 0;
	Display(false);
}

void Game::Init(int p)
{
	m_iPlayers = p;
	Display(true);
}

void Game::Display(bool bPostInit)
{
	if (bPostInit == true)
		{cout << "Game POST Init() DISPLAY SECTION" << endl;}
	else
		{cout << "Game PRE Init() DISPLAY SECTION" << endl;}
	cout << "m_iPlayers: " << m_iPlayers << endl;
}
