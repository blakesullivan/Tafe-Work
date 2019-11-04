//Blake Sullivan - Board.cpp
#include "Board.h"

Board::Board()
{
	m_iHorSquares = 0;
	m_iVertSquares = 0;
	Display(false);
}

void Board::Init(int p, int hs, int vs)
{
	Game::Init(p);
	m_iHorSquares = hs;
	m_iVertSquares = vs;
	Display(true);
}

void Board::Display(bool bPostInit)
{
	if (bPostInit == true)
		{cout << "Board POST Init() DISPLAY SECTION" << endl;}
	else
		{cout << "Board PRE Init() DISPLAY SECTION" << endl;}
	cout << "m_iHorSquares: " << m_iHorSquares << endl;
	cout << "m_iVertSquares: " << m_iVertSquares << endl;
}