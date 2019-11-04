//Blake Sullivan - Board.h
#ifndef BOARD_H
#define BOARD_H
#include "Square.h"
#include "Piece.h"
#include "ConsoleColour.h"
#include <iostream>
#include <string>
using namespace std;

class Board
{
public: 
	static const int CIMAXPIECES = 33;
	static const int CIMAXSQUARES = 64;
	static const int CIBOARDSIZE = 8;

private:
	int iForeWhiteCol, iForeBlackCol, iBackWhiteCol, iBackBlackCol;
	int iBorderForeCol, iBorderBackCol;
	int iGridSizeH, iGridSizeV;
	char cTopLeftCorner, cTopRightCorner, cBotLeftCorner, cBotRightCorner, cHorizontal, cVertical;
	ConsoleColour objCC;
	Square squares[CIMAXSQUARES];
	Piece pieces[CIMAXPIECES];

public:
	Board();

	void Init();

	void Display();
	void DrawLine(int, int, int);
	void DrawSquare(int, bool);
	void DrawSquare();

	void SetupPiece(int, char, bool, bool, int, int, int, int, int, int);
	void SetupSquare(int, bool, int, int, int, int);
	void SetupSquareColours(int);

	void SetColour(string, string, string, string);
	void SetGridSize(int, int);
	void SetBorders(char, char, char, char, char, char);
	void SetBorderCol(string, string);

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

	bool CheckCoOrds(int, int, int);

	int GetPieceLocFromSquare(int);
	int GetSquareLocFromPiece(int);

	void SetPieceLocInSquare(int, int);
	void SetSquareLocInPiece(int, int);

};

#endif