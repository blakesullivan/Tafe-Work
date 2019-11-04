//Tim's Text Controller :D 1.1

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

int TextController::GetCursorX() {
	CONSOLE_SCREEN_BUFFER_INFO ScreenBuffer;

	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &ScreenBuffer);

	return ScreenBuffer.dwCursorPosition.X;
}

int TextController::GetCursorY() {
	CONSOLE_SCREEN_BUFFER_INFO ScreenBuffer;

	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &ScreenBuffer);

	return ScreenBuffer.dwCursorPosition.Y;
}


void TextController::ClearScreen() {
	int y, x = 0;

	GotoXY(0, 0);

	for (y = 0; y < 12; y++) {
		for (x = 0; x < 36; x++) {
			cout << " " << endl;
		}
	}

	GotoXY(0, 0);
}

void TextController::ChangeScreenSize(int h, int w) {
    SMALL_RECT DisplayArea = {0,0,0,0};

	//Default is h23, w79
    DisplayArea.Bottom = h;   
	DisplayArea.Right = w;
    SetConsoleWindowInfo(GetStdHandle(STD_OUTPUT_HANDLE), TRUE, &DisplayArea);
}