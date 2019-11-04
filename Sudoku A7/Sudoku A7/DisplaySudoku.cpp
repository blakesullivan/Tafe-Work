//Blake Sullivan - DisplaySudoku.cpp
#include "DisplaySudoku.h"

DisplaySudoku::DisplaySudoku()
{
	m_CC.SetTextColours(ccWhite, ccBlack);
	//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15 + 0 * 16);
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

	m_CC.DisplayColouredText("  1 2 3 4 5 6 7 8 9\n", ccDarkGreen, ccBlack);
	m_CC.SetTextColours(ccPurple, ccBlack);
	cout << " " << m_cTopLeft;
	for (int i = 0; i < 3; i++)
	{
		cout << m_cTop << m_cTopMidSng << m_cTop << m_cTopMidSng << m_cTop;
		if (i < 2) {cout << m_cTopMidDbl;}
	}
	cout << m_cTopRight << endl;
	m_CC.SetTextColours(ccWhite, ccBlack);
}
void DisplaySudoku::PrintMidNumberLine(int& iCurrNum, SudokuGrid& sGrid, bool bDrawPosLeft)
{
	int iFore = 0;
	m_CC.SetTextColours(ccDarkGreen, ccBlack);
	cout << ((iCurrNum / 9) + 1);
	for (int i = 0; i < 3; i++)
	{
		m_CC.SetTextColours(ccPurple, ccBlack);
		cout << m_cMidOut;
		for (int j = 0; j < 3; j++) 
		{
			iFore = sGrid(iCurrNum)->GetForeColour();
			if (sGrid(iCurrNum)->GetNum() == 0 && bDrawPosLeft == true)
			{
				if (sGrid(iCurrNum)->GetPossibleNumsRemaining() == 2)
					{iFore = ccPink;}
				else
					{iFore = ccYellow;}
			}
			m_CC.SetTextColours(iFore, sGrid(iCurrNum)->GetBackColour());
			if (sGrid(iCurrNum)->GetNum() > 0 || bDrawPosLeft == true)
			{
				/*if (sGrid(iCurrNum)->GetIsUserNum() == false) 
					{iFore = ccWhite;} //white
				else
				{
					if (sGrid(iCurrNum)->GetIsPreviousUserNum() == true)
						{iFore = ccBlue;} //blue
					else
						{iFore = ccRed;} //red
				}*/
				
				//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), iFore + 0 * 16);
				if (bDrawPosLeft == false)
					{cout << sGrid(iCurrNum)->GetNum();}
				else
					{cout << sGrid(iCurrNum)->GetPossibleNumsRemaining();}
				m_CC.Reset();
				//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15 + 0 * 16);
			}
			else
				{cout << " ";}
			m_CC.SetTextColours(ccPurple, ccBlack);
			if (j < 2) {cout << m_cMid;}
			m_CC.Reset();
			iCurrNum++;
		}
		//cout << cMid;
	}
	m_CC.SetTextColours(ccPurple, ccBlack);
	cout << m_cMidOut;
	m_CC.SetTextColours(ccDarkGreen, ccBlack);
	cout << (iCurrNum / 9) << endl;
	m_CC.Reset();
	
}
void DisplaySudoku::PrintMid()
{
	m_CC.SetTextColours(ccPurple, ccBlack);
	cout << " " << m_cMidLeft;
	for (int i = 0; i < 3; i++)
	{
		cout << m_cMidsMid << m_cMidSng << m_cMidsMid << m_cMidSng << m_cMidsMid;
		if (i < 2) {cout << m_cMidDbl;}
	}
	cout << m_cMidRight << endl;
	m_CC.Reset();
}
void DisplaySudoku::PrintMidJoinLine()
{
	m_CC.SetTextColours(ccPurple, ccBlack);
	cout << " " << m_cJoinLeft;
	for (int i = 0; i < 3; i++)
	{
		cout << m_cTop << m_cJoinSng << m_cTop << m_cJoinSng << m_cTop;
		if (i < 2) {cout << m_cJoinDbl;}
	}
	cout << m_cJoinRight << endl;
	m_CC.Reset();
}
void DisplaySudoku::PrintFooter()
{
	m_CC.SetTextColours(ccPurple, ccBlack);
	cout << " " << m_cBotLeft;
	for (int i = 0; i < 3; i++)
	{
		cout << m_cTop << m_cBotMidSng << m_cTop << m_cBotMidSng << m_cTop;
		if (i < 2) {cout << m_cBotMidDbl;}
	}
	cout << m_cBotRight << endl;
	m_CC.SetTextColours(ccDarkGreen, ccBlack);
	cout << "  1 2 3 4 5 6 7 8 9" << endl;
	m_CC.Reset();
}