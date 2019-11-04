//Blake Sullivan - Manager.h
#ifndef MANAGER_H
#define MANAGER_H

#include "TextFile.h"
#include "SudokuGrid.h"
#include <exception>

class Manager
{
private:
	enum fileType
	{
		ftText = 1,
		ftBinary = 2,
		ftDataBase = 3
	};
	const static int MCS_IMAXSQUARES = 81;
	SudokuGrid m_sGrid;
	SudokuGrid m_ResultGrid;
	SudokuGrid m_PlayGrid;
	int m_iPuzzleNum;
	TextFile m_TF;
	int m_iFileType;
	int m_iComboNum;
	int m_iCurrTB;

public:
	Manager();
	void LoadSudoku(int puzNum);
	bool RunSolver();
	bool RunGame();

	bool CheckExplicit();
	bool CheckImplicit();
	bool CheckExplicitPairs();
	bool CheckImplicitPairs();

	void SetCheckVars(int i, int& iC1, int& iC2, int& iR1, int& iR2);

	void SetupSquares();
	void CompareResults();

	void GridLocInput(int& iRow, int& iCol);
	void GetGridPosFromInput(string sInput, int& iRow, int& iCol);
	int NumberInput();
	void SolveSudoku();
	void SolveSquare(int row, int col);
	void SolveSquare(int num);

	void SetComboNum(int n);
	int GetComboNum();
	void SetGridNum(int index, int num);
	int GetGridNum(int index);

	void SetCurrTB(int num);
	int GetCurrTB();
	void WriteToFile();

	Square* GetSquare(int index);
};

#endif