//Blake Sullivan - ChessBoard.cpp
#include "ChessBoard.h"

ChessBoard::ChessBoard()
{
	m_iPieces = 0;
	Display(false);
}

void ChessBoard::Init(int pl, int hs, int vs, int pi)
{
	Board::Init(pl, hs, vs);
	m_iPieces = pi;
	Display(true);
}

void ChessBoard::Display(bool bPostInit)
{
	if (bPostInit == true)
		{cout << "ChessBoard POST Init() DISPLAY SECTION" << endl;}
	else
		{cout << "ChessBoard PRE Init() DISPLAY SECTION" << endl;}
	cout << "m_iPieces: " << m_iPieces << endl;
}