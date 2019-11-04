//Blake Sullivan - Assessment Task 2 - Guessing Game
//Including all required libraries
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string>
//Adding namespacing
using namespace std;
//Start of main program
int main()
{
	//Initizing variables for outside loops
	int iPlay = 0;
	bool bReplay = false;
	bool bValidInput = false;
	char cAgain;
	//Start iPlay while loop
	while (2 != iPlay)
	{
		//Quiestion and Input section for main menu
		cout<<"Welcome to my Guessing Game \n 1. Play the game \n 2. Quit the game \n";
		cin>>iPlay;
		//Resulting IF of iPlay cin
		if(1 == iPlay)
		{
			//Start of DOWHILE loop for bReplay == True
			do
			{
				//Initilizing variables needed to guessing game.
				int iRandomNum = 0;
				int iGuesses = 0;
				int iGuessNum = 0;
				//String variable used to help check the input and make sure it's valid.
				string sGuessNumInput;
				/* initialize random seed: */
				srand ( time(NULL) );
				//Initialize random number to be guessed
				iRandomNum = rand() %91 + 1;
				//Start WHILE loop for guessing, always goes in because iGuessNum = 0 and iRandomNum never = 0
				while (iRandomNum != iGuessNum)
				{
					//Input and Output for the guessing game
					cout<<"Guess a number between 1 and 100"<<endl;
					cin>>sGuessNumInput;
					//Increments counter of guesses, even invalid inputs are counted
					iGuesses++;
					//Declaring a const char for help in the checking.
					const char *cGuessNum = sGuessNumInput.c_str();
					//IF to check if the first input is a number.
					if (*cGuessNum < '0' || *cGuessNum > '9')
					{
						//IF not a number then it's an invalid input.
						cout<<"Invalid Input "<<sGuessNumInput<<" is not a number."<<endl;
					}
					else
					{
						//IF a vaild input it then converts the string to an integer using the a to i function.
						iGuessNum = atoi(sGuessNumInput.c_str());
						//IF to compare the guess to the number
						if (iGuessNum == iRandomNum)
						{
							cout<<"Congratulations, you guessed the number right!"<<endl<<"It only took you "<<iGuesses<<" tries to guess the number."<<endl;
						}
						else
						{
							//if to check if the number is higher or lower.
							if(iGuessNum > iRandomNum)
							{
								cout<<"The number you guess was too high."<<endl;
							}
							else
							{
								cout<<"The number you guess was too low."<<endl;
							}
						}
					}
				}
				//End WHILE loop for guessing
				//Start DOWHILE for replay options
				do
				{
					cout<<"Play again? (y/n)"<<endl;
					cin>>cAgain;
					//IF checks for the input to make it work for lower and upper case inputs or invalid for neither
					if ('y' == cAgain || 'Y' == cAgain)
					{
						cout<<endl;
						bValidInput=true;
						bReplay=true;
					}
					else if ('n' == cAgain || 'N' == cAgain)
					{
						//Purposfully takes the program back to the main menu, as most games do when you exit.
						cout<<endl;
						bValidInput=true;
						bReplay=false;
						iPlay=0;
					}
					else
					{
						cout<<"Invalid input"<<endl;
						bValidInput=false;
					}
				} while (false == bValidInput);
				//End DOWHILE for replay options
			} while (true == bReplay);
			//End of DOWHILE loop for bReplay == True
		}
		else if (2 == iPlay)
		{
			//Second Result of the if to check the iPlay variable, this result ends the program
			return 0;
		}
		else
		{
			//else result for iPlay when the input isn't 1 or 2 it goes here.
			cout<<"Invalid, please select 1 or 2"<<endl;
		}
	}
	//End iPlay while loop
}