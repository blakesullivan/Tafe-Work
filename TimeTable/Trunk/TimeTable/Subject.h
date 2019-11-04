//Blake Sullivan - Subject.h
#ifndef SUBJECT_H
#define SUBJECT_H
#include <iostream>
#include <string>
#include "Unit.h"
using namespace std;

class Subject
{
private:
	string sSubjectGroupName;
	Unit units;
	int iHours;
	bool bTut;

public:
	Subject();

	void Display();
};
#endif