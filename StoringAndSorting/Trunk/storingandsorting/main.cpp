//Array example - Input, storing, sorting.
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
using namespace std;

int main ()
{
	int iInput[10];
	int iTemp;
	bool bSorted = false;
	/* initialize random seed: */
	srand ( time(NULL) );
	for (int i=0;i<10;i++)
	{
		/*cout<<"Please input a number between 1-100."<<endl<<"Number "<<(i+1)<<": ";
		cin>>iInput[i];*/
		//Initialize random number to be guessed
		iInput[i] = rand() %100 + 1;
		if(9==i)
		{
			cout<<iInput[i]<<endl;
		}
		else
		{
			cout<<iInput[i]<<", ";
		}
	}
	while (bSorted == false)
	{
		bSorted = true;
		for (int i = 0; i<9; i++)
		{
			cout << "iInput[" << i << "] = " << iInput[i] << " V iInput[" << (i+1) << "] = " << iInput[i+1] << endl;
			if (iInput[i] > iInput[i+1])
			{
				iTemp = iInput[i];
				iInput[i] = iInput[i+1];
				iInput[i+1] = iTemp;
				//i=-1;
				bSorted = false;
			}
			cout << "iInput[" << i << "] = " << iInput[i] << " <-> iInput[" << (i+1) << "] = " << iInput[i+1] << endl;
			for (int i=0;i<10;i++)
			{
				if(9==i)
				{
					cout<<iInput[i]<<endl<<endl;
				}
				else
				{
					cout<<iInput[i]<<", ";
				}
			}
		}
	}
	cout<<"Sorted: ";
	for (int i=0;i<10;i++)
	{
		if(9==i)
		{
			cout<<iInput[i]<<endl;
		}
		else
		{
			cout<<iInput[i]<<", ";
		}
	}
	/*for (int i=0; i<10; i++)
	{
		cout<<"Number "<<i<<" = "<< iInput[i]<<endl;
	}*/
	system("PAUSE");
	return 0;
}