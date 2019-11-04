//Blake Sullivan - MyTime.h
#ifndef MYTIME_H
#define MYTIME_H
#include <iostream>
#include <string>
using namespace std;

class MyTime
{
private:
	int iHour;
	int iMinute;
	int iSecond;

public:
	MyTime();
	
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