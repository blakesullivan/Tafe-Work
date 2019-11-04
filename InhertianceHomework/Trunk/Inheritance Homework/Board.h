//Blake Sullivan - Board.h
#ifndef BOARD
#define BOARD

#include "Game.h"

class Board: public Game
{
protected:
	int m_iHorSquares;
	int m_iVertSquares;
public:
	Board();

	void Init(int, int, int);
	void Display(bool);
};
#endif