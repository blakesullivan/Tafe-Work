//Blake Sullivan - Deck.cpp
#include "Deck.h"

Deck::Deck()
{
}

Deck::Deck(unsigned int deckSize)
{
	AddMultCard(deckSize);
	AssignCardValues();
}

Deck::~Deck()
{
}

void Deck::AssignCardValues()
{
	Card* pNextCard = NULL;
	SetCurrent(GetHead());
	//int i = 0;
	for (int i = 0; i < GetCardCount(); i++)
	{
		//i = rand() % Card::GetCardCount();
		//cout << i << endl;
		if (i < 10) //1 Plant
		{
			GetCurrent()->SetName("One Plant");
			GetCurrent()->SetPicPos(1);
			GetCurrent()->SetValue(1);
			GetCurrent()->SetRuleValue(0);
		}
		else if (i < 20) //2 Plant
		{
			GetCurrent()->SetName("Two Plant");
			GetCurrent()->SetPicPos(2);
			GetCurrent()->SetValue(2);
			GetCurrent()->SetRuleValue(0);
		}
		else if (i < 26) //3 Plant
		{
			GetCurrent()->SetName("Three Plant");
			GetCurrent()->SetPicPos(3);
			GetCurrent()->SetValue(3);
			GetCurrent()->SetRuleValue(0);
		}
		else if (i < 29) //4 Plant
		{
			GetCurrent()->SetName("Four Plant");
			GetCurrent()->SetPicPos(4);
			GetCurrent()->SetValue(4);
			GetCurrent()->SetRuleValue(0);
		}
		else if (i < 30) //6 Plant
		{
			GetCurrent()->SetName("Six Plant");
			GetCurrent()->SetPicPos(5);
			GetCurrent()->SetValue(6);
			GetCurrent()->SetRuleValue(0);
		}
		else if (i < 35) //Dandelion
		{
			GetCurrent()->SetName("Dandelion");
			GetCurrent()->SetPicPos(6);
			GetCurrent()->SetValue(0);
			GetCurrent()->SetRuleValue(1);
		}
		else if (i < 40) //Weed Killer
		{
			GetCurrent()->SetName("Weed Killer");
			GetCurrent()->SetPicPos(7);
			GetCurrent()->SetValue(0);
			GetCurrent()->SetRuleValue(2);
		}
		else if (i < 45) //Steal
		{
			GetCurrent()->SetName("Steal");
			GetCurrent()->SetPicPos(8);
			GetCurrent()->SetValue(0);
			GetCurrent()->SetRuleValue(3);
		}
		else if (i < 48) //Thrips
		{
			GetCurrent()->SetName("Thrip");
			GetCurrent()->SetPicPos(9);
			GetCurrent()->SetValue(0);
			GetCurrent()->SetRuleValue(4);
		}
		else if (i < 50) //Flower Show
		{
			GetCurrent()->SetName("Flower Show");
			GetCurrent()->SetPicPos(10);
			GetCurrent()->SetValue(0);
			GetCurrent()->SetRuleValue(5);
		}
		else //Potzilla
		{
			GetCurrent()->SetName("Rosezilla");
			GetCurrent()->SetPicPos(11);
			GetCurrent()->SetValue(0);
			GetCurrent()->SetRuleValue(6);
		}
		pNextCard = GetCurrent()->GetNextCard();
		SetCurrent(pNextCard);
	}
}

void Deck::Sort()
{
	Card* pNext = NULL;
	SetCurrent(GetHead());
	//cout << Card::GetCardCount() << endl;
	for (int i = 0; i < GetCardCount(); i++)
	{
		cout << i << ": ";
		pNext = GetCurrent()->GetNextCard();
		if (pNext == NULL) {break;}
		/*if (*GetCurrent() < pNext)
		{
			cout << GetCurrent()->GetName() << "(" << GetCurrent()->GetValue() << ") is less than " << pNext->GetName() << "(" << pNext->GetValue() << ")" << endl;
		}
		else
		{
			cout << GetCurrent()->GetName() << "(" << GetCurrent()->GetValue() << ") is NOT less than " << pNext->GetName() << "(" << pNext->GetValue() << ")" << endl;
		}*/
		SetCurrent(GetCurrent()->GetNextCard());		
	}
}