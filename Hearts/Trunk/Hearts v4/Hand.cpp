#include "Hand.h"

Hand::Hand()
{
	playerOnesHand = new Linked_List();
	playerTwosHand = new Linked_List();
	playerThreesHand = new Linked_List();
	playerFoursHand = new Linked_List();
}
Hand::~Hand()
{

}
void Hand::addCard(Node* ptrGrabbedNode,int shuffleIncrementer)
{
	if (shuffleIncrementer == 1)
	{
		playerOnesHand->addNode(ptrGrabbedNode);
		//cout << "Player Ones Hand: " << ptrGrabbedNode->getNodeValue() << endl;
	}
	else if (shuffleIncrementer == 2)
	{
		playerTwosHand->addNode(ptrGrabbedNode);
		//cout << "Player Twos Hand: " << ptrGrabbedNode->getNodeValue() << endl;
	}
	else if (shuffleIncrementer == 3)
	{
		playerThreesHand->addNode(ptrGrabbedNode);
		//cout << "Player Threes Hand: " << ptrGrabbedNode->getNodeValue() << endl;
	}
	else if (shuffleIncrementer == 4)
	{
		playerFoursHand->addNode(ptrGrabbedNode);
		//cout << "Player Fours Hand: " << ptrGrabbedNode->getNodeValue() << endl;
	}
}
void Hand::displayHands()
{
	cout << "Player Ones Hand" << endl;
	playerOnesHand->displayHand();
	cout << "Player Twos Hand" << endl;
	playerTwosHand->displayHand();
	cout << "Player Threes Hand" << endl;
	playerThreesHand->displayHand();
	cout << "Player Fours Hand" << endl;
	playerFoursHand->displayHand();
}
void Hand::sortPlayerHands()
{
	playerOnesHand->sortHands();
	playerTwosHand->sortHands();
	playerThreesHand->sortHands();
	playerFoursHand->sortHands();
}