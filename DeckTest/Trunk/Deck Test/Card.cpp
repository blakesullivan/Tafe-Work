//Blake Sullivan - Card.cpp
#include "Card.h"

unsigned int Card::ms_uiCardCount = 0;

Card::Card()
{
	//SetDisplayPos(ms_uiCardCount);
	SetNextCard(NULL);
	//cout << "Card " << ms_uiCardCount << " Constructed" << endl;
}

Card::Card(const Card& n)
{
	SetDisplayPos(n.GetDisplayPos());
	SetName(n.GetName());
	SetPicPos(n.GetPicPos());
	SetValue(n.GetValue());
	SetRuleValue(n.GetRuleValue());
	SetNextCard(NULL);
	
	cout << "Card[" << n.GetDisplayPos() << "] Copied!" << endl;
}

Card::~Card()
{
	cout << "Card " << m_uiDisplayPos << " destructed!" << endl;
}

void Card::SetNextCard(Card* n)
{
	m_pNextCard = n;
}

void Card::SetDisplayPos(const unsigned int dp)
{
	m_uiDisplayPos = dp;
}
void Card::SetName(string n)
{
	m_sName = n;
}
void Card::SetPicPos(unsigned int pp)
{
	m_uiPicPos = pp;
}
void Card::SetValue(unsigned int v)
{
	m_uiValue = v;
}
void Card::SetRuleValue(unsigned int rv)
{
	m_uiRuleValue = rv;
}

Card* Card::GetNextCard() const
{
	return m_pNextCard;
}

unsigned int Card::GetDisplayPos() const
{
	return m_uiDisplayPos;
}

string Card::GetName() const
{
	return m_sName;
}
unsigned int Card::GetPicPos() const
{
	return m_uiPicPos;
}
unsigned int Card::GetValue() const
{
	return m_uiValue;
}
unsigned int Card::GetRuleValue() const
{
	return m_uiRuleValue;
}

int Card::operator+(Card* c)
{
	int total = 0;
	total = m_uiValue + c->GetValue();
	return total;
}
bool Card::operator<(Card* c)
{
	bool result = false;
	if (m_uiPicPos < c->GetPicPos())
		{result = true;}
	else
		{result = false;}

	return result;
}
bool Card::operator<=(Card* c)
{
	bool result = false;
	if (m_uiPicPos <= c->GetPicPos())
		{result = true;}
	else
		{result = false;}

	return result;
}
bool Card::operator>(Card* c)
{
	bool result = false;
	if (m_uiPicPos > c->GetPicPos())
		{result = true;}
	else
		{result = false;}

	return result;
}
bool Card::operator>=(Card* c)
{
	bool result = false;
	if (m_uiPicPos >= c->GetPicPos())
		{result = true;}
	else
		{result = false;}

	return result;
}