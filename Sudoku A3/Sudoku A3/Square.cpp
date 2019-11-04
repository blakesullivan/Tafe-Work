//Blake Sullivan - Square.cpp
#include "Square.h"

Square::Square()
{
	SetNum(0);
	SetIsUserNum(false);
	SetIsEmpty(true);
	SetIsPreviousUserNum(false);
	SetPossibleNumsRemaining(0);
	SetRow(0);
	SetCol(0);
	SetSubGrid(0);
	for (int i = 0; i < 10; i++)
		{SetNumbersLeft(i, true);}
}

void Square::Init(int n, bool ie, int pnr, int r, int c, int sg)
{
	SetNum(n);
	SetIsUserNum(false);
	SetIsEmpty(ie);
	SetIsPreviousUserNum(false);
	SetPossibleNumsRemaining(pnr);
	SetRow(r);
	SetCol(c);
	SetSubGrid(sg);
	for (int i = 0; i < 10; i++)
	{
		if (n > 0 && i != n)
			{SetNumbersLeft(i, false);}
	}
}

void Square::SetNum(int n)
{
	m_iNum = n;
}
void Square::SetIsUserNum(bool iun)
{
	m_bIsUserNum = iun;
}
void Square::SetIsEmpty(bool ie)
{
	m_bIsEmpty = ie;
}
void Square::SetIsPreviousUserNum(bool ipun)
{
	m_bIsPreviousUserNum = ipun;
}
void Square::SetPossibleNumsRemaining(int pnr)
{
	m_iPossibleNumsRemaining = pnr;
}
void Square::SetRow(int r)
{
	m_iRow = r;
}
void Square::SetCol(int c)
{
	m_iCol = c;
}
void Square::SetSubGrid(int sg)
{
	m_iSubGridNum = sg;
}
void Square::SetNumbersLeft(int i, bool l)
{
	m_abNumbersLeft[i] = l;
}

int Square::GetNum()
{
	return m_iNum;
}
bool Square::GetIsUserNum()
{
	return m_bIsUserNum;
}
bool Square::GetIsEmpty()
{
	return m_bIsEmpty;
}
bool Square::GetIsPreviousUserNum()
{
	return m_bIsPreviousUserNum;
}
int Square::GetPossibleNumsRemaining()
{
	return m_iPossibleNumsRemaining;
}
int Square::GetRow()
{
	return m_iRow;
}
int Square::GetCol()
{
	return m_iCol;
}
int Square::GetSubGrid()
{
	return m_iSubGridNum;
}
bool Square::GetNumbersLeft(int i)
{
	return m_abNumbersLeft[i];
}