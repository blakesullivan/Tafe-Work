//Blake Sullivan - Sort 3 Chars header file.
#include <string>
using namespace std;

class sortChars
{
private:
	//Variables
	char cInput[3];
	char cOrder[3];

public:
	//Constructor
	sortChars();

	//Functions
	void beginSort();
	char input();
	bool sort(int, int);
	void swap(int, int);
	void display(string);
	void display(char, char, char);
	void set(int, char, bool);
	char get(int, bool);
	bool replay();
	bool validInput(char);
	bool replayInput(char);
};