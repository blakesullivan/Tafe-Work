//Blake Sullivan - TimeTable.h
#ifndef TIMETABLE_H
#define TIMETABLE_H
#include <iostream>
#include <string>
using namespace std;
#include "Date.h"
#include "Course.h"
#include "Day.h"

class TimeTable
{
private:
	string sUnitX;
	string sCollege;
	string sHeadTeacher;
	string sGroup;
	Date semesterStartDate;
	Date semesterEndDate;
	Date currentYear;
	Date estEndYear;
	Course course;
	int iStage;
	int iSemester;
	int iPhone;
	Day days;
	Date dateForTesting;
	Time timeForTesting;

public:
	TimeTable();

	void Display();
	void Manage();

	int InputOption(string, int, int);
	bool CheckOption(string, int, int);
};

#endif