//Blake Sullivan - Unit.h
#ifndef UNIT_H
#define UNIT_H
#include <iostream>
#include <String>
using namespace std;

class Unit
{
private:
	string sUnitNumber;
	string sUnitName;
	int iHours;

public:
	Unit();

	void Display();
};

#endif