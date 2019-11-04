#include "DeckOfCards.h"	//DeckOfCards class definition

#include <iostream>
using std::cout;
using std::endl;
using std::cin;

#include <iomanip>
using std::setw;

DeckOfCards::DeckOfCards()
{
	for (int i = 0; i < 52; i++)
	{
		deck[i].face = i% 13;	//faces in order
		deck[i].suit = i / 13; //suits in order
		deck[i].colour = i / 26; //colours in order
	}
}

void DeckOfCards::deal()
{
	for (int k1 = 0, k2 = k1 + 26; k1 <= 25; k1++, k2++)
	{
		cout << "Card:" << setw(3) << deck[k1].face
			 << " Suit:" << setw(2) << deck[k1].suit
			 << " Colour:" << setw(2) << deck[k1].colour << "\t"
			 << "Card:" << setw(3) << deck[k2].face
			 << " Suit:" << setw(2) << deck[k2].suit
			 << " Colour:" << setw(2) << deck[k2].colour << endl;
	}
	int itemp = 0;
	cin >> itemp;
}