//Blake Sullivan - RosesCard.cpp
#include "RosesCard.h"

RosesCard::RosesCard()
{
	m_iCardsInHand = 0;
	Display(false);
}

void RosesCard::Init(int p, int s, int ds, int c)
{
	Card::Init(p, s, ds);
	m_iCardsInHand = c;
	Display(true);
}

void RosesCard::Display(bool bPostInit)
{
	if (bPostInit == true)
		{cout << "RosesCard POST Init() DISPLAY SECTION" << endl;}
	else
		{cout << "RosesCard PRE Init() DISPLAY SECTION" << endl;}
	cout << "m_iCardsInHand: " << m_iCardsInHand << endl;
}