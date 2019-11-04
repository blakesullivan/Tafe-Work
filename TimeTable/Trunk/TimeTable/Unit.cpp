//Blake Sullivan - Unit.cpp
#include "Unit.h"

Unit::Unit()
{
	sUnitNumber="";
	sUnitName="";
	iHours=0;
	Display();
}

void Unit::Display()
{
	cout << "UNIT VARIABLES" << endl;
	cout << "sUnitNumber: " << sUnitNumber << endl;
	cout << "sUnitName: " << sUnitName << endl;
	cout << "iHours: " << iHours << endl;
}