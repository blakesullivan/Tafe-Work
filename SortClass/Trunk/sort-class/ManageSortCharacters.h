//Blake Sullivan - Manage Sort Characters header
#include <string>
using namespace std;

class ManageSortCharacters
{
private:

public:
	ManageSortCharacters();
	
	void Manage();
	bool Replay();
	char Input(int);
	int InputOption(string);
	void Display(string);
	void Display(string, char, char, char);
	void DisplayInFormat(int*);
	void DisplayInFormat(char*);
	void EasterEgg();
};