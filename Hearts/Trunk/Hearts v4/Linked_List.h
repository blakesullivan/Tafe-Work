#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include "Node.h"

#include <iostream>
#include <ctime> 
#include <cstdlib>
#include <iomanip>
using namespace std;

class Linked_List
{
private:
	Node *ptrNode;
	Node *ptrHead;
	Node *ptrTail;
	Node *ptrCurrent;

public:
	Linked_List();
	~Linked_List();
	Node* createNode(int iNodeValue);
	void addNode(Node* ptrNode);
	void createDeck(int);
	void displayNodes(int);
	void displayHand();
	Node* searchList(int, int);
	Node* getNode();
	void sortHands();
};
#endif