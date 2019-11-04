//Blake Sullivan sortChars.pp
#include <iostream>
#include <string>
#include "sortChars.h"
using namespace std;

sortChars::sortChars()
{
	//Constructor that runs the beingSort function to start the program
	cInput[0] = ' ';
	cInput[1] = ' ';
	cInput[2] = ' ';

	cOrder[0] = ' ';
	cOrder[1] = ' ';
	cOrder[2] = ' ';
	beginSort();
}

void sortChars::beginSort()
{
	//This function is the main function that actually runs the program
	display("Welcome to the Sorting Program.\n\n");
	do //Start Do While replay()=true
	{
		for (int i=0; i<=2; i++) //Start for loop to input characters
		{
			display("Please input a character: ");
			set(i, input(),true);
		}//End for loop to input characters
		for (int i=0; i<2; i++) //Start for loop to loop through sorting
		{
			if (sort(i, i+1)==true) //if statement that calls the sort function and returns a boolean.
			{
				i=-1;
			}
		}
		display("\nOriginal character order = ");
		display(get(0, true), get(1, true),get(2, true));
		display("Characters in order = ");
		display(get(0, false),get(1, false),get(2, false));
	}while (replay()==true); //End Do While replay()=true
}

char sortChars::input()
{
	//This function gets the input from the user
	char cTemp;
	cin>>cTemp;
	return cTemp;
}

bool sortChars::sort(int iChar1, int iChar2)
{
	//This function sorts the two characters it is sent and returns true if it sorted them, or false if it didn't.
	if (get(iChar1, false) > get(iChar2, false))
	{
		swap(iChar1, iChar2);
		return true;
	}
	else
	{
		return false;
	}
}

void sortChars::swap(int iChar1, int iChar2)
{
	//This function swaps the two passed characters
		char cTemp = get(iChar1, false);
		set(iChar1, get(iChar2, false), false);
		set(iChar2, cTemp, false);
}

void sortChars::display(string displayMessage)
{
	//This function displays the string it is passed.
	cout<<displayMessage;
}

void sortChars::display(char cChar1, char cChar2, char cChar3)
{
	//This function displays the 3 characters in order and outputs it to a set look
	cout<<cChar1<<", "<<cChar2<<", "<<cChar3<<endl<<endl;
}

void sortChars::set(int iNum, char cInputChar, bool bInput)
{
	//This function sets the array, the array number is sent through as well as the character it is to be set to
	cOrder[iNum] = cInputChar;
	if (bInput == true)
	{
		cInput[iNum] = cInputChar;
	}
}

char sortChars::get(int iNum, bool bInput)
{
	//This function gets the character that is located in the location it is passed
	char cChar;
	if (bInput == true)
	{
		cChar = cInput[iNum];
	}
	else
	{
		cChar = cOrder[iNum];
	}
	return cChar;
}

bool sortChars::replay()
{
	/*This function loops until it gets a correct input. Asks again if invalid input.
	It returns a bool depending on the answer, this is then used to see if the game is replayed or not.*/
	bool bExit=false;
	while(bExit==false)
	{
		display("Would you like to play again? (y/n)\n");
		char cTemp = input();
		if (true==validInput(cTemp))
		{
			if (true==replayInput(cTemp))
			{
				bExit=true;
				return true;
			}
			else
			{
				bExit=true;
				return false;
			}
		}
		else
		{
			bExit=false;
		}
	}
}

bool sortChars::validInput(char cTemp)
{
	if ('y'==cTemp || 'Y'==cTemp || 'n'==cTemp || 'N'==cTemp)
	{
		return true;
	}
	else
	{
		display("Invalid input please try again.\n");
		return false;
	}
}

bool sortChars::replayInput(char cTemp)
{
	if ('y'==cTemp || 'Y'==cTemp)
	{
		return true;
	}
	else if ('n'==cTemp || 'N'==cTemp)
	{
		return false;
	}
}