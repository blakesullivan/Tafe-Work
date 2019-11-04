//Blake Sullivan - Manage Sort Characters
#include "ManageSortCharacters.h"
#include "SortCharacters.h"
#include <iostream>
#include <windows.h>
using namespace std;

ManageSortCharacters::ManageSortCharacters()
{
	do
	{
		Manage();
	} while (true==Replay());
}

void ManageSortCharacters::Manage()
{
	if (1==InputOption("What would you like to sort?\n 1. Randomly Generated Lists\n 2. User Entered 3 Characters\n"))
	{
		SortCharacters objSortCharacters;
		if (1==InputOption("How do you want to use this program?\n 1. 1000 Numbers\n 2. 20 Characters\n"))
		{
			objSortCharacters.GenerateRandomNumbers();
			Display("Randomly Generated Numbers:\n");
			DisplayInFormat(objSortCharacters.GetIntArrayPoint(0));
			objSortCharacters.SortIntArray();
			Display("Sorted Numbers:\n");
			DisplayInFormat(objSortCharacters.GetIntArrayPoint(0));
		}
		else
		{
			objSortCharacters.GenerateRandomCharacters(InputOption("What case do you want the characters?\n 1. UPPER CASE\n 2. lower case\n"));
			Display("Randomly Generated Characters:\n");
			DisplayInFormat(objSortCharacters.GetCharArrayPoint(0));
			objSortCharacters.SortCharArray();
			Display("Sorted Characters:\n");
			DisplayInFormat(objSortCharacters.GetCharArrayPoint(0));
		}
	}
	else
	{
		char c1=Input(1), c2=Input(2), c3=Input(3);
		SortCharacters objSortCharacters(c1, c2, c3);
		Display("Character input order: ", objSortCharacters.GetChar1(), objSortCharacters.GetChar2(), objSortCharacters.GetChar3());
		Display("Sorted character order: ", objSortCharacters.GetCharS1(), objSortCharacters.GetCharS2(), objSortCharacters.GetCharS3());
	}
}

bool ManageSortCharacters::Replay()
{
	if (1==InputOption("Do you want to try again?\n 1. Yes\n 2. No\n"))
	{
		return true;
	}
	else
	{
		return false;
	}
}

char ManageSortCharacters::Input(int iTemp)
{
	char const* cTemp;
	string sInput;
	cout<<"Please input a characters. This is Character "<<iTemp<<": ";
	getline (cin, sInput);
	cTemp = sInput.c_str();
	return *cTemp;
}

int ManageSortCharacters::InputOption(string sString)
{
	int iTemp;
	bool bExit=false;
	string sInput;
	while (false==bExit)
	{
		cout<<sString;
		getline(cin, sInput);
		const char* cInput = sInput.c_str();
		if (*cInput < '0' || *cInput > '9')
		{
			bExit = false;
			Display("Invalid input, please try again.\n");
		}
		else
		{
			iTemp = atoi(sInput.c_str());
			if (1==iTemp || 2==iTemp)
			{
				bExit=true;
				return iTemp;
			}
			else if (1337==iTemp)
			{
				bExit = false;
				EasterEgg();
			}
			else
			{
				bExit = false;
				Display("Invalid input, please try again.\n");
			}
		}
	}
}

void ManageSortCharacters::Display(string sString)
{
	cout<<sString;
}

void ManageSortCharacters::Display(string sString, char c1,char c2, char c3)
{
	cout<<sString<<c1<<", "<<c2<<", "<<c3<<endl;
}

void ManageSortCharacters::DisplayInFormat(int * iPArray)
{
	int iNum=10;
	for (int i = 0; i <1000 ; i++)
	{
		if ((i+1)%iNum==0)
		{
			cout<<i+1<<"="<<*(iPArray+i)<<endl;
		}
		else
		{
			cout <<i+1<<"="<<*(iPArray+i)<<"	";
		}
	}
	system("PAUSE");
}

void ManageSortCharacters::DisplayInFormat(char* cPArray)
{
	int iNum=10;
	for (int i = 0; i <20 ; i++)
	{
		if ((i+1)%iNum==0)
		{
			cout<<i+1<<"="<<*(cPArray+i)<<endl;
		}
		else
		{
			cout <<i+1<<"="<<*(cPArray+i)<<"	";
		}
	}
	system("PAUSE");
}

void ManageSortCharacters::EasterEgg()
{
		cout << "         _          " << endl;
		cout << "        / \\         " << endl;
		cout << "        \\_/         " << endl;
		cout << "      _  ||  _      " << endl;
		cout << "     /o\\_||_/o\\     " << endl;
		cout << "    |          |    " << endl;
		cout << "    |  -    -  |    " << endl;
		cout << "  __|   \\  /   |__  " << endl;
		cout << "  \\  \\   ()   /  /  " << endl;
		cout << "   | /        \\ |   " << endl;
		cout << "   |/          \\|   " << endl;
		cout << "    | |      | |    " << endl;
		cout << "    \\_|  __  |_/    " << endl;
		cout << "     |___||___|     " << endl;
        //
		Beep(587.33,166);
		Beep(587.33,166);
		Beep(587.33,166);
		Beep(587.33,500);
		Beep(466.16,500);
		Beep(523.25,500);
		//
		Beep(587.33,166);
		Beep(000.00,166);
		Beep(523.25,166);
		Beep(587.33,1000);
		//
}