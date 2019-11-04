//Blake Sullivan - Manage Time Table
#ifndef MANAGETIMETABLE_H
#define MANAGETIMETABLE_H
#include "TimeTable.h"
#include "TimeTableDate.h"

class ManageTimeTable
{
private:

public:
	ManageTimeTable();

	void Manage();
	void ManageDate(TimeTableDate &);
	void ManageOptions(TimeTable[], TimeTableDate &);
	void ManageInput(TimeTable[], TimeTableDate &, int);
	void ManageDisplay(TimeTable[], TimeTableDate &, int);
	void ManageEdit(TimeTable[], TimeTableDate &, int);
	void ManageDelete(TimeTable[], TimeTableDate &, int);
	void DisplayCalender(TimeTableDate &);
	string InputYear();
	string InputMonth(TimeTableDate &);
	int InputDay(string, int);
	int InputOption(string, int);
	bool CheckInputDay(string, int&, int);
	bool CheckInput(string, int&, int);
};
#endif