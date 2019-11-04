//Blake Sullivan - SudokuGrid.h
#ifndef SUDOKUGRID_H
#define SUDOKUGRID_H

#include "Square.h"

class SudokuGrid
{
private:
	const static int MCS_IMAXSQUARES = 81;
	Square m_aSquare[81];

public:
	SudokuGrid();
	void Init();
	Square* GetSquare(int);
	int FigureOutG(int);
	void SetSquare(int iSquare, int iNum, bool bIsUserNum);
	void UpdateUserNums();
	void ResetPossibleNums();
	int GetTotalEmptySquares();
	bool CheckRow(int iFS, int iSS);
	bool CheckCol(int iFS, int iSS);
	bool CheckGrid(int iFS, int iSS);
	void CheckToRemoveNum(int iUseSquare, int iCheckSquare);
	void RemovePossibleNum(int iUseSquare, int iSquareToRemoveFrom);
	void UpdatePossibleNums(int iSquare);
	bool CompareThePair(int iUseSquare, int iCompareSquare);
	void RemovePairs(char cType, int iFirst, int iSecond);
	void RemovePairFromNumLeft(int iUseSquare, int iRemoveSquare);
};

#endif