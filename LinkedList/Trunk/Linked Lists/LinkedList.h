//Blake Sullivan - List.h
#ifndef LINKEDLIST
#define LINKEDLIST

#include "Node.h"

class LinkedList
{
private:
	Node *m_pnHead;
	Node *m_pnTail;
	Node *m_pnCurrent;
	Node *m_pnNew;

public:
	LinkedList();
	~LinkedList();

	void AddNode();
	void AddMultNode(unsigned int);
	void DeleteNode(unsigned int);
	void DeleteAll();
	void ViewNode(unsigned int);
	void ViewAll();

	void CreateNode();
	void CopyNode(unsigned int);

	void SetHead(Node*);
	void SetTail(Node*);
	void SetCurrent(Node*);
	Node* GetHead();
	Node* GetTail();
	Node* GetCurrent();
};
#endif