//Blake Sullivan - TimeTableItem.h
#ifndef TIMETABLEITEM_H
#define TIMETABLEITEM_H
#include <iostream>
#include <string>
using namespace std;
#include "Subject.h"
#include "Teacher.h"
#include "Room.h"
#include "Time.h"

class TimeTableItem
{
private:
	Subject subject;
	Teacher teacher;
	Room room;
	Time fromTime;
	Time toTime;
	string sDay;
public:
	TimeTableItem();

	void Display();
};
#endif