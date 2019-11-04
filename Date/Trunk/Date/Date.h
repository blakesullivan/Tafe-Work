//Blake Sullivan - Date.h
#ifndef DATE_H
#define DATE_H
#include <iostream>
#include <string>
using namespace std;

class Date
{
private:
	int iDay;
	int iMonth;
	int iYear;
	bool bLeapYear;

public:
	Date();

	void Display();

	void ManageInput();
	void ManageDisplay();

	int InputOption(string, int, int);
	bool CheckOption(string, int, int);
	bool CheckLeapYear(int);
	int CheckDayInMonth(int, bool);

	void DisplayDate(string, bool = false);

	void SetDay(int);
	void SetMonth(int);
	void SetYear(int);
	void SetLeapYear(bool);

	int GetDay();
	int GetMonth();
	int GetYear();
	bool GetLeapYear();
};
#endif