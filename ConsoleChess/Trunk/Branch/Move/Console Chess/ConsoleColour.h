//Blake Sullivan - ConsoleColour.h

#ifndef CONSOLECOLOUR_H
#define CONSOLECOLOUR_H

#include <Windows.h>
#include <iostream>
#include <string>
using namespace std;

class ConsoleColour 
{
public:
	ConsoleColour();

	void Manage();

	int ColourStringToColourInt(string);

	void SetTextColours(int, int);
	void SetTextColours(string, string);
};
#endif