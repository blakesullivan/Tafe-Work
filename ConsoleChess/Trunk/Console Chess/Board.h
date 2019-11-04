//Blake Sullivan - Board.h
#ifndef BOARD_H
#define BOARD_H
#include "Square.h"
#include "Piece.h"
#include "BoardDisplay.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Board : public BoardDisplay
{
	friend ostream& operator<<(ostream&, Piece);
	friend ostream& operator<<(ostream&, Square);
public: 
	static const int CIMAXPIECES = 33;
	static const int CIDUMMYPIECE = 32;
	static const int CIMAXSQUARES = 64;
private:
	bool bIsTake, bIsCastling, bCanEnPassent, bEnPassentTake;
	Square squares[CIMAXSQUARES];
	Piece pieces[CIMAXPIECES];

public:
	Board();

	void Init(string, string, string, string, int, int, char, char, char, char, char, char, string, string);

	void SetupPiece(int, char, bool, bool, int, int, int, int, int, int);
	void SetupSquare(int, bool, int, int, int, int);

	void Display();
	void DrawBoard(int, int, int, int, bool);
	void DrawLine(int, int, int);

	bool CheckEverythingValidForMove(int, int, int, int, bool);
	bool ValidMove(int, int);
	void MovePiece(int, int, bool);

	bool CheckCoOrds(int, int, int);
	bool CheckPieceIsSameCol(int, bool);
	bool CheckValidMove(int, int, bool);
	bool CheckLegalMove(int, int, bool = true);
	bool CheckLegalTake(int, int, bool = true);
	bool CheckLandingHasPiece(int);
	bool CheckPath(int, int, int, int, bool);
	bool CheckTakePieceColToDestPieceCol(int, int);
	bool CheckKingInCheck(bool, int, int);
	bool CheckKingInCheckPreMove(bool);
	bool CheckKingInCheckAfterMove(bool, int, int);
	bool CheckCastlingMove(int, int, int&, int&, bool); 
	bool CheckEnPassent(int, int);
	bool CheckEnPassentTake(int, int);

	void SetIsTake(bool);
	void SetIsCastling(bool);
	void SetCanEnPassent(bool);
	void SetEnPassentTake(bool);

	bool GetIsTake();
	bool GetIsCastling();
	bool GetCanEnPassent();
	bool GetEnPassentTake();

	int GetPieceLocFromSquare(int);
	int GetSquareLocFromPiece(int);
	int GetSquarePosFromSquareCoOrd(int, int);
	int GetOppKingPiece(bool);
	int GetKingPiece(bool);
	int GetRookForCastling(bool, int, bool);

	void SetPieceLocInSquare(int, int);
	void SetSquareLocInPiece(int, int);

	void OutputMove(string, string);
	void OutputSquares(string);
	void OutputPieces(string);
	void OutputSetup(string);

	void ReadSetupFile(string);
	string ReadMoveFile(fstream&);
	bool CheckEOFMove(fstream&);
};

#endif