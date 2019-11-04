//Gender Program
//Headers
#include <iostream>
using namespace std;
//Main program
int main()
{
	//Declaring Variables
	char cGender;
	bool bLoop = 0;
	bool bExit;
	//Do While loop start
	do
	{
		cout << "What is your gender? (M/m,F/f)" << endl;
		cin >> cGender;
		if (cGender != 'M' && cGender != 'm')
		{
			if (cGender != 'F' && cGender != 'f')
			{
				cout << "The input is invalid";
				bLoop = false;
			}
			else
			{
				cout << "You are female." << endl;
				bLoop = true;
			}
		}
		else
		{
			cout << "You are male." << endl;
			bLoop = true;
		}
		/*
		if (cGender == 'M'|| cGender == 'm')
		{
			cout << "You are a male" << endl;
			bLoop = true;
		}
		else if (cGender == 'F' || cGender == 'f')
		{
			cout << "You are a female" << endl;
			bLoop = true;
		}
		else
		{
			cout << "The input is invalid" << endl;
			bLoop = false;
		}
		*/
	}
	while (bLoop == 0);
	//Do While loop end
	int x=0;
  for (int i=0;i<10;i++)
  {
	  if (i<5)
		  x+=10;
	  if (i=10)
		  x=7;
	  if (i==1)
		  x-=5;
	  if (i>9)
		  x=(x+1)*2 -5;
	  if (i==10)
		  x=42;

  }
  cout<<x<<endl;

	cout << "Press any key to exit";
	cin >> bExit;
	return 0;
	
}