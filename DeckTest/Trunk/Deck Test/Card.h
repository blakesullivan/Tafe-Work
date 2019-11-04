//Blake Sullivan - Card.h
#ifndef CARD_H
#define CARD_H

#include <string>
#include <iostream>
using namespace std;
class Card
{
private:
	static unsigned int ms_uiCardCount;
	Card* m_pNextCard;
	unsigned int m_uiDisplayPos;
	string m_sName;
	unsigned int m_uiPicPos;
	unsigned int m_uiValue;
	unsigned int m_uiRuleValue;

public:
	Card();
	Card(const Card&);
	~Card();
	
	void SetNextCard(Card*);
	void SetDisplayPos(const unsigned int);
	void SetName(string);
	void SetPicPos(unsigned int);
	void SetValue(unsigned int);
	void SetRuleValue(unsigned int);

	Card* GetNextCard() const;
	unsigned int GetDisplayPos() const;
	string GetName() const;
	unsigned int GetPicPos() const;
	unsigned int GetValue() const;
	unsigned int GetRuleValue() const;

	int operator+(Card*);
	bool operator<(Card*);
	bool operator<=(Card*);
	bool operator>(Card*);
	bool operator>=(Card*);

};
#endif