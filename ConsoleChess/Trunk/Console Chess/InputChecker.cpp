//Blake Sullivan - InputChecker.cpp
#include "InputChecker.h"

int InputChecker::InputOptionInt(string sOutput, int iMin, int iMax)
{
	string sInput = " ";
	bool bExit = false;
	do
	{
		cout << sOutput;
		getline(cin, sInput);
		if (true == CheckOption(sInput, iMin, iMax))
			{bExit = true;}
		else
			{bExit = false;}
	}while (false == bExit);
	return atoi(sInput.c_str());
}

bool InputChecker::InputOptionBool(string sOutput, int iMin, int iMax)
{
	string sInput = " ";
	bool bValid = false, bExit = false;
	do
	{
		cout << sOutput;
		getline(cin, sInput);
		bValid = CheckOption(sInput, iMin, iMax);
		bExit = bValid;
	}while (false == bExit);
	return bValid;
}

string InputChecker::InputOptionStr(string sOutput, int iMin, int iMax)
{
	string sInput = " ";
	bool bExit = false;
	do
	{
		cout << sOutput;
		getline(cin, sInput);
		bExit = CheckOption(sInput, iMin, iMax);
	}while (false == bExit);
	return sInput;
}

bool InputChecker::CheckOption(string sInput, int iMin, int iMax)
{
	const char* cInput = sInput.c_str();
	if (*cInput < '0' || *cInput > '9')
	{
		cout << "Invalid Input. Number not entered.\n";
		return false;
	}
	else
	{
		int iInput = 0;
		iInput = atoi(sInput.c_str());
		if (iInput >= iMin && iInput <= iMax)
			{return true;}
		else
		{
			cout << "Invalid Input. Input not within bounds.\n";
			return false;
		}
	}
}