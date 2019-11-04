//Tim's Text Controller :D

#include <Windows.h>
#include <iostream>
using namespace std;

#include "textcontroller.h"

//Constructors
TextController::TextController() {
	Manage();
}

//Private Functions
void TextController::Manage() {
	SetTextColours("white", "black");
}

int TextController::ColourStringToColourInt(string sColour) {
	if (sColour == "black") {
		return 0;
	}
	else if (sColour == "darkblue") {
		return 1;
	}
	else if (sColour == "darkgreen") {
		return 2;
	}
	else if (sColour == "darkcyan") {
		return 3;
	}
	else if (sColour == "darkred") {
		return 4;
	}
	else if (sColour == "darkmagenta" || sColour == "purple") {
		return 5;
	}
	else if (sColour == "brown" || sColour == "gold") {
		return 6;
	}
	else if (sColour == "lightgrey" || sColour == "silver") {
		return 7;
	}
	else if (sColour == "darkgrey" || sColour == "grey") {
		return 8;
	}
	else if (sColour == "blue") {
		return 9;
	}
	else if (sColour == "green") {
		return 10;
	}
	else if (sColour == "cyan") {
		return 11;
	}
	else if (sColour == "red") {
		return 12;
	}
	else if (sColour == "magenta" || sColour == "pink") {
		return 13;
	}
	else if (sColour == "yellow") {
		return 14;
	}
	else if (sColour == "white") {
		return 15;
	}
	else {
		return 0;
	}
}

//Public Functions
void TextController::SetTextColours(int iFore, int iBack) {
	if (iFore >= 0 && iFore <= 15 && iBack >= 0 && iBack <= 15) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), iFore + iBack * 16);
	}
}

void TextController::SetTextColours(string sFore, string sBack) {
	int iFore = -1;
	int iBack = -1;

	iFore = ColourStringToColourInt(sFore);
	iBack = ColourStringToColourInt(sBack);

	if (iFore > -1 && iBack > -1) {
		SetTextColours(iFore, iBack);
	}
}

void TextController::GotoXY(int iX, int iY) {
    //Set the cursor position
    COORD Coord;

    Coord.X = iX;
    Coord.Y = iY;

    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Coord);
}
