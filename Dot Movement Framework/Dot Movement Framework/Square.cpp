//Blake Sullivan - Square.cpp
#include "Square.h"

Square::Square()
{
	SetRow(-1);
	SetCol(-1);
	SetX(-1);
	SetY(-1);
}

void Square::Init(int r, int c, int x, int y)
{
	SetRow(r);
	SetCol(c);
	SetX(x);
	SetY(y);
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

int Square::GetSize()
{
	return MSC_ISIZE;
}