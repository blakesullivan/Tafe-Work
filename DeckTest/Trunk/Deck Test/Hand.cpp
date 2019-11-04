//Blake Sullivan - Hand.cpp
#include "Hand.h"

Hand::Hand()
{
	SetNextHand(NULL);
	SetPlayerName("");
	SetGarden(new Garden());
}

Hand::Hand(string name)
{
	SetNextHand(NULL);
	SetPlayerName(name);
	SetGarden(new Garden());
}
Hand::~Hand()
{
	delete GetGarden();
}

void Hand::SetNextHand(Hand* nh)
{
	m_pNextHand = nh;
}
void Hand::SetPlayerName(string pn)
{
	m_sPlayerName = pn;
}
void Hand::SetGarden(Garden *g)
{
	m_pGarden = g;
}

Hand* Hand::GetNextHand()
{
	return m_pNextHand;
}
string Hand::GetPlayerName()
{
	return m_sPlayerName;
}
Garden* Hand::GetGarden()
{
	return m_pGarden;
}