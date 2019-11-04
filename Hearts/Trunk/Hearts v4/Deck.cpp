//clubs = 100's
//diamonds = 200's
//spades = 300's
//hearts = 400's

//jacks = 11
//queen = 12
//king = 13
//ace = 14

#include "Deck.h"

Deck::Deck(int gameSelected)
{
	deckOfCards = new Linked_List();
	if (gameSelected == 1)
	{
		deckSize = 52;
		numberOfPlayers = 4;
		for (int i = 0;i < numberOfPlayers;i++)
		{
			player = new Hand();
		}
		createDeck();
	}
}
Deck::~Deck()
{

}
void Deck::createDeck()
{
	deckOfCards->createDeck(deckSize);
	shuffleDeck();
}
void Deck::shuffleDeck()
{
	Node* ptrSelectedNode;
	int pickedNode = 0;
	int numberOfNodes = 52;
	int shuffleIncrementer = 1;
	int sizeOfDeck = 52;

	for (int i = 0;i < sizeOfDeck;i++)
	{
		srand((unsigned)time(0));
		pickedNode = rand()% numberOfNodes;
		//deckOfCards->displayNodes(numberOfNodes);
		//cout << "Picked Node: " << pickedNode << endl;
		ptrSelectedNode = deckOfCards->searchList(pickedNode,numberOfNodes);
		player->addCard(ptrSelectedNode,shuffleIncrementer);
		numberOfNodes--;
		shuffleIncrementer++;
		if (shuffleIncrementer > 4)
		{
			shuffleIncrementer = 1;
		}
	}
	player->displayHands();
	player->sortPlayerHands();
	player->displayHands();
}