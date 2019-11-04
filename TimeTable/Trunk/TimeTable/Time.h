//Blake Sullivan - Time.h
#ifndef TIME_H
#define TIME_H
#include <iostream>
#include <string>
using namespace std;

class Time
{
private:
	int iHour;
	int iMinute;
	int iSecond;

public:
	Time();

	void Display();
	
	void ManageInput();
	int InputOption(string, int, int);
	bool CheckOption(string, int, int);
	bool InputMethod(string);
	int InputHour(bool, bool);
	int InputMinute();
	int InputSecond();

	void ManageDisplay();

	int ConvertToTweleve(int);
	int ConvertToTwenty(int, bool);

	void SetHour(int);
	void SetMinute(int);
	void SetSecond(int);

	int GetHour();
	int GetMinute();
	int GetSecond();
};

#endif