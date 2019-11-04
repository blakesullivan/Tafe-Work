//Blake Sullivan - Date.cpp
#include "Date.h"

Date::Date()
{
	SetDay(0);
	SetMonth(0);
	SetYear(0);
	SetLeapYear(false);

	ManageInput();
	Display();
	ManageDisplay();
}

void Date::Display()
{
	cout << "DATE VARIABLES" << endl;
	cout << "iDay: " << GetDay() << endl;
	cout << "iMonth: " << GetMonth() << endl;
	cout << "iYear: " << GetYear() << endl;
	cout << "bLeapYear: " << GetLeapYear() << endl;
}

void Date::ManageInput()
{
	int iInput = 0, iMax = 0;
	
	iInput = InputOption("What year are you entering (yyyy, 2011): ", -1, -1);
	SetYear(iInput);
	
	SetLeapYear(CheckLeapYear(iYear));
	
	iInput = InputOption("What month are you entering (mm, 12): ", 1, 12);
	SetMonth(iInput);

	iMax = CheckDayInMonth(iMonth, bLeapYear);
	iInput = InputOption("What day are you entering (dd, 08): ", 1, iMax);
	SetDay(iInput);
}

int Date::InputOption(string sDisplay, int iMin, int iMax)
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

bool Date::CheckOption(string sInput, int iMin, int iMax)
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

bool Date::CheckLeapYear(int year)
{
	bool bIsLeap = false;
	if (year%400 == 0)
		{bIsLeap = true;}
	else if (year%100 == 0)
		{bIsLeap = false;}
	else if (year%4 == 0)
		{bIsLeap = true;}
	else
		{bIsLeap = false;}
	
	return bIsLeap;
}

int Date::CheckDayInMonth(int month, bool leapYear)
{
	int iNumDays = 0;
	if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
		{iNumDays = 31;}
	else if (month == 4 || month == 6 || month == 9 || month == 11)
		{iNumDays = 30;}
	else
	{
		if (leapYear == true)
			{iNumDays = 29;}
		else
			{iNumDays = 28;}
	}

	return iNumDays;
}

void Date::ManageDisplay()
{
	int iDisplayOption = 0;
	iDisplayOption = InputOption("How would you like to display the date?\n 1. dd/mm/yyyy\n 2. yyyy/mm/dd\n 3. mm/dd/yyyy\n 4. dd/mm/yy\nPlease input the number of the option: ", 1, 4);
	switch (iDisplayOption)
	{
	case 1:
		DisplayDate("dd", true);
		DisplayDate("mm", true);
		DisplayDate("yyyy");
	break;
	case 2:
		DisplayDate("yyyy", true);
		DisplayDate("mm", true);
		DisplayDate("dd");
	break;
	case 3:
		DisplayDate("mm", true);
		DisplayDate("dd", true);
		DisplayDate("yyyy");
	break;
	case 4:
		DisplayDate("dd", true);
		DisplayDate("mm", true);
		DisplayDate("yy");
	break;
	default:
		DisplayDate("dd", true);
		DisplayDate("mm", true);
		DisplayDate("yyyy");
	}
}

void Date::DisplayDate(string sFormat, bool bShowSymbol)
{
	if (sFormat[0] == 'd')
		{cout << GetDay();}
	else if (sFormat[0] == 'm')
	{
		if (GetMonth() < 10)
			{cout << "0";}
		cout << GetMonth();
	}
	else if (sFormat[0] == 'y')
	{
		if (sFormat == "yyyy")
		{cout << GetYear();}
		else
		{
			int iShortYear = GetYear();
			do{iShortYear -= 100;} while (iShortYear > 100);
			cout << iShortYear;
		}
		
	}
	if (bShowSymbol == true) {cout << "/";} else {cout << endl;}
}

void Date::SetDay(int iTemp)
{
	iDay = iTemp;
}
void Date::SetMonth(int iTemp)
{
	iMonth = iTemp;
}
void Date::SetYear(int iTemp)
{
	iYear = iTemp;
}
void Date::SetLeapYear(bool bTemp)
{
	bLeapYear = bTemp;
}

int Date::GetDay()
{
	return iDay;
}
int Date::GetMonth()
{
	return iMonth;
}
int Date::GetYear()
{
	return iYear;
}
bool Date::GetLeapYear()
{
	return bLeapYear;
}