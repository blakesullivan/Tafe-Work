//Blake Sullivan - Time Class .cpp
#include <iostream>
#include <string>
#include "Time.h"
using namespace std;

Time::Time()
{
	SetHours(0);
	SetMinutes(0);
	SetSeconds(0);
	SetTimeOfDay(" "); 
	
	SetHoursD(0);
	SetLZHours(" ");
	SetMinutesD(0);
	SetLZMinutes(" ");
	SetSecondsD(0);
	SetLZSeconds(" ");
	SetTimeOfDayD(" ");
	
	Manage();
}

void Time::Manage()
{
	int iOption = InputOption();
	InputHours(iOption);
	InputMinutes();
	InputSeconds();
	if (1==iOption)
	{
		InputTimeOfDay();
	}
	int iDisplayOption = InputDisplayOption();
	if (1==iDisplayOption)
	{
		ConvertToTweleve();
	}
	else if (2==iDisplayOption)
	{
		ConvertToTwenty();
	}
	Display();
}

int Time::InputOption()
{
	string sInput;
	bool bExit = false;
	while (false==bExit)
	{
		cout<<"Please choose a format to input the time in:\n 1. 12 Hour\n 2. 24 Hour\n";
		getline(cin, sInput);
		if (true==CheckInputOption(sInput))
		{
			bExit = true;
			return atoi(sInput.c_str());
		}
		else
		{
			bExit = false;
			cout<<"Invalid input, please try again"<<endl;
		}

	}
}

void Time::InputHours(int iOption)
{
	string sInput;
	bool bExit=false;
	while (false==bExit)
	{
		cout<<"Please input the Hour: ";
		getline(cin, sInput);
		if (true==CheckHours(iOption, sInput))
		{
			bExit=true;
			SetHours(atoi(sInput.c_str()));
		}
		else
		{
			bExit=false;
			cout<<"Invalid input, please try again."<<endl;
		}
	}
}

void Time::InputMinutes()
{
	string sInput;
	bool bExit=false;
	while (false==bExit)
	{
		cout<<"Please input the Minutes: ";
		getline(cin, sInput);
		if (true==CheckMinutes(sInput))
		{
			bExit=true;
			SetMinutes(atoi(sInput.c_str()));
		}
		else
		{
			bExit=false;
			cout<<"Invalid input, please try again."<<endl;
		}
	}
}

void Time::InputSeconds()
{
	string sInput;
	bool bExit=false;
	while (false==bExit)
	{
		cout<<"Please input the Seconds: ";
		getline(cin, sInput);
		if (true==CheckSeconds(sInput))
		{
			bExit=true;
			SetSeconds(atoi(sInput.c_str()));
		}
		else
		{
			bExit=false;
			cout<<"Invalid input, please try again."<<endl;
		}
	}
}

void Time::InputTimeOfDay()
{
	string sInput;
	bool bExit=false;
	while (false==bExit)
	{
		cout<<"Please input the Time Of Day: ";
		getline(cin, sInput);
		if (true==CheckTimeOfDay(sInput))
		{
			bExit=true;
			SetTimeOfDay(sInput);
		}
		else
		{
			bExit=false;
			cout<<"Invalid input, please try again."<<endl;
		}
	}
}

int Time::InputDisplayOption()
{
	string sInput;
	bool bExit = false;
	while (false==bExit)
	{
		cout<<"Please choose a format to display the time in:\n 1. 12 Hour\n 2. 24 Hour\n";
		getline(cin, sInput);
		if (true==CheckInputOption(sInput))
		{
			bExit = true;
			return atoi(sInput.c_str());
		}
		else
		{
			bExit = false;
			cout<<"Invalid Input, please try again."<<endl;
		}
	}
}

bool Time::CheckHours(int iOption, string sInput)
{
	const char *cInput = sInput.c_str();
	if (*cInput < '0' || *cInput > '9')
	{return false;}
	else
	{
		int iInput = atoi(sInput.c_str());
		switch (iOption)
		{
		case 1:
			if (iInput < 13 && iInput > 0)
			{return true;}
			else
			{return false;}
		case 2:
			if (iInput < 24 && iInput >= 0)
			{return true;}
			else
			{return false;}
		}
	}
}

bool Time::CheckMinutes(string sInput)
{
	const char *cInput = sInput.c_str();
	if (*cInput < '0' || *cInput > '9')
	{return false;}
	else
	{
		int iInput = atoi(sInput.c_str());
		if (iInput < 60 && iInput > 0)
		{return true;}
		else
		{return false;}
	}
}
bool Time::CheckSeconds(string sInput)
{
	const char *cInput = sInput.c_str();
	if (*cInput < '0' || *cInput > '9')
	{return false;}
	else
	{
		int iInput = atoi(sInput.c_str());
		if (iInput < 60 && iInput > 0)
		{return true;}
		else
		{return false;}
	}
}
bool Time::CheckTimeOfDay(string sInput)
{

	if (sInput=="am" || sInput=="AM" || sInput=="Am" || sInput=="aM")
	{return true;}
	else if (sInput=="pm" || sInput=="PM" || sInput=="Pm" || sInput=="pM")
	{return true;}
	else
	{return false;}
}
bool Time::CheckInputOption(string sInput)
{
	const char *cInput = sInput.c_str();
	if (*cInput < '0' || *cInput > '9')
	{return false;}
	else
	{
		int iInput = atoi(sInput.c_str());
		if (iInput > 2 || iInput < 1)
		{return false;}
		else
		{return true;}
	}
}

void Time::Display()
{
	//cout<<"The time input was: "<<GetHours()<<":"<<GetMinutes()<<":"<<GetSeconds()<<GetTimeOfDay()<<endl;
	cout<<"The time converted is: "<<GetLZHours()<<GetHoursD()<<":"<<GetLZMinutes()<<GetMinutesD()<<":"<<GetLZSeconds()<<GetSecondsD()<<GetTimeOfDayD()<<endl;
}

void Time::ConvertToTweleve()
{
	if (" "!=sTimeOfDay) //This means it is already in 12 hour format
	{
		SetTimeOfDayD(sTimeOfDay);
		SetHoursD(iHours);
	}
	else
	{
		SetTimeOfDayD("am");
		if (iHours>11) //when military is in pm
		{
			SetTimeOfDayD("pm");
			if (iHours>12) //military over 12 needs to be reduced to be first numbers again
			{SetHoursD(iHours-12);}
			else // 12 hours is the same in military and standard
			{SetHoursD(iHours);}
		}
		else if (iHours < 1) //For when 24 hour time is at 00 hours
		{SetHoursD(iHours+12);}
		else //when the hours is between 1 and 11
		{SetHoursD(iHours);}
	}
	
	SetMinutesD(iMinutes);
	if (iMinutes < 10)
	{SetLZMinutes("0");}
	else
	{SetLZMinutes("");}
	SetSecondsD(iSeconds);
	if (iSeconds < 10)
	{SetLZSeconds("0");}
	else
	{SetLZSeconds("");}
}

void Time::ConvertToTwenty()
{
	if (sTimeOfDay=="pm" && iHours < 12)
	{SetHoursD(iHours+12);}
	else if (sTimeOfDay=="am" && 12==iHours)
	{SetHoursD(iHours-12);}
	else
	{SetHoursD(iHours);}

	if (iHours < 10)
	{SetLZHours("0");}
	else
	{SetLZHours("");}

	SetMinutesD(iMinutes);
	if (iMinutes < 10)
	{SetLZMinutes("0");}
	else
	{SetLZMinutes("");}

	SetSecondsD(iSeconds);
	if (iSeconds < 10)
	{SetLZSeconds("0");}
	else
	{SetLZSeconds("");}
	SetTimeOfDayD(" Hours");
}

int Time::GetHours()
{
	return iHours;
}
int Time::GetMinutes()
{
	return iMinutes;
}
int Time::GetSeconds()
{
	return iSeconds;
}
string Time::GetTimeOfDay()
{
	return sTimeOfDay;
}

void Time::SetHours(int iTemp)
{
	iHours = iTemp;
}
void Time::SetMinutes(int iTemp)
{
	iMinutes = iTemp;
}
void Time::SetSeconds(int iTemp)
{
	iSeconds = iTemp;
}
void Time::SetTimeOfDay(string sTemp)
{
	sTimeOfDay = sTemp;
}

int Time::GetHoursD()
{
	return iHoursD;
}
string Time::GetLZHours()
{
	return sLZHours;
}
int Time::GetMinutesD()
{
	return iMinutesD;
}
string Time::GetLZMinutes()
{
	return sLZMinutes;
}
int Time::GetSecondsD()
{
	return iSecondsD;
}
string Time::GetLZSeconds()
{
	return sLZSeconds;
}
string Time::GetTimeOfDayD()
{
	return sTimeOfDayD;
}

void Time::SetHoursD(int iTemp)
{
	iHoursD = iTemp;
}
void Time::SetLZHours(string sTemp)
{
	sLZHours = sTemp;
}
void Time::SetMinutesD(int iTemp)
{
	iMinutesD = iTemp;
}
void Time::SetLZMinutes(string sTemp)
{
	sLZMinutes = sTemp;
}
void Time::SetSecondsD(int iTemp)
{
	iSecondsD = iTemp;
}
void Time::SetLZSeconds(string sTemp)
{
	sLZSeconds = sTemp;
}
void Time::SetTimeOfDayD(string sTemp)
{
	sTimeOfDayD = sTemp;
}