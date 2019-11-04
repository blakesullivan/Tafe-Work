//Blake Sullivan - List.h
#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Card.h"

class LinkedList
{
protected:
	Card *m_pHead;
	Card *m_pTail;
	Card *m_pCurrent;
	Card *m_pNew;

	unsigned int m_uiCardCount;

public:
	LinkedList();
	~LinkedList();

	void AddCard();
	void AddMultCard(unsigned int);
	void DeleteCard(unsigned int);
	void DeleteAll();
	void ViewCard(unsigned int);
	void ViewAll();

	void CreateCard();
	void CopyCard(unsigned int);
	void CopyCard(Card*);

	void SetHead(Card*);
	void SetTail(Card*);
	void SetCurrent(Card*);
	void SetCardCount(unsigned int);
	Card* GetHead();
	Card* GetTail();
	Card* GetCurrent();
	unsigned int GetCardCount();

	Card* FindCard(unsigned int);
};
#endif