//Blake Sullivan - List.cpp
#include "LinkedList.h"

LinkedList::LinkedList()
{
	m_pnHead = NULL;
	m_pnTail = NULL;
	m_pnCurrent = NULL;
}

LinkedList::~LinkedList()
{
	DeleteAll();
}

void LinkedList::AddNode()
{
	CreateNode();
	
	if (GetHead() == NULL)
	{
		SetHead(m_pnNew);
		SetCurrent(m_pnNew);
		SetTail(m_pnNew);
		m_pnCurrent->SetNextNode(NULL);
	}
	else
	{
		m_pnTail->SetNextNode(m_pnNew);
		SetTail(m_pnNew);
		SetCurrent(m_pnNew);
	}
	m_pnNew = NULL;
}

void LinkedList::CreateNode()
{
	m_pnNew = new Node;
}

void LinkedList::CopyNode(unsigned int uiCopyNum)
{
	Node* pNextNode = NULL;

	SetCurrent(GetHead());
	for (int i = 0; i < uiCopyNum; i++)
	{
		pNextNode = m_pnCurrent->GetNextNode();
		SetCurrent(pNextNode);
	}
	
	m_pnNew = new Node(*GetCurrent());
	m_pnTail->SetNextNode(m_pnNew);
	m_pnTail = m_pnNew;

}

void LinkedList::AddMultNode(unsigned int uiNodes)
{
	for (unsigned int i = 0; i < uiNodes; i++)
	{
		AddNode();
	}
}

void LinkedList::DeleteNode(unsigned int uiNodeNum)
{
	Node* pnNext = NULL; 
	Node* pnPrev = NULL;
	SetCurrent(GetHead());
	if (uiNodeNum == 0)
	{
		SetHead(GetCurrent()->GetNextNode());
	}
	else
	{
		for (unsigned int i = 0; i < uiNodeNum; i++)
		{
			pnPrev = GetCurrent();
			pnNext = m_pnCurrent->GetNextNode();
			SetCurrent(pnNext);
		}
		pnPrev->SetNextNode(m_pnCurrent->GetNextNode());
	}
	delete m_pnCurrent;
}

void LinkedList::DeleteAll()
{
	unsigned int uiMaxNodes = Node::GetNodeCount();
	Node* pnNext = NULL;

	SetCurrent(GetHead());
	for (unsigned int i = 0; i < uiMaxNodes; i++)
	{
		pnNext = m_pnCurrent->GetNextNode();
		delete m_pnCurrent;
		SetCurrent(pnNext);
	}
	SetHead(NULL);
	SetTail(NULL);
	SetCurrent(NULL);
}
void LinkedList::ViewNode(unsigned int uiNodeNum)
{
	Node* p_nNext = NULL;
	m_pnCurrent = m_pnHead;
	unsigned int i = 0;
	for (i = 0; i < uiNodeNum; i++)
	{
		p_nNext = m_pnCurrent->GetNextNode();
		m_pnCurrent = p_nNext;
	}
	cout << "Node[" << i << "]: " << m_pnCurrent->GetDisplayPos() << endl;
}
void LinkedList::ViewAll()
{
	Node* p_nNext = NULL;
	m_pnCurrent = m_pnHead;
	for (unsigned int i = 0; i < Node::GetNodeCount(); i++)
	{
		cout << "Node[" << i << "]: " << m_pnCurrent->GetDisplayPos() << endl;
		p_nNext = m_pnCurrent->GetNextNode();
		m_pnCurrent = p_nNext;
	}
}

void LinkedList::SetHead(Node* h)
{
	m_pnHead = h;
}
void LinkedList::SetTail(Node* t)
{
	m_pnTail = t;
}
void LinkedList::SetCurrent(Node* c)
{
	m_pnCurrent = c;
}
Node* LinkedList::GetHead()
{
	return m_pnHead;
}
Node* LinkedList::GetTail()
{
	return m_pnTail;
}
Node* LinkedList::GetCurrent()
{
	return m_pnCurrent;
}