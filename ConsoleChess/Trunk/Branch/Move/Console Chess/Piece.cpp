//Blake Sullivan - Piece.cpp
#include "Piece.h"

Piece::Piece()
{
	SetID(' ');
	SetSide(false);
	SetIsWhite(false);
	SetLocation(0);
	SetValue(0);
	SetMoved(false);
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
	SetIsWhite(iw);
	SetLocation(loc);
	SetValue(val);
	SetMoved(false);
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
	cout << "GetIsWhite: " << GetIsWhite() << endl;
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
void Piece::SetIsWhite(bool iw)
{
	bIsWhite = iw;
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

void Piece::SetR1(int iTemp)
{
	iR1 = iTemp;
}
void Piece::SetR2(int iTemp)
{
	iR2 = iTemp;
}
void Piece::SetL1(int iTemp)
{
	 iL1 = iTemp;
}
void Piece::SetL2(int iTemp)
{
	iL2 = iTemp;
}

char Piece::GetID()
{
	return cID;
}
bool Piece::GetSide()
{
	return bKingSide;
}
bool Piece::GetIsWhite()
{
	return bIsWhite;
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

int Piece::GetR1()
{
	return iR1;
}
int Piece::GetR2()
{
	return iR2;
}
int Piece::GetL1()
{
	return iL1;
}
int Piece::GetL2()
{
	return iL2;
}