//Blake Sullivan - Teacher.cpp
#include "Teacher.h"

Teacher::Teacher()
{
	sFirstName="";
	sLastName="";
	Display();
}

void Teacher::Display()
{
	cout << "TEACHER VARIABLES" << endl;
	cout << "sFirstName: " << sFirstName << endl;
	cout << "sLastName: " << sLastName << endl;
}