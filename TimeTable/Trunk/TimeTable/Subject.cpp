//Blake Sullivan - Subject.cpp
#include "Subject.h"

Subject::Subject()
{
	sSubjectGroupName = "";
	iHours = 0;
	bTut = false;
	Display();
}

void Subject::Display()
{
	cout << "SUBJECT VARIABLES" << endl;
	cout << "sSubjectGroupName: " << sSubjectGroupName << endl;
	cout << "iHours: " << iHours << endl;
	cout << "bTut: " << bTut << endl;
}