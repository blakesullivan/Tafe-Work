#ifndef HAND_H
#define HAND_H

#include "Linked_List.h"

#include <iostream>
#include <ctime> 
#include <cstdlib>
#include <iomanip>
using namespace std;

class Hand
{
private:
	Node *ptrHandHead;
	Node *ptrHandTail;
	Node *ptrHandCurrent;
	Linked_List *playerOnesHand;
	Linked_List *playerTwosHand;
	Linked_List *playerThreesHand;
	Linked_List *playerFoursHand;

public:
	Hand();
	~Hand();
	void addCard(Node*,int);
	void displayHands();
	void sortPlayerHands();
};
#endif