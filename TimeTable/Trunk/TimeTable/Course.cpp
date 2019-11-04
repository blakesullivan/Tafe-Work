//Blake Sullivan - Course.cpp
#include "Course.h"

Course::Course()
{
	sCourseName = "";
	Display();
}

void Course::Display()
{
	cout << "COURSE VARIABLES" << endl;
	cout << "sCourseName: " << sCourseName << endl;
}