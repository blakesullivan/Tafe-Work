//Blake Sullivan - RosesCard.h
#ifndef ROSESCARD
#define ROSESCARD

#include "Card.h"

class RosesCard: virtual public Card
{
private:
	int m_iCardsInHand;

public:
	RosesCard();

	void Init(int, int, int, int);
	void Display(bool);
};
#endif