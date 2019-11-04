//Blake Sullivan - Manage.h
#ifndef MANAGEGAME_H
#define MANAGEGAME_H
#include "Board.h"
class ManageGame
{
private:
	Board board;

public:
	ManageGame();

	void Manage();
	void DrawBoard(bool);
	void SetupPieces();
	void SetupSquares();

	void Move(string, bool);
	void SwapPiece(int, int);
	int ConvertX(char);
	int ConvertY(char);

	bool CheckInput(string);
	bool CheckLetter(char);
	bool CheckNumber(char);
	bool CheckSymbol(char);
	string Input(bool);

};
#endif