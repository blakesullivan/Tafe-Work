//Blake Sullivan - Time.cpp
#include "Time.h"

Time::Time()
{
	SetHour(0);
	SetMinute(0);
	SetSecond(0);
	Display();
}

void Time::Display()
{
	cout << "TIME VARIABLE" << endl;
	cout << "iHour: " << iHour << endl;
	cout << "iMinute: " << iMinute << endl;
	cout << "iSecond: " << iSecond << endl;
}

void Time::ManageInput()
{
	bool bMilitary = false, bIsPM=false;
	
	bMilitary = InputMethod("What time method are you using to input your hours?\n 1. Standard (1:30:00pm)\n 2. Military (13:30:00)\nPlease input number of option: ");
	
	if (false==bMilitary)
		bIsPM = InputMethod("What time of day?\n 1. AM\n 2. PM\nPlease input number of option: ");

	SetHour(InputHour(bMilitary, bIsPM));
	SetMinute(InputMinute());
	SetSecond(InputSecond());
}

void Time::ManageDisplay()
{
	bool bMilitary = false;
	int iHourDisplay = 0;
	string sTimeOfDay = "", sLZHour = "", sLZMinute="", sLZSecond="";
	
	bMilitary = InputMethod("How would you like to display the time?\n 1. Standard (1:30:00pm)\n 2. Military (13:30:00)\nPlease input number of option: ");

	if (bMilitary == false)
	{
		iHourDisplay = ConvertToTweleve(iHour);
		if (iHour > 12)
			{sTimeOfDay="PM";}
		else
			{sTimeOfDay="AM";}
	}
	else
	{
		if (iHour < 10)
			{sLZHour = "0";}
	}

	if (iMinute < 10)
	{sLZMinute="0";}

	if (iSecond < 10)
	{sLZSecond="0";}

	cout<<"The Time is: "<< sLZHour << iHourDisplay << ":" << sLZMinute << iMinute << ":" << sLZSecond << iSecond << sTimeOfDay << endl;
}

bool Time::InputMethod(string sDisplay)
{
	int iInput = 0;
	iInput = InputOption(sDisplay, 1, 2);
	if (1==iInput)
		{return false;}
	else
		{return true;}
}

int Time::InputHour(bool bMilitary, bool bIsPM)
{
	int iTempHour = 0, iMin = 0, iMax = 0;
	if (false==bMilitary)
		{iMin = 1; iMax = 12;}
	else
		{iMin = 0; iMax = 23;}
	iTempHour = InputOption("Please input the hour: ", iMin, iMax);
	if (false==bMilitary)
		iTempHour = ConvertToTwenty(iTempHour, bIsPM);
	return iTempHour;
}

int Time::InputMinute()
{
	int iTempMinute = 0;
	iTempMinute = InputOption("Please input the minute: ", 0, 59);
	return iTempMinute;
}

int Time::InputSecond()
{
	int iTempSecond = 0;
	iTempSecond = InputOption("Please input the second: ", 0, 59);
	return iTempSecond;
}

int Time::InputOption(string sOption, int iMin, int iMax)
{
	bool bExit = false;
	string sInput = " ";
	int iOutput = 0;
	do
	{
		cout << sOption;
		getline(cin, sInput);
		if (CheckOption(sInput, iMin, iMax)==true)
		{
			bExit=true;
			iOutput = atoi(sInput.c_str());
			return iOutput;
		}
		else
			{bExit=false;}
	}while (bExit == false);
}

bool Time::CheckOption(string sInput, int iMin, int iMax)
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
		if (iInput >= iMin && iInput <= iMax)
			{return true;}
		else
		{
			cout << "Invalid Input. Input was not a valid option." << endl;
			return false;
		}
	}
}

int Time::ConvertToTweleve(int iTemp)
{
	int iReturn = 0;
	iReturn = iTemp;
	if (iTemp==0)
		{iReturn = iTemp + 12;}
	else if (iTemp>12)
		{iReturn = iTemp - 12;}
	return iReturn;
}

int Time::ConvertToTwenty(int iTemp, bool bIsPM)
{
	int iReturn = 0;
	iReturn = iTemp;
	if (bIsPM == true)
	{
		if (iTemp!=12)	
			{iReturn = iTemp + 12;}
	}
	else
	{
		if (iTemp==12)
			{iReturn = iTemp - 12;}
	}
	return iReturn;
}

void Time::SetHour(int iSet)
{
	iHour=iSet;
}

void Time::SetMinute(int iSet)
{
	iMinute=iSet;
}

void Time::SetSecond(int iSet)
{
	iSecond=iSet;
}

int Time::GetHour()
{
	return iHour;
}

int Time::GetMinute()
{
	return iMinute;
}

int Time::GetSecond()
{
	return iSecond;
}