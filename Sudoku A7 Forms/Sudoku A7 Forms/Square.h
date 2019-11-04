//Blake Sullivan - Square.h
#ifndef SQUARE_H
#define SQUARE_H

#include "ColourHeader.h"

class Square
{
private:
	int m_iNum;
	bool m_bIsUserNum;
	bool m_bIsEmpty;
	//bool m_bIsPreviousUserNum;
	int m_iPossibleNumsRemaining;
	int m_iRow;
	int m_iCol;
	int m_iSubGridNum;
	bool m_abNumbersLeft[10];
	int m_iForeColour, m_iBackColour;

public:
	Square();

	void Init(int n, bool ie, int pnr, int r, int c, int sg, int fcol = ccWhite, int bcol = ccBlack);
	
	void SetNum(int n);
	void SetIsUserNum(bool iun);
	void SetIsEmpty(bool ie);
	//void SetIsPreviousUserNum(bool ipun);
	void SetPossibleNumsRemaining(int pnr);
	void SetRow(int r);
	void SetCol(int c);
	void SetSubGrid(int sg);
	void SetNumbersLeft(int i, bool l);
	void SetForeColour(int fc);
	void SetBackColour(int bc);

	int GetNum();
	bool GetIsUserNum();
	bool GetIsEmpty();
	//bool GetIsPreviousUserNum();
	int GetPossibleNumsRemaining();
	int GetRow();
	int GetCol();
	int GetSubGrid();
	bool GetNumbersLeft(int i);
	int GetForeColour();
	int GetBackColour();
};

#endif