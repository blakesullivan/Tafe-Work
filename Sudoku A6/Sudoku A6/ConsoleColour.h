//Blake Sullivan - ConsoleColour.h

#ifndef CONSOLECOLOUR_H
#define CONSOLECOLOUR_H

#include <Windows.h>
#include <iostream>
#include <string>
#include "ColourHeader.h"
using namespace std;

class ConsoleColour 
{
public:
	ConsoleColour();

	void Reset();

	int ColourStringToColourInt(string);

	void SetTextColours(int, int);
	void SetTextColours(string, string);

	void DisplayColouredText(string, int, int);
	void DisplayColouredText(string, string, string);
};
#endif