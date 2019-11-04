//Blake Sullivan - Square.cpp
#include "Square.h"

Square::Square()
{
	SetIsWhite(false);
	SetLocRow(0);
	SetLocCol(0);
	SetGridRef(0);
	SetPiece(0);
	//Display();
}

void Square::Init(bool iw, int locX, int locY, int gr, int cp)
{
	SetIsWhite(iw);
	SetLocRow(locX);
	SetLocCol(locY);
	SetGridRef(gr);
	SetPiece(cp);
}

void Square::Display()
{
	cout << "SQUARE VARIABLES" << endl;
	cout << "GetIsWhite: " << GetIsWhite() << endl;
	cout << "GetLocRow: " << GetLocRow() << endl;
	cout << "GetLocCol: " << GetLocCol() << endl;
	cout << "GetGridRef: " << GetGridRef() << endl;
	cout << "GetPiece: " << GetPiece() << endl;
}


void Square::SetIsWhite(bool bTemp)
{
	bIsWhite=bTemp;
}
void Square::SetLocRow(int iTemp)
{
	iLocRow=iTemp;
}
void Square::SetLocCol(int iTemp)
{
	iLocCol=iTemp;
}
void Square::SetGridRef(int iTemp)
{
	iGridRef=iTemp;
}
void Square::SetPiece(int iTemp)
{
	iPiece = iTemp;
}

bool Square::GetIsWhite()
{
	return bIsWhite;
}
int Square::GetLocRow()
{
	return iLocRow;
}
int Square::GetLocCol()
{
	return iLocCol;
}
int Square::GetGridRef()
{
	return iGridRef;
}
int Square::GetPiece()
{
	return iPiece;
}