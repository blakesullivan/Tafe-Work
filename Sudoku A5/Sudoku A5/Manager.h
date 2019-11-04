//Blake Sullivan - Manager.h
#ifndef MANAGER_H
#define MANAGER_H

#include "BinaryFile.h"
#include "TextFile.h"
#include "DisplaySudoku.h"
#include "SudokuGrid.h"

class Manager
{
private:
	const static int MCS_IMAXSQUARES = 81;
	DisplaySudoku m_Display;
	SudokuGrid m_sGrid;
	SudokuGrid m_ResultGrid;
	int m_iPuzzleNum;
	TextFile m_TF;
	BinaryFile m_BF;
	bool m_bIsTextFile;

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
	void CompareResults();
};

#endif