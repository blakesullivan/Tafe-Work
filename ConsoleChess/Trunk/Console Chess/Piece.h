//Blake Sullivan - Piece.h
#ifndef PIECE_H
#define PIECE_H
#include "Movement.h"
#include <iostream>
#include <string>
using namespace std;

class Piece : public Movement
{
private:
	char cID; //'P', 'N', 'B'
	bool bKingSide, bIsBlack, bMoved, bAlive;
	int iLocation, iValue;
	
public:
	Piece();

	void Display();

	void Init(char, bool, bool, int, int, int, int, int, int);

	void SetID(char);
	void SetSide(bool);
	void SetIsBlack(bool);
	void SetLocation(int);
	void SetValue(int);
	void SetMoved(bool);
	void SetAlive(bool);


	char GetID();
	bool GetSide();
	bool GetIsBlack();
	int GetLocation();
	int GetValue();
	bool GetMoved();
	bool GetAlive();
};
#endif