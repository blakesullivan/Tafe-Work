//Blake Sullivan - Piece.cpp
#include "Piece.h"

Piece::Piece()
{
	SetID(' ');
	SetSide(false);
	SetIsBlack(false);
	SetLocation(0);
	SetValue(0);
	SetMoved(false);
	SetAlive(false);
	SetR1(0);
	SetR2(0);
	SetL1(0);
	SetL2(0);

	//Display();
}

void Piece::Init(char id, bool ks, bool iw, int loc, int val, int r1, int r2, int l1, int l2)
{
	SetID(id);
	SetSide(ks);
	SetIsBlack(iw);
	SetLocation(loc);
	SetValue(val);
	SetMoved(false);
	SetAlive(true);
	SetR1(r1);
	SetR2(r2);
	SetL1(l1);
	SetL2(l2);
}

void Piece::Display()
{
	cout << "PIECE VARIABLES" << endl;
	cout << "GetID: " << GetID() << endl;
	cout << "GetSide: " << GetSide() << endl;
	cout << "GetIsBlack: " << GetIsBlack() << endl;
	cout << "GetLocation: " << GetLocation() << endl;
	cout << "GetValue: " << GetValue() << endl;
	cout << "GetMoved: " << GetMoved() << endl;
	cout << "GetR1: " << GetR1() << endl;
	cout << "GetR2: " << GetR2() << endl;
	cout << "GetL1: " << GetL1() << endl;
	cout << "GetL2: " << GetL2() << endl;
}

void Piece::SetID(char id)
{
	cID = id;
}
void Piece::SetSide(bool ks)
{
	bKingSide = ks;
}
void Piece::SetIsBlack(bool ib)
{
	bIsBlack = ib;
}
void Piece::SetLocation(int loc)
{
	iLocation = loc;
}
void Piece::SetValue(int val)
{
	iValue = val;
}
void Piece::SetMoved(bool mov)
{
	bMoved = mov;
}

void Piece::SetAlive(bool bTemp)
{
	bAlive = bTemp;
}

char Piece::GetID()
{
	return cID;
}
bool Piece::GetSide()
{
	return bKingSide;
}
bool Piece::GetIsBlack()
{
	return bIsBlack;
}
int Piece::GetLocation()
{
	return iLocation;
}
int Piece::GetValue()
{
	return iValue;
}
bool Piece::GetMoved()
{
	return bMoved;
}
bool Piece::GetAlive()
{
	return bAlive;
}