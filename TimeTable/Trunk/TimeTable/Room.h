//Blake Sullivan - Room.h
#ifndef ROOM_H
#define ROOM_H
#include <iostream>
#include <string>
using namespace std;

class Room
{
private:
	string sName;
	string sLocation;
	string sType;

public:
	Room();

	void Display();
};

#endif