//Blake Sullivan - ChessBoard.h
#ifndef CHESSBOARD
#define CHESSBOARD

#include "Board.h"
class ChessBoard: virtual public Board
{
private:
	int m_iPieces;
public:
	ChessBoard();

	void Init(int, int, int, int);
	void Display(bool);

};
#endif