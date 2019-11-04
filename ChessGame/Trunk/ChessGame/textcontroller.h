//Tim's Text Controller :D 1.1

#ifndef TEXTCONTROL_H
	#define TEXTCONTROL_H

#include <string>
using namespace std;

class TextController {
private:

public:
	TextController();

	void Manage();

	int ColourStringToColourInt(string);

	void SetTextColours(int, int);
	void SetTextColours(string, string);

	void GotoXY(int, int);
	int GetCursorX();
	int GetCursorY();

	void ClearScreen();
	void ChangeScreenSize(int, int);
};
#endif