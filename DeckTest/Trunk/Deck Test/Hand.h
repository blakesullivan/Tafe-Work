//Blake Sullivan - Hand.h
#ifndef HAND_H
#define HAND_H

#include "LinkedList.h"
#include "Garden.h"

class Hand : public LinkedList
{
private:
	Hand* m_pNextHand;
	string m_sPlayerName;
	Garden* m_pGarden;

public:
	Hand();
	Hand(string);
	~Hand();

	void SetNextHand(Hand*);
	void SetPlayerName(string);
	void SetGarden(Garden*);

	Hand* GetNextHand();
	string GetPlayerName();
	Garden* GetGarden();
};

#endif