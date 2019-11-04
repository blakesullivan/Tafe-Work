//Blake Sullivan - TimeTable.cpp
#include "TimeTable.h"

TimeTable::TimeTable()
{
	sUnitX = "";
	sCollege = "";
	sHeadTeacher = "";
	sGroup = "";
	iStage = 0;
	iSemester = 0;
	iPhone = 0;
	Display();
	Manage();
}

void TimeTable::Display()
{
	cout << "TIMETABLE VARIABLES" << endl;
	cout << "sUnitX: " << sUnitX << endl;
	cout << "sCollege: " << sCollege << endl;
	cout << "sHeadTeacher: " << sHeadTeacher << endl;
	cout << "sGroup: " << sGroup << endl;
	cout << "iStage: " << iStage << endl;
	cout << "iSemester: " << iSemester << endl;
	cout << "iPhone: " << iPhone << endl;
}

void TimeTable::Manage()
{
	bool bUsingTime = false, bExit = false;
	int iOption = 0;
	do
	{
		iOption = InputOption("What do you wish to test?\n 1. Input\n 2. Output\n 3. Exit\nPlease enter the number of the option: ", 1, 3);
		if (1 == iOption)
		{
			bUsingTime = InputOption("What system do you want to use?\n 1. Date\n 2. Time\nPlease enter the number of the option: ", 1, 2) - 1;
			if (true == bUsingTime)
			{timeForTesting.ManageInput();}
			else
			{dateForTesting.ManageInput();}
		}
		else if (2 == iOption)
		{
			bUsingTime = InputOption("What system do you want to use?\n 1. Date\n 2. Time\nPlease enter the number of the option: ", 1, 2) - 1;
			if (true == bUsingTime)
			{timeForTesting.ManageDisplay();}
			else
			{dateForTesting.ManageDisplay();}
		}
		else
			{bExit = true;}

	} while (bExit == false);
}

int TimeTable::InputOption(string sDisplay, int iMin, int iMax)
{
	int iInput = 0;
	bool bExit = false;
	string sInput = "";
	do
	{
		cout << sDisplay;
		getline(cin, sInput);
		if (true==CheckOption(sInput, iMin, iMax))
		{
			iInput = atoi(sInput.c_str());
			bExit = true;
		}
		else
			{bExit = false;}

	}while (bExit == false);

	return iInput;
}

bool TimeTable::CheckOption(string sInput, int iMin, int iMax)
{
	const char* cInput = sInput.c_str();
	if (*cInput < '0' || *cInput > '9')
	{
		cout << "Invalid Input. Input was not a number." << endl;
		return false;
	}
	else
	{
		int iInput = 0;
		iInput = atoi(cInput);
		if (iMin == -1 && iMax == -1)
			{return true;}
		else
		{
			if (iInput >= iMin && iInput <= iMax)
				{return true;}
			else
			{
				cout << "Invalid Input. Input was not a valid option." << endl;
				return false;
			}
		}
	}
}