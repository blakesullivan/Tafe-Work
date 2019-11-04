//Input date - dd/mm/yyyy, leap years, different months-days, output day
#ifndef TIMETABLEDATE_H
#define TIMETABLEDATE_H
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class TimeTableDate
{
private:
	int iDay;
	int iMonth;
	int iYear;
	string sDay;

	struct Month
	{
		string name;
		int days;
	};
	Month mMonth[13];
	
	struct Day
	{
		string longName;
		string shortName;
	};
	Day dDay[7];

	int iStartDay[100][13];

public:
	TimeTableDate();

	bool CheckLeapYear(int);
	bool CheckYear(string);
	bool CheckMonth(string);
	bool CheckDay(string);

	string DisplayHeader();
	string DisplayDate(int, int);
	int CalcMaxDays(int, int);
	int CalcStartDay(int, int);

	void SetIDay(int);
	void SetMonth(int);
	void SetYear(int);
	void SetSDay(string);

	int GetIDay();
	string GetSDay();
	string GetDayShort(int);
	string GetDayLong(int);
	int GetIMonth();
	int GetMonthDays(int, int);
	string GetMonthName(int);
	int GetYear();
};
#endif
