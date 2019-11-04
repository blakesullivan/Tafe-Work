//Blake Sullivan - InputChecer.h
#ifndef INPUTCHECKER_H
#define INPUTCHECKER_H

#include <iostream>
#include <string>
using namespace std;

class InputChecker
{
public:
	int InputOptionInt(string, int, int);
	bool InputOptionBool(string, int, int);
	string InputOptionStr(string, int, int);
	bool CheckOption(string, int, int);
};
#endif