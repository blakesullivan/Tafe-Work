//Blake Sullivan - SudokuGrid.cpp
#include "SudokuGrid.h"

SudokuGrid::SudokuGrid()
{
	//
}

void SudokuGrid::Init()
{
	int r = 0, c = 0, sg = 0;
	for (int i = 0; i < MCS_IMAXSQUARES; i++)
	{
		//cout << "c: " << c << " r: " << r << endl;
		m_aSquare[i].Init(0, true, 9, r, c, FigureOutG(i));
		if (c < 8) {c++;} else {c = 0; r++;} 
	}
	
	/*for (int i = 0; i < MCS_IMAXSQUARES; i++)
	{
		cout << "col: " << m_aSquare[i].GetCol() << " row: " << m_aSquare[i].GetRow() << endl;
	}*/
}

Square* SudokuGrid::GetSquare(int i)
{
	return &m_aSquare[i];
}

int SudokuGrid::FigureOutG(int i)
{
	int g;
	if (i == 0 || i == 1 || i == 2 || i == 9 || i == 10 || i == 11 || i == 18 || i == 19 || i == 20)
		{g = 0;}
	else if (i == 3 || i == 4 || i == 5 || i == 12 || i == 13 || i == 14 || i == 21 || i == 22 || i == 23)
		{g = 1;}
	else if (i == 6 || i == 7 || i == 8 || i == 15 || i == 16 || i == 17 || i == 24 || i == 25 || i == 26)
		{g = 2;}
	else if (i == 27 || i == 28 || i == 29 || i == 36 || i == 37 || i == 38 || i == 45 || i == 46 || i == 47)
		{g = 3;}
	else if (i == 30 || i == 31 || i == 32 || i == 39 || i == 40 || i == 41 || i == 48 || i == 49 || i == 50)
		{g = 4;}
	else if (i == 33 || i == 34 || i == 35 || i == 42 || i == 43 || i == 44 || i == 51 || i == 52 || i == 53)
		{g = 5;}
	else if (i == 54 || i == 55 || i == 56 || i == 63 || i == 64 || i == 65 || i == 72 || i == 73 || i == 74)
		{g = 6;}
	else if (i == 57 || i == 58 || i == 59 || i == 66 || i == 67 || i == 68 || i == 75 || i == 76 || i == 77)
		{g = 7;}
	else if (i == 60 || i == 61 || i == 62 || i == 69 || i == 70 || i == 71 || i == 78 || i == 79 || i == 80)
		{g = 8;}
	return g;
}

void SudokuGrid::SetSquare(int iSquare, int iNum, bool bIsUserNum)
{
	m_aSquare[iSquare].SetNum(iNum);
	m_aSquare[iSquare].SetIsUserNum(bIsUserNum);
	//m_aSquare[iSquare].SetIsPreviousUserNum(false);
	if (iNum > 0)
	{
		m_aSquare[iSquare].SetIsEmpty(false);
		m_aSquare[iSquare].SetPossibleNumsRemaining(1);
		for (int j = 0; j < 10; j++)
		{
			if (j != m_aSquare[iSquare].GetNum())
				{m_aSquare[iSquare].SetNumbersLeft(j, false);}
		}
	}
	else
	{
		m_aSquare[iSquare].SetIsEmpty(true);
		m_aSquare[iSquare].SetPossibleNumsRemaining(9);
		for (int j = 0; j < 10; j++)
			{m_aSquare[iSquare].SetNumbersLeft(j, true);}
	}
	//cout << "SetSquare: Row: " << m_aSquare[iSquare].GetRow() << " Col: " << m_aSquare[iSquare].GetRow() << endl;
}

void SudokuGrid::UpdateUserNums()
{
	for (int i = 0; i < MCS_IMAXSQUARES; i++)
	{
		if (m_aSquare[i].GetIsUserNum() == true)
			{m_aSquare[i].SetForeColour(ccBlue);}
	}
}

void SudokuGrid::ResetPossibleNums()
{
	for (int i = 0; i < MCS_IMAXSQUARES; i++)
	{
		m_aSquare[i].SetPossibleNumsRemaining(9);
	}
}

int SudokuGrid::GetTotalEmptySquares()
{
	int iCount = 0;
	for (int i = 0; i < MCS_IMAXSQUARES; i++)
	{
		if (m_aSquare[i].GetIsEmpty() == true)
			{iCount++;}
	}
	return iCount;
}

bool SudokuGrid::CheckRow(int iFS, int iSS)
{
	bool bMatch = false;
	if (m_aSquare[iFS].GetRow() == m_aSquare[iSS].GetRow())
		{bMatch = true;}
	return bMatch;
}
bool SudokuGrid::CheckCol(int iFS, int iSS)
{
	bool bMatch = false;
	if (m_aSquare[iFS].GetCol() == m_aSquare[iSS].GetCol())
		{bMatch = true;}
	return bMatch;
}
bool SudokuGrid::CheckGrid(int iFS, int iSS)
{
	bool bMatch = false;
	if (m_aSquare[iFS].GetSubGrid() == m_aSquare[iSS].GetSubGrid())
		{bMatch = true;}
	return bMatch;
}

void SudokuGrid::CheckToRemoveNum(int iUseSquare, int iCheckSquare)
{
	if (m_aSquare[iCheckSquare].GetIsEmpty() == false)
	{
		RemovePossibleNum(iUseSquare, iCheckSquare);
	}
}

void SudokuGrid::RemovePossibleNum(int iUseSquare, int iSquareToRemoveFrom)
{
	m_aSquare[iUseSquare].SetNumbersLeft(m_aSquare[iSquareToRemoveFrom].GetNum(), false);
}

void SudokuGrid::UpdatePossibleNums(int iSquare)
{
	int iTemp = 0;
	m_aSquare[iSquare].SetPossibleNumsRemaining(9);

	for (int j = 1; j < 10; j++)
	{
		if (m_aSquare[iSquare].GetNumbersLeft(j) == false)
		{
			iTemp = m_aSquare[iSquare].GetPossibleNumsRemaining() - 1;
			m_aSquare[iSquare].SetPossibleNumsRemaining(iTemp);
		}
	}
}

bool SudokuGrid::CompareThePair(int iUseSquare, int iCompareSquare)
{
	bool bMatch = false;
	int iFN = 0, iSN = 0;
	for (int i = 1; i < 10; i++)
	{
		if (m_aSquare[iUseSquare].GetNumbersLeft(i) == true)
		{
			if (iFN == 0)
				{iFN = i;}
			else
				{iSN = i;}
		}
	}
	if (m_aSquare[iCompareSquare].GetNumbersLeft(iFN) == true && m_aSquare[iCompareSquare].GetNumbersLeft(iSN) == true)
	{
		if (CheckRow(iUseSquare, iCompareSquare) == true) {RemovePairs('r', iUseSquare, iCompareSquare);}
		if (CheckCol(iUseSquare, iCompareSquare) == true) {RemovePairs('c', iUseSquare, iCompareSquare);}
		if (CheckGrid(iUseSquare, iCompareSquare) == true) {RemovePairs('g', iUseSquare, iCompareSquare);}
		bMatch = true;
	}

	return bMatch;
}

void SudokuGrid::RemovePairs(char cType, int iFirst, int iSecond)
{
	for (int i = 0; i < 81; i++)
	{
		if (i != iFirst && i != iSecond)
		{
			if (cType == 'r')
			{
				if (CheckRow(iFirst, i) == true)
				{
					RemovePairFromNumLeft(iFirst, i);
				}
			}
			else if (cType == 'c')
			{
				if (CheckCol(iFirst, i) == true)
				{
					RemovePairFromNumLeft(iFirst, i);
				}
			}
			else if (cType == 'g')
			{
				if (CheckGrid(iFirst, i) == true)
				{
					RemovePairFromNumLeft(iFirst, i);
				}
			}
		}
		UpdatePossibleNums(i);
	}
}

void SudokuGrid::RemovePairFromNumLeft(int iUseSquare, int iRemoveSquare)
{
	for (int i = 1; i < 10; i++)
	{
		if (m_aSquare[iUseSquare].GetNumbersLeft(i) == true)
		{
			m_aSquare[iRemoveSquare].SetNumbersLeft(i, false);
		}
	}
}

Square* SudokuGrid::GetSquareFromGrid(int iRow, int iCol)
{
	//cout << "In GetSquareFromGrid. Remember to -1.\n";
	//cout << "Row: " << iRow << " Col: " << iCol << endl;
	int id = -1;
	for (int i = 0; i < MCS_IMAXSQUARES; i++)
	{
		//cout << "i: " << i << " Row: " << m_aSquare[i].GetRow() << " Col: " << m_aSquare[i].GetCol() << endl;
		if (m_aSquare[i].GetRow() == (iRow - 1) && m_aSquare[i].GetCol() == (iCol - 1))
		{
			id = i;
			break;
		}
	}
	//cout << "id: " << id << endl;
	//cout << "Num in square: " << m_aSquare[id].GetNum() << endl;
	return &m_aSquare[id];
}

Square* SudokuGrid::operator() (int id) 
{
	return &m_aSquare[id];
}

Square* SudokuGrid::operator() (int iRow, int iCol) 
{
	//cout << "In second overloaded operator.Remember to -1.\n";
	//cout << "Row: " << iRow << " Col: " << iCol << endl;
	int id = -1;
	for (int i = 0; i < MCS_IMAXSQUARES; i++)
	{
		//cout << "i: " << i << " Row: " << m_aSquare[i].GetRow() << " Col: " << m_aSquare[i].GetCol() << endl;
		if (m_aSquare[i].GetRow() == (iRow - 1) && m_aSquare[i].GetCol() == (iCol - 1))
		{
			id = i;
			break;
		}
	}
	//cout << "id: " << id << endl;
	//cout << "Num in square: " << m_aSquare[id].GetNum() << endl;
	return &m_aSquare[id];
}