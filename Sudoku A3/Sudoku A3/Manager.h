//Blake Sullivan - Manager.h
#ifndef MANAGER_H
#define MANAGER_H

#include "MyFile.h"
#include "DisplaySudoku.h"
#include "SudokuGrid.h"

class Manager
{
private:
	const static int MCS_IMAXSQUARES = 81;
	DisplaySudoku m_Display;
	SudokuGrid m_sGrid;
	int m_iPuzzleNum;

public:
	Manager();
	void RunSudoku();
	bool RunSolver();

	bool CheckExplicit();
	bool CheckImplicit();
	bool CheckExplicitPairs();
	bool CheckImplicitPairs();

	void SetCheckVars(int i, int& iC1, int& iC2, int& iR1, int& iR2);

	void SetupSquares();
	void ReadInPuzzle(int iPN);
	string GetNumFromFull(string& sFull);
	void SetSquareFromFile(int i, string sNum);
	void PrintFinalPuzzle(int iPN);

};

#endif