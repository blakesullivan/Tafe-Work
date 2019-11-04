//Random number generator
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
using namespace std;
int main()
{
	int iNum = 0, iTotal = 0;
	bool bExit = false;
	char cChar;
	do
	{
		iNum = 0; iTotal = 0;
		/* initialize random seed: */
		srand ( time(NULL) );
		for(int i=0; i<4; i++)
		{
			/* generate secret number: */
			iNum = rand() %16 + 1;
			iTotal += iNum;
			cout<<iNum<<endl;
		}
		cout << "Total: " << iTotal << endl;
		cout << "Again? (y/n)";
		cin >> cChar;
		if (cChar == 'y') {bExit = false;} else {bExit = true;}
	} while (bExit == false);
	return 0;
}