#ifndef DECK_H
#define DECK_H

#include "Linked_List.h"
#include "Hand.h"

#include <iostream>
#include <ctime> 
#include <cstdlib>
#include <iomanip>
#include <string>
 
using namespace std;

class Deck
{
private:
	Linked_List *deckOfCards;
	Hand *player;
	int deckSize;
	int numberOfPlayers;


public:
	Deck(int);
	~Deck();
	void createDeck();
	void shuffleDeck();

};
#endif
