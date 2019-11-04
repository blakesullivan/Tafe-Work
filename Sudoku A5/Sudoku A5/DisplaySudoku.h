//Blake Sullivan - DisplaySudoku.h
#ifndef DISPLAYSUDOKU_H
#define DISPLAYSUDOKU_H

#include <windows.h>
#include <iostream>
#include "SudokuGrid.h"
using namespace std;

class DisplaySudoku
{
private:
	char m_cTop, m_cMid, m_cMidsMid;
	char m_cTopLeft, m_cTopRight, m_cTopMidSng, m_cTopMidDbl;
	char m_cMidOut, m_cMidLeft, m_cMidRight, m_cMidSng, m_cMidDbl;
	char m_cJoinLeft, m_cJoinSng, m_cJoinDbl, m_cJoinRight;
	char m_cBotLeft, m_cBotRight, m_cBotMidSng, m_cBotMidDbl;

public:
	DisplaySudoku();

	void Init();
	void DrawSudoku(SudokuGrid& sGrid, bool bShowPosLeft = false);
	void PrintHeader();
	void PrintMidNumberLine(int& iCurrNum, SudokuGrid& sGrid, bool bDrawPosLeft = false);
	void PrintMid();
	void PrintMidJoinLine();
	void PrintFooter();
};

#endif