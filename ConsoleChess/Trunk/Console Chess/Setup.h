//Blake Sullivan - Setup.h
#ifndef SETUP_H
#define SETUP_H

#include "ConsoleColour.h"
#include "InputChecker.h"
#include <iostream>
#include <string>
using namespace std;

class Setup : public InputChecker
{
private:
	string sForeWhiteCol, sForeBlackCol, sBackWhiteCol, sBackBlackCol;
	int iGridSizeX, iGridSizeY;
	char cBordTopL, cBordTopR, cBordBotL, cBordBotR, cBordHor, cBordVert;
	string sForeBordCol, sBackBordCol;
	ConsoleColour objCC;

public:
	Setup();

	void Manage();

	void SetupBoardSize();
	void SetupBoardColour();
	void SetupBorderColour();
	void SetupBorderCharacters();

	void SetBoardColours(string, string, string, string);
	void SetGridSize(int, int);
	void SetBorderChars(char, char, char, char, char, char);
	void SetBorderColours(string, string);

	string GetForeWhiteCol();
	string GetForeBlackCol();
	string GetBackWhiteCol();
	string GetBackBlackCol();
	int GetGridSizeX();
	int GetGridSizeY();
	char GetBordTopL();
	char GetBordTopR();
	char GetBordBotL();
	char GetBordBotR();
	char GetBordHor();
	char GetBordVert();
	string GetForeBorderCol();
	string GetBackBorderCol();
};

#endif