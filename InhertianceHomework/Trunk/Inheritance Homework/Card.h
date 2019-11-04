//Blake Sullivan - Card.h
#ifndef CARD
#define CARD

#include "Game.h"
class Card: public Game
{
protected:
	int m_iSuits;
	int m_iDeckSize;
public:
	Card();

	void Init(int, int, int);
	void Display(bool);
};
#endif