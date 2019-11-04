//Definition of class DeckOfCards that represents a deck of playing cards.

struct BitCard			//BitCard structure definition with bit fields
{
	unsigned face	:4;	//4 bits: 0-15
	unsigned suit	:2;	//2 bits: 0-3
	unsigned colour	:1;	//1 bit: 0-1
};

class DeckOfCards
{
private:
	BitCard deck[52];
public:
	DeckOfCards();
	void deal();
};