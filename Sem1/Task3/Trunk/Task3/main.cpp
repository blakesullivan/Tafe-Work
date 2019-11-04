//Blake Sullivan - Task 3 - Array Manipulation
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string>
using namespace std;

//Global Variable
int iArray[5];
//Prototyping
void SortElements();
void DisplayArray();
void DeleteElement();
void PopulateElement(bool);

int main()
{
	//Declaring local variables
	int iAnswer;
	string sAnswer;
	bool bExit = false;
	srand ( time(NULL) ); // initialize random seed
	PopulateElement(false); //Calling Populate function with the false attribute to make it not break out of the loop
	
	while (false==bExit) //Start while loop to stay in the main loop
	{
		SortElements(); //Calls the sortElements function, does this here to always have it sorted before it's displayed, and before the menu.
		DisplayArray(); //Calls he display function, done here to have it displayed before the menu.
		cout << "What do you want to do?\n 1. Delete\n 2. Populate\n 3. Quit\n"; //cout to show the main menu
		cin >> sAnswer; //cin to get the response, done as a string to make it catch errors
		const char *cAnswer = sAnswer.c_str(); //declaring a const char from the .c_str on sAnswer to make it able to check against the inbuilt char ordering to make sure it's a number and not a letter.
		if (*cAnswer < '0' || *cAnswer > '9') //if to make sure that cAnswer is a number
		{
			bExit=false; //Sets this to keep the loop going
			cout<<"Invalid input, please select an option using the number of the option. [1-3]\n\n";
		}
		else
		{
			cout<<endl;
			iAnswer = atoi(cAnswer);//convers the char cAnswer into an int iAnswer.
			switch (iAnswer) //switch case used because we know what the inputs should be
			{
			case 1:
				bExit=false; //Sets this to keep the loop going
				DeleteElement();  //calls the delete element function
				break; //break used to stop the switch doing everything after it.
			case 2:
				bExit=false; //Sets this to keep the loop going
				PopulateElement(true); //calls the populate function with the attribute of true, this is done to make it break out of the loop when it finds what is needs
				break; //break used to stop the switch doing everything after it.
			case 3:
				bExit=true; //Sets this to break out of the loop
				break; //break used to stop the switch doing everything after it.
			default:
				bExit=false; //Sets this to keep the loop going
				cout<<"Invalid input"<<endl;
			} //end switch case
		} //end number checking if
	} //end while loop
	return 0; //return 0 used to exit out of the program
}

//This function is used to sort any elements of 0 to the end of the array
void SortElements()
{
	bool bSort=true;
	while (true==bSort)
	{
		bSort = false;
		for (int i=0; i<4; i++)
		{
			int iTemp;
			if (0 == iArray[i] && 0 != iArray[i+1])
			{
				iTemp = iArray[i];
				iArray[i] = iArray[i+1];
				iArray[i+1] = iTemp;
				bSort = true;
			} //end if
		} //end For i
	} //end while bSort
}

//This function is used to display all the elements of the array in a standard output.
void DisplayArray()
{
	for (int i=0; i<5; i++)
	{
		cout<<"iArray["<<i<<"] = "<<iArray[i]<<endl;
	}
	cout<<endl;
}

//This function is used to delete the element, it asks which element they want to delete and if valid makes that element 0.
void DeleteElement()
{
	int iInput;
	string sInput;
	bool bExit = false;
	while (false == bExit)
	{
		cout<<"Which element would you like to delete? [0-4]"<<endl;
		cin>>sInput;
		const char *cInput = sInput.c_str(); //same error checking as in the menu for valid input
		if (*cInput < '0' || *cInput > '9')
		{
			bExit=false;
			cout<<"Invalid input, please input a Number between 0 and 4, inclusive."<<endl;
		}
		else
		{
			iInput = atoi(cInput);
			if (iInput >= 0 && iInput <= 4) //If to check that the number input is part of the array
			{
				bExit=true;
				if (0==iArray[iInput]) //If to check that the element selected has a number set to it
				{
					cout<<"Cannot delete an element that is already 0.\n\n";
				}
				else
				{
					iArray[iInput]=0;
				}// end if iArray
			}
			else
			{
				bExit=false;
				cout<<"Invalid number, please input a number between 0 and 4, inclusive."<<endl;
			}//end if iInput
		} //end If cInput
	} //end While bExit
}

//This function populates the array, the bBreak attribute is used to break out of the for loop or not.
void PopulateElement(bool bBreak)
{
	bool bSet=false;
	for (int i=0; i<5; i++)
	{
		if (0==iArray[i])
		{
			bSet=true; //sets variable to true because an array element has been set, so no need to display the message.
			iArray[i] = rand() %20 + 1; //Initialize the random number and set it to the array
			if (true==bBreak)
				break;
		}
	}
	if (false==bSet) //If used to see if any elements have been set, if not then it displays the message.
		cout<<"No available element to be populated.\n\n";
}