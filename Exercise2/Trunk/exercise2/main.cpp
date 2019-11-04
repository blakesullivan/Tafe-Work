//Blake Sullivan Exercise 2 stuff
#include <iostream>
using namespace std;

void ShowAscii()
{
	int iTemp;
	cin>>iTemp;
	char cChar = iTemp;
	cout<<cChar<<endl;
}

int main()
{
	cout<<"Put in a number to be returned as the ascii character: ";
	ShowAscii();
	system("PAUSE");
	return 0;
}