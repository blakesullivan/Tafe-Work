//Blake Sullivan - Time Class.cpp
#include <iostream>
#include "TimeTable.h"
using namespace std;

TimeTable::TimeTable()
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

	for (int i=0;i<10;i++)
	{
		SetLessonArrayStart(i);
		SetLessonArrayEnd(i);
	}
}

void TimeTable::LessonInput(int iSet)
{
	int iNum=0;
	while (iNum<2)
	{
		if (0==iNum)
		{
			InputLessonName(iSet);
			cout<<"Now you will enter the Start time."<<endl;
		}
		else
		{cout<<"Now you will enter the Finish time."<<endl;}
		int iOption = InputOption();
		InputHours(iOption);
		InputMinutes();
		//InputSeconds();
		if (1==iOption)
		{
			InputTimeOfDay();
		}
		else
		{SetTimeOfDay(" ");}
		ConvertToTweleve();
		if (0==iNum)
		{SetLessonArrayStart(iSet);}
		else
		{SetLessonArrayEnd(iSet);}
		iNum++;
	}
	/*int iDisplayOption = InputDisplayOption();
	if (1==iDisplayOption)
	{
		ConvertToTweleve();
	}
	else if (2==iDisplayOption)
	{
		ConvertToTwenty();
	}
	Display();*/
}

void TimeTable::LessonDelete(int iSet)
{
	SetLessonName(iSet, "");
	SetLessonHS(iSet, 0);
	SetLessonMS(iSet, 0);
	SetLessonLZMS(iSet, "");
	SetLessonToDS(iSet, "");
	SetLessonHE(iSet, 0);
	SetLessonME(iSet, 0);
	SetLessonLZME(iSet, "");
	SetLessonToDE(iSet, "");
	//SetLessonDur(iSet, 0.0);
}

int TimeTable::InputOption()
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

void TimeTable::InputHours(int iOption)
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
			int iInput = atoi(sInput.c_str());
			SetHours(iInput);
		}
		else
		{
			bExit=false;
			cout<<"Invalid input, please try again."<<endl;
		}
	}
}

void TimeTable::InputMinutes()
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

void TimeTable::InputSeconds()
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

void TimeTable::InputTimeOfDay()
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

void TimeTable::InputLessonName(int iSet)
{
	string sInput;
	cout<<"Please input the Name of the Lesson: ";
	getline(cin, sInput);
	SetLessonName(iSet, sInput);
}

int TimeTable::InputDisplayOption()
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

bool TimeTable::CheckHours(int iOption, string sInput)
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

bool TimeTable::CheckMinutes(string sInput)
{
	const char *cInput = sInput.c_str();
	if (*cInput < '0' || *cInput > '9')
	{return false;}
	else
	{
		int iInput = atoi(sInput.c_str());
		if (iInput >= 0 && iInput < 60)
		{return true;}
		else
		{return false;}
	}
}
bool TimeTable::CheckSeconds(string sInput)
{
	const char *cInput = sInput.c_str();
	if (*cInput < '0' || *cInput > '9')
	{return false;}
	else
	{
		int iInput = atoi(sInput.c_str());
		if (iInput >= 0 && iInput < 60)
		{return true;}
		else
		{return false;}
	}
}
bool TimeTable::CheckTimeOfDay(string sInput)
{

	if (sInput=="am" || sInput=="AM" || sInput=="Am" || sInput=="aM")
	{return true;}
	else if (sInput=="pm" || sInput=="PM" || sInput=="Pm" || sInput=="pM")
	{return true;}
	else
	{return false;}
}
bool TimeTable::CheckInputOption(string sInput)
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

void TimeTable::Display()
{
	//cout<<"The time input was: "<<GetHours()<<":"<<GetMinutes()<<":"<<GetSeconds()<<GetTimeOfDay()<<endl;
	cout<<"The time converted is: "<<GetLZHours()<<GetHoursD()<<":"<<GetLZMinutes()<<GetMinutesD()<<":"<<GetLZSeconds()<<GetSecondsD()<<GetTimeOfDayD()<<endl;
}

void TimeTable::DisplayLesson()
{
	bool bExit=false;
	int i=0;
	while (false==bExit)
	{
		if(0!=GetLessonHS(i))
		{
			cout<<"Lesson "<<i+1<<":";
			cout<<GetLessonName(i)<<endl;
			cout<<"Begins at: ";
			cout<<GetLessonHS(i)<<":";
			cout<<GetLessonLZMS(i);
			cout<<GetLessonMS(i)<<" ";
			cout<<GetLessonToDS(i)<<endl;
			cout<<"Ends at: ";
			cout<<GetLessonHE(i)<<":";
			cout<<GetLessonLZME(i);
			cout<<GetLessonME(i)<<" ";
			cout<<GetLessonToDE(i)<<endl;
			i++;
		}
		else
		{bExit=true;}
	}
}

void TimeTable::ConvertToTweleve()
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

void TimeTable::ConvertToTwenty()
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

int TimeTable::GetHours()
{
	return iHours;
}
int TimeTable::GetMinutes()
{
	return iMinutes;
}
int TimeTable::GetSeconds()
{
	return iSeconds;
}
string TimeTable::GetTimeOfDay()
{
	return sTimeOfDay;
}

void TimeTable::SetHours(int iTemp)
{
	iHours = iTemp;
}
void TimeTable::SetMinutes(int iTemp)
{
	iMinutes = iTemp;
}
void TimeTable::SetSeconds(int iTemp)
{
	iSeconds = iTemp;
}
void TimeTable::SetTimeOfDay(string sTemp)
{
	sTimeOfDay = sTemp;
}

int TimeTable::GetHoursD()
{
	return iHoursDisplay;
}
string TimeTable::GetLZHours()
{
	return sLZHours;
}
int TimeTable::GetMinutesD()
{
	return iMinutesDisplay;
}
string TimeTable::GetLZMinutes()
{
	return sLZMinutes;
}
int TimeTable::GetSecondsD()
{
	return iSecondsDisplay;
}
string TimeTable::GetLZSeconds()
{
	return sLZSeconds;
}
string TimeTable::GetTimeOfDayD()
{
	return sTimeOfDayDisplay;
}

void TimeTable::SetHoursD(int iTemp)
{
	iHoursDisplay = iTemp;
}
void TimeTable::SetLZHours(string sTemp)
{
	sLZHours = sTemp;
}
void TimeTable::SetMinutesD(int iTemp)
{
	iMinutesDisplay = iTemp;
}
void TimeTable::SetLZMinutes(string sTemp)
{
	sLZMinutes = sTemp;
}
void TimeTable::SetSecondsD(int iTemp)
{
	iSecondsDisplay = iTemp;
}
void TimeTable::SetLZSeconds(string sTemp)
{
	sLZSeconds = sTemp;
}
void TimeTable::SetTimeOfDayD(string sTemp)
{
	sTimeOfDayDisplay = sTemp;
}

void TimeTable::SetLessonArrayStart(int iSet)
{
	SetLessonHS(iSet, iHoursDisplay);
	SetLessonLZMS(iSet, GetLZMinutes());
	SetLessonMS(iSet, iMinutesDisplay);
	SetLessonToDS(iSet, sTimeOfDayDisplay);
}

void TimeTable::SetLessonArrayEnd(int iSet)
{
	SetLessonHE(iSet, iHoursDisplay);
	SetLessonLZME(iSet, GetLZMinutes());
	SetLessonME(iSet, iMinutesDisplay);
	SetLessonToDE(iSet, sTimeOfDayDisplay);
}

void TimeTable::SetLessonName(int iSet, string sValue)
{
	lesson[iSet].sName = sValue;
}
void TimeTable::SetLessonHS(int iSet, int iValue)
{
	lesson[iSet].iHourStart = iValue;
}
void TimeTable::SetLessonHE(int iSet, int iValue)
{
	lesson[iSet].iHourEnd = iValue;
}
void TimeTable::SetLessonLZMS(int iSet, string sValue)
{
	lesson[iSet].sMinuteLZStart = sValue;
}
void TimeTable::SetLessonMS(int iSet, int iValue)
{
	lesson[iSet].iMinuteStart = iValue;
}
void TimeTable::SetLessonLZME(int iSet, string sValue)
{
	lesson[iSet].sMinuteLZEnd = sValue;
}
void TimeTable::SetLessonME(int iSet, int iValue)
{
	lesson[iSet].iMinuteEnd = iValue;
}
void TimeTable::SetLessonToDS(int iSet, string sValue)
{
	lesson[iSet].sTimeOfDayStart = sValue;
}
void TimeTable::SetLessonToDE(int iSet, string sValue)
{
	lesson[iSet].sTimeOfDayEnd = sValue;
}

string TimeTable::GetLessonName(int iSet)
{
	return lesson[iSet].sName;
}
int TimeTable::GetLessonHS(int iSet)
{
	return lesson[iSet].iHourStart;
}
int TimeTable::GetLessonHE(int iSet)
{
	return lesson[iSet].iHourEnd;
}
string TimeTable::GetLessonLZMS(int iSet)
{
	return lesson[iSet].sMinuteLZStart;
}
int TimeTable::GetLessonMS(int iSet)
{
	return lesson[iSet].iMinuteStart;
}
string TimeTable::GetLessonLZME(int iSet)
{
	return lesson[iSet].sMinuteLZEnd;
}
int TimeTable::GetLessonME(int iSet)
{
	return lesson[iSet].iMinuteEnd;
}
string TimeTable::GetLessonToDS(int iSet)
{
	return lesson[iSet].sTimeOfDayStart;
}
string TimeTable::GetLessonToDE(int iSet)
{
	return lesson[iSet].sTimeOfDayEnd;
}