//Blake Sullivan - BoardDisplay.h
#ifndef BOARDDISPLAY_H
#define BOARDDISPLAY_H
#include "ConsoleColour.h"
class BoardDisplay
{
public:
	static const int CIBOARDSIZE = 8;
	static const int CIBORDERSIZE = 10;

private:
	int iForeWhiteCol, iForeBlackCol, iBackWhiteCol, iBackBlackCol;
	int iBorderForeCol, iBorderBackCol;
	int iGridSizeH, iGridSizeV;
	char cTopLeftCorner, cTopRightCorner, cBotLeftCorner, cBotRightCorner, cHorizontal, cVertical;
	ConsoleColour objCC;

public:
	BoardDisplay();

	void DrawSquare(bool, char);
	void DrawSquare();
	void DrawBorderVert(bool, int, int);
	void DrawBorderLine(bool, bool);
	void DrawBorder(int, int, bool, int);
	void SetupSquareColours(bool, bool);

	void SetColour(string, string, string, string);
	void SetColour(int, int, int, int);
	void SetGridSize(int, int);
	void SetBorders(char, char, char, char, char, char);
	void SetBorderCol(string, string);
	void SetBorderCol(int, int);

	int GetForeWhite();
	int GetBackWhite();
	int GetForeBlack();
	int GetBackBlack();
	int GetGridSizeH();
	int GetGridSizeV();
	char GetTopLeft(); 
	char GetTopRight(); 
	char GetBotLeft(); 
	char GetBotRight(); 
	char GetHorizontal(); 
	char GetVertical();
	int GetBorderFore(); 
	int GetBorderBack();
};
#endif