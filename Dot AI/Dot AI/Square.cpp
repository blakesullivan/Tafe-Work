//Blake Sullivan - Square.cpp
#include "Square.h"

int Square::ms_iSize = 32;

Square::Square()
{
	SetRow(-1);
	SetCol(-1);
	SetX(-1);
	SetY(-1);
	SetWalkable(0);
	SetSize(0);
}

void Square::Init(int r, int c, int x, int y, int s, int tpp)
{
	SetRow(r);
	SetCol(c);
	SetX(x);
	SetY(y);
	if (tpp == 0)
		{SetWalkable(0);}
	else
		{SetWalkable(9);}
	SetSize(s);
	SetTilePicPos(tpp);
}
void Square::SetRow(int r)
{
	m_iRow = r;
}
void Square::SetCol(int c)
{
	m_iCol = c;
}
void Square::SetX(int x)
{
	m_iX = x;
}
void Square::SetY(int y)
{
	m_iY = y;
}
void Square::SetWalkable(int w)
{
	m_iWalkable = w;
}
void Square::SetTilePicPos(int tpp)
{
	m_iTilePicPos = tpp;
}
void Square::SetSize(int s)
{
	ms_iSize = s;
}

int Square::GetRow()
{
	return m_iRow;
}
int Square::GetCol()
{
	return m_iCol;
}
int Square::GetX()
{
	return m_iX;
}
int Square::GetY()
{
	return m_iY;
}
int Square::GetWalkable()
{
	return m_iWalkable;
}
int Square::GetTilePicPos()
{
	return m_iTilePicPos;
}
int Square::GetSize()
{
	return ms_iSize;
}