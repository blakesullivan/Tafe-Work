//Blake Sullivan - Manager.cpp
#include "Manager.h"

Manager::Manager()
{
	m_sGrid.Init();
	m_Display.Init();
	m_iPuzzleNum = 0;
	RunSudoku();
}

void Manager::RunSudoku()
{
	bool bExit = false, bEndProg = false; string sAgain = "";
	do
	{
		SetupSquares();
		do
		{
			m_Display.DrawSudoku(m_sGrid);
			bExit = RunSolver();
		}while (bExit == false);
		PrintFinalPuzzle(m_iPuzzleNum);

		cout << "Play Again? (y/n)\n";
		getline(cin, sAgain);
		if (sAgain[0] == 'y' || sAgain[0] == 'Y')
			{bEndProg = false;}
		else
			{bEndProg = true;}

	}while (bEndProg == false);
}

bool Manager::RunSolver()
{
	bool bKeepTesting = true, bExit = false;

	cout << "Press [Enter] to start Solver.";
	cin.get();

	m_sGrid.UpdateUserNums();

	bKeepTesting = CheckExplicit();
	if (bKeepTesting == true) {bKeepTesting = CheckImplicit();}
	if (bKeepTesting == true) {bKeepTesting = CheckExplicitPairs();}

	m_sGrid.ResetPossibleNums();

	bExit = bKeepTesting;

	if (bExit == true)
	{
		int iCount = 0;
		iCount = m_sGrid.GetTotalEmptySquares();
		if (iCount > 0)
			{cout << "No new square found, unsolvable!\n";}
		else
			{cout << "Puzzle solved!\n";}
	}

	return bExit;
}

bool Manager::CheckExplicit()
{
	//Check Explicit works by finding an empty square and checking the row, column, and sub grid it's in for numbers.
	//Any number it finds is then ruled out as a possible number for this square. If, at the end of checking the square, there
	//is only 1 possibility left, that square is set to that number.
	bool bKeepTesting = true;
	int iOnlyNum = 0;
	for (int i = 0; i < MCS_IMAXSQUARES; i++)
	{
		if (m_sGrid.GetSquare(i)->GetIsEmpty() == true && bKeepTesting == true)
		{
			for (int j = 0; j < MCS_IMAXSQUARES; j++)
			{
				if (m_sGrid.CheckRow(i, j) == true)
				{
					m_sGrid.CheckToRemoveNum(i, j);
				}
				if (m_sGrid.CheckCol(i, j) == true)
				{
					m_sGrid.CheckToRemoveNum(i, j);
				}
				if (m_sGrid.CheckGrid(i, j) == true)
				{
					m_sGrid.CheckToRemoveNum(i, j);
				}
			}

			iOnlyNum = 0;
			for (int j = 1; j < 10; j++)
			{
				if (m_sGrid.GetSquare(i)->GetNumbersLeft(j) == true)
					{iOnlyNum = j;}
			}

			m_sGrid.UpdatePossibleNums(i);

			if (m_sGrid.GetSquare(i)->GetPossibleNumsRemaining() == 1)
			{
				m_sGrid.SetSquare(i, iOnlyNum, true);
				bKeepTesting = false;
				cout << "Explicitly solved.\n";
			}
		}
		if (bKeepTesting == false) {break;}
	}
	return bKeepTesting;
}
bool Manager::CheckImplicit()
{
	//Check Implicit works by finding an empty square and then checking all of the squares in it's row, column, and sub grid.
	//It checks one number at a time, from all of the numbers still available to the square. It checks if all the other squares
	//Have removed that number as a possibility. If the 8 squares in the columns, rows, or sub grid around the test square have
	//Removed that number as a possibility, it adds that number to the square, as it is the only number that can possibily go there.

	bool bKeepTesting = true;
	int iCheckCol = 0, iCheckRow = 0, iCheckGrid = 0;

	for (int i = 0; i < MCS_IMAXSQUARES; i++)
	{
		if (m_sGrid.GetSquare(i)->GetIsEmpty() == true && bKeepTesting == true)
		{
			for (int iNum = 1; iNum < 10; iNum++)
			{
				if (m_sGrid.GetSquare(i)->GetNumbersLeft(iNum) == true)
				{
					iCheckRow = 0; iCheckCol = 0; iCheckGrid = 0;
					for (int j = 0; j < MCS_IMAXSQUARES; j++)
					{
						if (j != i)
						{
							if (m_sGrid.CheckRow(i, j) == true && m_sGrid.GetSquare(j)->GetNumbersLeft(iNum) == false)
								{iCheckRow++;}
							if (m_sGrid.CheckCol(i, j) == true && m_sGrid.GetSquare(j)->GetNumbersLeft(iNum) == false)
								{iCheckCol++;}
							if (m_sGrid.CheckGrid(i, j) == true && m_sGrid.GetSquare(j)->GetNumbersLeft(iNum) == false)
								{iCheckGrid++;}
						}
					}
					if (iCheckRow == 8 || iCheckCol == 8 || iCheckGrid == 8)
					{
						m_sGrid.SetSquare(i, iNum, true);
						bKeepTesting = false;
						cout << "Implicitly solved.\n";
						break;
					}
				}
			}
		}
	}

	return bKeepTesting;
}
bool Manager::CheckExplicitPairs()
{
	bool bKeepTesting = true, bStopTesting = false;
	for (int i = 0; i < MCS_IMAXSQUARES; i++)
	{
		if (m_sGrid.GetSquare(i)->GetIsEmpty() == true)
		{
			if (m_sGrid.GetSquare(i)->GetPossibleNumsRemaining() == 2)
			{
				for (int j = 0; j < MCS_IMAXSQUARES; j++)
				{
					if (j != i)
					{
						if (m_sGrid.CheckRow(i, j) == true)
						{
							if (m_sGrid.GetSquare(j)->GetPossibleNumsRemaining() == 2)
							{
								bStopTesting = m_sGrid.CompareThePair(i, j);
							}
						}
						if (m_sGrid.CheckCol(i, j) == true)
						{
							if (m_sGrid.GetSquare(j)->GetPossibleNumsRemaining() == 2)
							{
								bStopTesting = m_sGrid.CompareThePair(i, j);
							}
						}
						if (m_sGrid.CheckGrid(i, j) == true)
						{
							if (m_sGrid.GetSquare(j)->GetPossibleNumsRemaining() == 2)
							{
								bStopTesting = m_sGrid.CompareThePair(i, j);
							}
						}
					}

					if (bStopTesting == true && bKeepTesting == true)
					{
						bKeepTesting = false;
						cout << "Pair found, updating grid!\n";
					}
				}
			}
		}
	}
	return bKeepTesting;
}

void Manager::SetupSquares()
{
	string sPuzNum = ""; bool bExit = false;
	do
	{
		cout << "Which puzzle do you want to do?\n 1. Rons 1\n 2. Rons 2\n 3. Rons 3\n 4. Rons 4\n 5. Rons 5\n\nPlease enter the number of the option: ";
		getline(cin, sPuzNum);
		m_iPuzzleNum = atoi(sPuzNum.c_str());
		if (m_iPuzzleNum < 0 || m_iPuzzleNum > 5)
		{
			cout << "\nInvalid puzle, please try again.\n\n";
			bExit = false;
		}
		else
			{bExit = true;}
	}while (bExit == false);
	ReadInPuzzle(m_iPuzzleNum);
}
void Manager::ReadInPuzzle(int iPN)
{
	string sPuzName = "Puzzle#.txt";
	char buffer[1] = {' '};
	sPuzName.replace(sPuzName.find("#"), 1, itoa(iPN, buffer, 10));
	ifstream puzzFile(sPuzName.c_str());
	string sFullRow = "";
	if (puzzFile.good())
	{
		int k = 0;
		for (int i = 0; i < 9; i++)
		{
			puzzFile >> sFullRow;
			for (int j = 0; j < 9; j++)
			{
				SetSquareFromFile(k, GetNumFromFull(sFullRow));
				k++;
			}
		}
	} 
}
string Manager::GetNumFromFull(string& sFull)
{
	string sReturn = "";
	if (sFull.find(",") > 0)
	{
		sReturn = sFull.substr(0, sFull.find(","));
		sFull = sFull.substr(sFull.find(",") + 1, sFull.length());
	}
	else
	{
		sReturn = sFull;
		sFull = "";
	}
	
	//cout << sFull << endl;
	return sReturn;
}
void Manager::SetSquareFromFile(int i, string sNum)
{
	int iNum = 0; bool bIsEmpty = true, bIsUserNum = false;
	iNum = atoi(sNum.c_str());
	m_sGrid.SetSquare(i, iNum, false);
}
void Manager::PrintFinalPuzzle(int iPN)
{
	cout << "Printing Result.\n";
	int r = 0, c = 0;
	
	string sResultName = "Result#.txt";
	char buffer[1] = {' '};
	sResultName.replace(sResultName.find("#"), 1, itoa(iPN, buffer, 10));

	ofstream resultFile(sResultName.c_str());
	for (int i = 0; i < MCS_IMAXSQUARES; i++)
	{
		resultFile << m_sGrid.GetSquare(i)->GetNum();
		if (c < 8) 
		{
			resultFile << ",";
			c++;
		} 
		else 
		{
			resultFile << endl;
			c = 0; 
			r++;
		}
	}
}