//Blake Sullivan - ConsoleColour.cpp
#include "ConsoleColour.h"

ConsoleColour::ConsoleColour() 
{
	SetConsoleTitle(TEXT("Blakes C++ Chess Board"));
	Reset();
}

void ConsoleColour::Reset() 
{
	SetTextColours("white", "black");
}

int ConsoleColour::ColourStringToColourInt(string sColour) 
{
	if (sColour == "black")
		{return 0;}
	else if (sColour == "dark blue")
		{return 1;}
	else if (sColour == "dark green")
		{return 2;}
	else if (sColour == "dark cyan")
		{return 3;}
	else if (sColour == "maroon")
		{return 4;}
	else if (sColour == "purple")
		{return 5;}
	else if (sColour == "brown")
		{return 6;}
	else if (sColour == "silver")
		{return 7;}
	else if (sColour == "grey")
		{return 8;}
	else if (sColour == "blue")
		{return 9;}
	else if (sColour == "green")
		{return 10;}
	else if (sColour == "cyan")
		{return 11;}
	else if (sColour == "red")
		{return 12;}
	else if (sColour == "pink")
		{return 13;}
	else if (sColour == "yellow")
		{return 14;}
	else if (sColour == "white")
		{return 15;}
	else
		{return 0;}
}

void ConsoleColour::SetTextColours(int iFore, int iBack) 
{
	if (iFore >= 0 && iFore <= 15 && iBack >= 0 && iBack <= 15) 
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), iFore + iBack * 16);
	}
}

void ConsoleColour::SetTextColours(string sFore, string sBack) 
{
	int iFore = -1;
	int iBack = -1;

	iFore = ColourStringToColourInt(sFore);
	iBack = ColourStringToColourInt(sBack);

	if (iFore > -1 && iBack > -1) {
		SetTextColours(iFore, iBack);
	}
}

void ConsoleColour::DisplayColouredText(string sOutput, int iFore, int iBack)
{
	SetTextColours(iFore, iBack);
	cout << sOutput;
	Reset();
}
void ConsoleColour::DisplayColouredText(string sOutput, string sFore, string sBack)
{
	SetTextColours(sFore, sBack);
	cout << sOutput;
	Reset();
}