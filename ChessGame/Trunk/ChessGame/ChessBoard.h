//Blake Sullivan - ChessBoard.h
#ifndef CHESSBOARD_H
#define CHESSBOARD_H
#include <iostream>
#include <string>
#include "textcontroller.h"
using namespace std;

class ChessBoard
{
private:
	static const char ccCornerTL = 218;
	static const char ccCornerTR = 191;
	static const char ccCornerBL = 192;
	static const char ccCornerBR = 217;
	static const char ccBorderHor = 196;
	static const char ccBorderHBT = 194;
	static const char ccBorderHBB = 193;
	static const char ccBorderVer = 179;
	static const char ccBorderVBL = 195;
	static const char ccBorderVBR = 180;
	static const char ccBorderCross = 197;

	static const int ciGridSize = 8;

	struct Board
	{
		char name;
		string foreCol;
		string backCol;
	};
	Board boardPos[ciGridSize][ciGridSize];

	TextController objTT;

public:
	ChessBoard();
	void Draw();
	
	void DrawAscii(int);
	void DrawTop(int);
	void DrawBottom(int);
	void DrawHBorderSegment(int);
	void DrawHBorderSegment(int, int, int);
	void DrawHBorderLine();

	void DrawMid(int, int);
	void DrawMidSegment(int, bool, int, int);
	void DrawSpace();
	void DrawPiece(int, int);

	void DrawInnerBorder(int, int);
	void DrawVBorderSegment(int);
	void DrawVBorderLine();

	void DrawColour(int);

	void DefaultPos();
	void SetCharPos(int, int, char);
	char GetCharPos(int, int);
};
#endif