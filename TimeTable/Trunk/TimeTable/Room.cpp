//Blake Sullivan - Room.cpp
#include "Room.h"

Room::Room()
{
	sName = "";
	sLocation = "";
	sType = "";
	Display();
}

void Room::Display()
{
	cout << "ROOM VARIABLES" << endl;
	cout << "sName: " << sName << endl;
	cout << "sLocation: " << sLocation << endl;
	cout << "sType: " << sType << endl;
}