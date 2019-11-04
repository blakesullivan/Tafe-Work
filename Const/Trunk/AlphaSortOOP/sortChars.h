//Blake Sullivan - sortChars.h
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
	bool sort(const int, const int);
	void swap(const int, const int);
	void display(const string);
	void display(const char, const char, const char);
	void set(const int, const char, const bool);
	char get(const int, const bool) const;
	bool replay();
	bool validInput(const char);
	bool replayInput(const char);
};