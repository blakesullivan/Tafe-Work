//Blake Sullivan - List.cpp
#include "LinkedList.h"

LinkedList::LinkedList()
{
	m_pHead = NULL;
	m_pTail = NULL;
	m_pCurrent = NULL;
	m_uiCardCount = 0;
}

LinkedList::~LinkedList()
{
	DeleteAll();
}

void LinkedList::AddCard()
{
	CreateCard();
	
	if (GetHead() == NULL)
	{
		SetHead(m_pNew);
		SetCurrent(m_pNew);
		SetTail(m_pNew);
		GetCurrent()->SetNextCard(NULL);
	}
	else
	{
		GetTail()->SetNextCard(m_pNew);
		SetTail(m_pNew);
		SetCurrent(m_pNew);
	}
	m_pNew = NULL;
	GetCurrent()->SetDisplayPos(GetCardCount());
	m_uiCardCount++;
}

void LinkedList::CreateCard()
{
	m_pNew = new Card;
}

void LinkedList::CopyCard(unsigned int uiCopyNum)
{
	Card* pNextCard = NULL;

	SetCurrent(GetHead());
	for (int i = 0; i < uiCopyNum; i++)
	{
		pNextCard = m_pCurrent->GetNextCard();
		SetCurrent(pNextCard);
	}
	
	m_pNew = new Card(*GetCurrent());
	m_pTail->SetNextCard(m_pNew);
	m_pTail = m_pNew;
	m_uiCardCount++;
}

void LinkedList::CopyCard(Card* pCard)
{
	m_pNew = new Card(*pCard);
	if (m_pHead == NULL) {SetHead(m_pNew);}
	if (m_pTail != NULL) {m_pTail->SetNextCard(m_pNew);}
	m_pTail = m_pNew;
	m_uiCardCount++;
}

void LinkedList::AddMultCard(unsigned int uiCards)
{
	for (unsigned int i = 0; i < uiCards; i++)
	{
		AddCard();
	}
}

void LinkedList::DeleteCard(unsigned int uiCardNum)
{
	Card* pNext = NULL;
	Card* pPrev = NULL;
	SetCurrent(GetHead());
	if (0 == uiCardNum)
		{SetHead(GetCurrent()->GetNextCard());}
	else
	{
		for (unsigned int i = 0; i < uiCardNum; i++)
		{
			pPrev = GetCurrent();
			pNext = GetCurrent()->GetNextCard();
			SetCurrent(pNext);
		}
		if (GetCurrent() == GetTail())
		{
			pPrev->SetNextCard(NULL);
			SetTail(pPrev);
		}
		else
			{pPrev->SetNextCard(GetCurrent()->GetNextCard());}
	}
	delete GetCurrent();
	m_uiCardCount--;
}

void LinkedList::DeleteAll()
{
	unsigned int uiMaxCards = GetCardCount();
	Card* pnNext = NULL;

	SetCurrent(GetHead());
	for (unsigned int i = 0; i < uiMaxCards; i++)
	{
		pnNext = m_pCurrent->GetNextCard();
		delete m_pCurrent;
		m_uiCardCount--;
		SetCurrent(pnNext);
	}
	SetHead(NULL);
	SetTail(NULL);
	SetCurrent(NULL);
}
void LinkedList::ViewCard(unsigned int uiCardNum)
{
	Card* p_nNext = NULL;
	m_pCurrent = m_pHead;
	unsigned int i = 0;
	for (i = 0; i < uiCardNum; i++)
	{
		p_nNext = m_pCurrent->GetNextCard();
		m_pCurrent = p_nNext;
	}
	cout << "Card[" << i << "]: " << m_pCurrent->GetDisplayPos() << endl;
	cout << "\t" << m_pCurrent->GetName();
	if (m_pCurrent->GetName().length() < 8) {cout << "\t";}
	cout << "\t" << m_pCurrent->GetPicPos();
	cout << "\t" << m_pCurrent->GetValue();
	cout << "\t" << m_pCurrent->GetRuleValue() << endl;
}
void LinkedList::ViewAll()
{
	Card* p_nNext = NULL;
	m_pCurrent = m_pHead;
	for (unsigned int i = 0; i < GetCardCount(); i++)
	{
		cout << "Card[" << i << "]:" << m_pCurrent->GetDisplayPos();
		cout << "\t" << m_pCurrent->GetName();
		if (m_pCurrent->GetName().length() < 8) {cout << "\t";}
		cout << "\t" << m_pCurrent->GetPicPos();
		cout << "\t" << m_pCurrent->GetValue();
		cout << "\t" << m_pCurrent->GetRuleValue() << endl;
		p_nNext = m_pCurrent->GetNextCard();
		m_pCurrent = p_nNext;
	}
}

void LinkedList::SetHead(Card* h)
{
	m_pHead = h;
}
void LinkedList::SetTail(Card* t)
{
	m_pTail = t;
}
void LinkedList::SetCurrent(Card* c)
{
	m_pCurrent = c;
}
void LinkedList::SetCardCount(unsigned int cc)
{
	m_uiCardCount = cc;
}
Card* LinkedList::GetHead()
{
	return m_pHead;
}
Card* LinkedList::GetTail()
{
	return m_pTail;
}
Card* LinkedList::GetCurrent()
{
	return m_pCurrent;
}

Card* LinkedList::FindCard(unsigned int uiCardNum)
{
	SetCurrent(GetHead());
	for (int i = 0; i < uiCardNum; i++)
	{
		SetCurrent(GetCurrent()->GetNextCard());
	}
	return GetCurrent();
}

unsigned int LinkedList::GetCardCount()
{
	return m_uiCardCount;
}