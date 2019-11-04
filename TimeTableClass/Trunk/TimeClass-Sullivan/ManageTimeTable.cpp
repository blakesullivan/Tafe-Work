//Blake Sullivan - Manage Time Table
#include "ManageTimeTable.h"
#include <iostream>
using namespace std;

ManageTimeTable::ManageTimeTable()
{
	Manage();
}

void ManageTimeTable::Manage()
{
	TimeTableDate objD;
	TimeTable objTimeTable[31];
	cout<<"Welcome to Blake Sullivans' Calender Time Table.\n\n";
	ManageDate(objD);
	ManageOptions(objTimeTable, objD);
	//ManageInput(objTimeTable, objD);
	//ManageDisplay(objTimeTable, objD);
	//system("PAUSE");
}

void ManageTimeTable::ManageDate(TimeTableDate & objDate)
{
	bool bYExit=false, bMExit=false;
	while (false==bYExit)
	{
		string sInput = InputYear();
		if (true==objDate.CheckYear(sInput))
		{
			int iInput = atoi(sInput.c_str());
			objDate.SetYear(iInput);
			bYExit=true;
			while (false==bMExit)
			{
				sInput = InputMonth(objDate);
				if (true==objDate.CheckMonth(sInput))
				{
					iInput = atoi(sInput.c_str());
					objDate.SetMonth(iInput);
					bMExit=true;
				}
				else
				{bMExit=false;}
			}
		}
		else
		{bYExit=false;}
	}
}

void ManageTimeTable::ManageOptions(TimeTable objTT[], TimeTableDate & objDate)
{
	bool bExit=false;
	int iOption=0;
	int iDay=0;
	while (false==bExit)
	{
		DisplayCalender(objDate);
		iDay = InputDay("Please input which day you want to look at, or Enter 99 to exit.\n", objDate.GetMonthDays(objDate.GetYear(), objDate.GetIMonth()));
		if (iDay != 99)
		{
			iOption=0;
			while (5!=iOption)
			{
				iOption = InputOption("What would you like to do with this day?\n 1. Add Lesson\n 2. Edit Lesson\n 3. Delete Lesson\n 4. View Lesson(s)\n 5. Choose Another Day\n", 5);
				if (5!=iOption)
				{
					switch (iOption)
					{
					case 1:
						ManageInput(objTT, objDate, iDay);
					break;
					case 2:
						ManageEdit(objTT, objDate, iDay);
					break;
					case 3:
						ManageDelete(objTT, objDate, iDay);
					break;
					case 4:
						ManageDisplay(objTT, objDate, iDay);
					break;
					default:
						cout<<"Invalid option."<<endl;
					}
				}
			}
		}
		else
		{bExit=true;}
	}
}

void ManageTimeTable::ManageInput(TimeTable objTT[], TimeTableDate & objDTT, int iDay)
{
	int iSet=0;
	bool bExit=false;
	while (false==bExit)
	{
		if (0==objTT[iDay].GetLessonHS(iSet))
		{
			bExit=true;
		}
		else
		{
			iSet++;
			bExit=false;
		}
	}
	//cout<<"iSet="<<iSet<<endl;
	objTT[iDay].LessonInput(iSet);
}

void ManageTimeTable::ManageDisplay(TimeTable objTT[], TimeTableDate & objDTT, int iDay)
{
	objTT[iDay].DisplayLesson();
}

void ManageTimeTable::ManageEdit(TimeTable objTT[], TimeTableDate & objDTT, int iDay)
{
	int iSet=0;
	bool bExit=false;
	while (false==bExit)
	{
		if (0==objTT[iDay].GetLessonHS(iSet))
		{
			bExit=true;
		}
		else
		{
			iSet++;
			bExit=false;
		}
	}
	if (iSet > 0)
	{
		int iOption;
		int i;
		do
		{
			cout<<"Which lesson would you like to edit?"<<endl;
			for (i=0; i<iSet; i++)
			{
				cout<<i+1<<". Lesson "<<i+1<<": "<<objTT[iDay].GetLessonName(i)<<endl;
			}
			cout<<i+1<<". Finish Editing\n";
			iOption = InputOption("",i+1) - 1;
			if (iOption != i)
			{objTT[iDay].LessonInput(iOption);}
		} while (iOption != i);
	}
}

void ManageTimeTable::ManageDelete(TimeTable objTT[], TimeTableDate & objDTT, int iDay)
{
	int iSet=0;
	bool bExit=false;
	while (false==bExit)
	{
		if (0==objTT[iDay].GetLessonHS(iSet))
		{
			bExit=true;
		}
		else
		{
			iSet++;
			bExit=false;
		}
	}
	if (iSet > 0)
	{
		int iOption;
		int i;

		cout<<"Which lesson would you like to edit?"<<endl;
		for (i=0; i<iSet; i++)
		{
			cout<<i+1<<". Lesson "<<i+1<<": "<<objTT[iDay].GetLessonName(i)<<endl;
		}
		cout<<i+1<<". Finish Deleting\n";
		iOption = InputOption("",i+1) - 1;

		if (iOption != i)
		{objTT[iDay].LessonDelete(iOption);}
	}
}

void ManageTimeTable::DisplayCalender(TimeTableDate& objectDate)
{
	cout<<"			"<<objectDate.GetMonthName(objectDate.GetIMonth())<<endl;
	cout<<objectDate.DisplayHeader();
	cout<<objectDate.DisplayDate(objectDate.GetYear(), objectDate.GetIMonth());
}

string ManageTimeTable::InputYear()
{
	string sInput;
	cout<<"What year are you setting? (yyyy)"<<endl;
	getline(cin, sInput);
	return sInput;
}

string ManageTimeTable::InputMonth(TimeTableDate & objectDate)
{
	string sInput;
	cout<<"What month are you setting?"<<endl;
	for (int i=1;i<13;i++)
	{
		cout<<i<<". "<<objectDate.GetMonthName(i)<<endl;
	}
	getline(cin, sInput);
	return sInput;
}

int ManageTimeTable::InputDay(string sOutput, int iMaxDay)
{
	string sInput;
	int iInput;
	do
	{
		cout<<sOutput;
		getline(cin, sInput);
	} while (false == CheckInputDay(sInput, iInput, iMaxDay));
	return iInput;
}

int ManageTimeTable::InputOption(string sOutput, int iMaxNum)
{
	string sInput;
	int iInput;
	do
	{
		cout<<sOutput;
		getline(cin, sInput);
	} while (false == CheckInput(sInput, iInput, iMaxNum));
	return iInput;
}

bool ManageTimeTable::CheckInputDay(string sTemp, int& iTemp, int iMaxDay)
{
	const char* cTemp = sTemp.c_str();
	if (*cTemp < '0' || *cTemp > '9')
	{
		cout << "Invalid Input. Input not a number, please try again."<<endl;
		return false;
	}
	else
	{
		iTemp = atoi(cTemp);
		if (99==iTemp)
		{return true;}
		else if (iTemp >= 1 && iTemp <= iMaxDay)
		{return true;}
		else
		{
			cout << "Invalid Input. Input not within date range, please try again." << endl;
			return false;
		}
	}
}

bool ManageTimeTable::CheckInput(string sTemp, int& iTemp, int iMaxNum)
{
	const char* cTemp = sTemp.c_str();
	if (*cTemp < '0' || *cTemp > '9')
	{
		cout << "Invalid Input. Input not a number, please try again."<<endl;
		return false;
	}
	else
	{
		iTemp = atoi(cTemp);
		if (iTemp >= 1 && iTemp <= iMaxNum)
		{return true;}
		else
		{
			cout << "Invalid Input. Input not within menu range, please try again." << endl;
			return false;
		}
	}
}