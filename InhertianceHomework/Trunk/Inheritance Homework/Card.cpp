//Blake Sullivan - Card.cpp
#include "Card.h"

Card::Card()
{
	m_iSuits = 0;
	m_iDeckSize = 0;
	Display(false);
}

void Card::Init(int p, int s, int ds)
{
	Game::Init(p);
	m_iSuits = s;
	m_iDeckSize = ds;
	Display(true);
}

void Card::Display(bool bPostInit)
{
	if (bPostInit == true)
		{cout << "Card POST Init() DISPLAY SECTION" << endl;}
	else
		{cout << "Card PRE Init() DISPLAY SECTION" << endl;}
	cout << "m_iSuits: " << m_iSuits << endl;
	cout << "m_iDeckSize: " << m_iDeckSize << endl;
}