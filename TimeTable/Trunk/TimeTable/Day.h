//Blake Sullivan - Day.h
#ifndef DAY_H
#define DAY_H
#include <iostream>
#include "Date.h"
#include "TimeTableItem.h"
using namespace std;

class Day
{
private:
	Date day;
	Date dateTimeTable;
	TimeTableItem timeTableItems;
public:
	Day();

	void Display();
};

#endif