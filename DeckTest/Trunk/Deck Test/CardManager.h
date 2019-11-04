//Blake Sullivan - CardManager.h
#ifndef CARDMANAGER_H
#define CARDMANAGER_H

#include "Deck.h"
#include "Hand.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <string>
using namespace std;

class CardManager
{
private:
	Deck* m_pDeck;
	Hand* m_pHeadHand;
	
public:
	CardManager();
	~CardManager();

	void Init(int, int);

	void ManagePlay();
	void BeginDeal(unsigned int);
	void DealCard(unsigned int, LinkedList*, LinkedList*);
	void PlaceCard(unsigned int, LinkedList*, LinkedList*);
	void DisplayHands();
	void PlayCardOptions(Hand*);

	void SetDeck(Deck*);
	void SetHeadHand(Hand*);

	Deck* GetDeck();
	Hand* GetHeadHand();
	Hand* GetHand(int);
};
#endif