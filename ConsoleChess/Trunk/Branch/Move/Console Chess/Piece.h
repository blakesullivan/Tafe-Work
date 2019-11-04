//Blake Sullivan - Piece.h
#ifndef PIECE_H
#define PIECE_H
#include <iostream>
#include <string>
using namespace std;

class Piece
{
private:
	char cID; //'P', 'N', 'B'
	bool bKingSide;
	bool bIsWhite;
	int iLocation;
	int iValue;
	bool bMoved;
	int iR1, iR2, iL1, iL2;
	
public:
	Piece();

	void Display();

	void Init(char, bool, bool, int, int, int, int, int, int);

	void SetID(char);
	void SetSide(bool);
	void SetIsWhite(bool);
	void SetLocation(int);
	void SetValue(int);
	void SetMoved(bool);
	void SetR1(int);
	void SetR2(int);
	void SetL1(int);
	void SetL2(int);

	char GetID();
	bool GetSide();
	bool GetIsWhite();
	int GetLocation();
	int GetValue();
	bool GetMoved();
	int GetR1();
	int GetR2();
	int GetL1();
	int GetL2();
};
#endif