//Blake Sullivan - Deck.h
#ifndef DECK_H
#define DECK_H

#include "LinkedList.h"

class Deck : public LinkedList
{
private:
	
public:
	Deck();
	Deck(unsigned int);
	~Deck();

	void Deal();
	void AssignCardValues();
	void Sort();
};
#endif