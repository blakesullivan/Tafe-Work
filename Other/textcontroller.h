//Tim's Text Controller :D

#ifndef TEXTCONTROL_H
	#define TEXTCONTROL_H

#include <string>
using namespace std;

class TextController {
private:
	void Manage();

	int ColourStringToColourInt(string);

public:
	TextController();

	void SetTextColours(int, int);
	void SetTextColours(string, string);

	void GotoXY(int, int);
};
#endif