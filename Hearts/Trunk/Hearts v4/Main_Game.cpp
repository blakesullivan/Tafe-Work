#include "Deck.h"

Deck *gameDeck;
int gameSelected = 0;

int main()
{
	cout << "Please select a game to play" << endl;
	cout << "1. Hearts" << endl;
	cin >> gameSelected;
	gameDeck = new Deck(gameSelected);

	system("PAUSE");
	return 0;
}