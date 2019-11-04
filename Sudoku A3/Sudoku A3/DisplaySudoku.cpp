//Blake Sullivan - DisplaySudoku.cpp
#include "DisplaySudoku.h"

DisplaySudoku::DisplaySudoku()
{
	m_cTop = 0, m_cMid = 0; m_cMidsMid = 0;
	m_cTopLeft = 0; m_cTopRight = 0; m_cTopMidSng = 0; m_cTopMidDbl = 0;
	m_cMidOut = 0; m_cMidLeft = 0; m_cMidRight = 0; m_cMidSng = 0; m_cMidDbl = 0;
	m_cJoinLeft = 0; m_cJoinSng = 0; m_cJoinDbl = 0; m_cJoinRight = 0;
	m_cBotLeft = 0; m_cBotRight = 0; m_cBotMidSng = 0; m_cBotMidDbl = 0;
}

void DisplaySudoku::Init()
{
	m_cTop = 205; m_cMid = 179; m_cMidsMid = 196;
	m_cTopLeft = 201; m_cTopRight = 187; m_cTopMidSng = 209; m_cTopMidDbl = 203;
	m_cMidOut = 186; m_cMidLeft = 199; m_cMidSng = 197; m_cMidDbl = 215; m_cMidRight = 182;
	m_cJoinLeft = 204; m_cJoinSng = 216; m_cJoinDbl = 206; m_cJoinRight = 185;
	m_cBotLeft = 200; m_cBotMidSng = 207; m_cBotMidDbl = 202; m_cBotRight = 188;
}
void DisplaySudoku::DrawSudoku(SudokuGrid& sGrid, bool bShowPosLeft)
{
	int iCurrentNum = 0;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15 + 0 * 16);
	PrintHeader();
	for (int j = 0; j < 3; j++)
	{
		for (int i = 0; i < 2; i++)
		{
			PrintMidNumberLine(iCurrentNum, sGrid, bShowPosLeft);
			PrintMid();
		}
		PrintMidNumberLine(iCurrentNum, sGrid, bShowPosLeft);
		if (j < 2) {PrintMidJoinLine();}
	}
	PrintFooter();
}
void DisplaySudoku::PrintHeader()
{
	cout << m_cTopLeft;
	for (int i = 0; i < 3; i++)
	{
		cout << m_cTop << m_cTopMidSng << m_cTop << m_cTopMidSng << m_cTop;
		if (i < 2) {cout << m_cTopMidDbl;}
	}
	cout << m_cTopRight << endl;
}
void DisplaySudoku::PrintMidNumberLine(int& iCurrNum, SudokuGrid& sGrid, bool bDrawPosLeft)
{
	int iFore = 0;
	for (int i = 0; i < 3; i++)
	{
		cout << m_cMidOut;
		for (int j = 0; j < 3; j++) 
		{
			
			if (sGrid.GetSquare(iCurrNum)->GetNum() > 0 || bDrawPosLeft == true)
			{
				if (sGrid.GetSquare(iCurrNum)->GetIsUserNum() == false) 
					{iFore = 15;} //white
				else
				{
					if (sGrid.GetSquare(iCurrNum)->GetIsPreviousUserNum() == true)
						{iFore = 11;} //blue
					else
						{iFore = 12;} //red
				}
				if (sGrid.GetSquare(iCurrNum)->GetNum() == 0 && bDrawPosLeft == true)
				{
					if (sGrid.GetSquare(iCurrNum)->GetPossibleNumsRemaining() == 2)
						{iFore = 13;}
					else
						{iFore = 14;}
				}
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), iFore + 0 * 16);
				if (bDrawPosLeft == false)
					{cout << sGrid.GetSquare(iCurrNum)->GetNum();}
				else
					{cout << sGrid.GetSquare(iCurrNum)->GetPossibleNumsRemaining();}
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15 + 0 * 16);
			}
			else
				{cout << " ";}
			if (j < 2) {cout << m_cMid;}
			iCurrNum++;
		}
		//cout << cMid;
	}
	cout << m_cMidOut << endl;
}
void DisplaySudoku::PrintMid()
{
	cout << m_cMidLeft;
	for (int i = 0; i < 3; i++)
	{
		cout << m_cMidsMid << m_cMidSng << m_cMidsMid << m_cMidSng << m_cMidsMid;
		if (i < 2) {cout << m_cMidDbl;}
	}
	cout << m_cMidRight << endl;
}
void DisplaySudoku::PrintMidJoinLine()
{
	cout << m_cJoinLeft;
	for (int i = 0; i < 3; i++)
	{
		cout << m_cTop << m_cJoinSng << m_cTop << m_cJoinSng << m_cTop;
		if (i < 2) {cout << m_cJoinDbl;}
	}
	cout << m_cJoinRight << endl;
}
void DisplaySudoku::PrintFooter()
{
	cout << m_cBotLeft;
	for (int i = 0; i < 3; i++)
	{
		cout << m_cTop << m_cBotMidSng << m_cTop << m_cBotMidSng << m_cTop;
		if (i < 2) {cout << m_cBotMidDbl;}
	}
	cout << m_cBotRight << endl;
}