//Blake Sullivan - Manager.cpp
#include "stdafx.h"
#include "Manager.h"

Manager::Manager()
{
	m_sGrid.Init();
	m_ResultGrid.Init();
	m_PlayGrid.Init();
	m_iPuzzleNum = 0;
	m_iFileType = ftText;
	//RunSudoku();
}

void Manager::LoadSudoku(int puzNum)
{
	//bool bExit = false, bEndProg = false; string sAgain = "";
	//do
	//{
		m_iPuzzleNum = puzNum;
		SetupSquares();
		//m_Display.DrawSudoku(m_PlayGrid);
		//do
		//{
		//bExit = 
		//if (m_iFileType != ftDataBase)
		//{
			RunSolver();
		//}
		//}while (bExit == false);
		//m_Display.DrawSudoku(m_sGrid);
		//RunGame();

		/*if (m_iFileType == ftText)
			{m_TF.WriteFile(&m_PlayGrid);}
		else if (m_iFileType == ftBinary)
		{
			string sFN = ""; char buffer[1] = {' '};
			sFN = itoa(m_iPuzzleNum, buffer, 10);
			m_BF.WriteFile(&m_PlayGrid, sFN);
		}
		else if (m_iFileType == ftDataBase)
		{
			string sPN = ""; char buffer[1] = {' '};
			sPN = itoa(m_iPuzzleNum, buffer, 10);
			m_ADO.OutputCurrent(&m_PlayGrid, sPN, "1");
		}*/

		//CompareResults();

		/*cout << "Play Again? (y/n)\n";
		getline(cin, sAgain);
		if (sAgain[0] == 'y' || sAgain[0] == 'Y')
			{bEndProg = false;}
		else
			{bEndProg = true;}*/

	//}while (bEndProg == false);
}

bool Manager::RunSolver()
{
	bool bKeepTesting = true, bExit = false;

	//cout << "Press [Enter] to start Solver.";
	//cin.get();

	do
	{
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
			/*if (iCount > 0)
				{cout << "No new square found, unsolvable!\n";}
			else
				{cout << "Puzzle solved!\n";}*/
		}
		
	}while (bExit == false);
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
		if (m_sGrid(i)->GetIsEmpty() == true && bKeepTesting == true)
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
				if (m_sGrid(i)->GetNumbersLeft(j) == true)
					{iOnlyNum = j;}
			}

			m_sGrid.UpdatePossibleNums(i);

			if (m_sGrid(i)->GetPossibleNumsRemaining() == 1)
			{
				m_sGrid.SetSquare(i, iOnlyNum, true);
				bKeepTesting = false;
				//cout << "Explicitly solved.\n";
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
		if (m_sGrid(i)->GetIsEmpty() == true && bKeepTesting == true)
		{
			for (int iNum = 1; iNum < 10; iNum++)
			{
				if (m_sGrid(i)->GetNumbersLeft(iNum) == true)
				{
					iCheckRow = 0; iCheckCol = 0; iCheckGrid = 0;
					for (int j = 0; j < MCS_IMAXSQUARES; j++)
					{
						if (j != i)
						{
							if (m_sGrid.CheckRow(i, j) == true && m_sGrid(j)->GetNumbersLeft(iNum) == false)
								{iCheckRow++;}
							if (m_sGrid.CheckCol(i, j) == true && m_sGrid(j)->GetNumbersLeft(iNum) == false)
								{iCheckCol++;}
							if (m_sGrid.CheckGrid(i, j) == true && m_sGrid(j)->GetNumbersLeft(iNum) == false)
								{iCheckGrid++;}
						}
					}
					if (iCheckRow == 8 || iCheckCol == 8 || iCheckGrid == 8)
					{
						m_sGrid.SetSquare(i, iNum, true);
						bKeepTesting = false;
						//cout << "Implicitly solved.\n";
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
		if (m_sGrid(i)->GetIsEmpty() == true)
		{
			if (m_sGrid(i)->GetPossibleNumsRemaining() == 2)
			{
				for (int j = 0; j < MCS_IMAXSQUARES; j++)
				{
					if (j != i)
					{
						if (m_sGrid.CheckRow(i, j) == true)
						{
							if (m_sGrid(j)->GetPossibleNumsRemaining() == 2)
							{
								bStopTesting = m_sGrid.CompareThePair(i, j);
							}
						}
						if (m_sGrid.CheckCol(i, j) == true)
						{
							if (m_sGrid(j)->GetPossibleNumsRemaining() == 2)
							{
								bStopTesting = m_sGrid.CompareThePair(i, j);
							}
						}
						if (m_sGrid.CheckGrid(i, j) == true)
						{
							if (m_sGrid(j)->GetPossibleNumsRemaining() == 2)
							{
								bStopTesting = m_sGrid.CompareThePair(i, j);
							}
						}
					}

					if (bStopTesting == true && bKeepTesting == true)
					{
						bKeepTesting = false;
						//cout << "Pair found, updating grid!\n";
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
	char buffer[10] = {' ',' ',' ',' ',' ',' ',' ',' ',' ',' '};
	sPuzNum = itoa(m_iPuzzleNum, buffer, 10);
	m_TF.LoadFile(&m_sGrid, sPuzNum);
	m_TF.LoadFile(&m_PlayGrid, sPuzNum);
	/*do
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
	}while (bExit == false);*/
	
	/*bExit = false;
	string sFileType = ""; int iFT = 0;
	do
	{
		cout << "\nWhat file system do you want to read to and write from:\n 1. Text\n 2. Binary\n 3. Access Database\n\nPlease enter the number of the option: ";
		getline(cin, sFileType);
		iFT = atoi(sFileType.c_str());
		if (iFT > 0 && iFT < 4) 
		{
			m_iFileType = iFT;
			bExit = true;
		}
	}while (bExit == false);

	if (m_iFileType == ftText)
	{
		m_TF.LoadFile(&m_sGrid, sPuzNum);
		m_TF.LoadFile(&m_PlayGrid, sPuzNum);
	}
	else if (m_iFileType == ftBinary)
	{
		m_BF.LoadFile(&m_sGrid, sPuzNum);
		m_TF.LoadFile(&m_PlayGrid, sPuzNum);
	}
	else if (m_iFileType == ftDataBase)
	{
		m_ADO.SetupPuzzle(&m_sGrid, "Results", sPuzNum);
		m_ADO.SetupPuzzle(&m_PlayGrid, "Puzzle", sPuzNum);
	}*/
}

void Manager::CompareResults()
{
	string sInput; bool bCompare = true;
	/*cout << "Do you want to compare the Result to the Puzzle? (y/n)\n";
	getline(cin, sInput);
	if (sInput[0] == 'y' || sInput[0] == 'Y')
		{bCompare = true;}
	else
		{bCompare = false;}*/

	if (bCompare == true)
	{
		string sPuzName = "Result#";
		char buffer[1] = {' '};
		string sPuzNum = itoa(m_iPuzzleNum, buffer, 10);
		sPuzName.replace(sPuzName.find("#"), 1, sPuzNum);
		if (m_iFileType == ftText)
		{
			sPuzName += ".txt";
			//cout << "sPuzName: " << sPuzName << endl;
			m_TF.LoadFile(&m_sGrid, sPuzNum);
			m_TF.LoadFile(&m_ResultGrid, sPuzName);

			for (int i = 0; i < MCS_IMAXSQUARES; i++)
			{
				if (m_sGrid(i)->GetNum() != m_ResultGrid(i)->GetNum())
				{
					m_ResultGrid(i)->SetIsUserNum(true);
					//m_ResultGrid(i)->SetIsPreviousUserNum(true);
					m_ResultGrid(i)->SetForeColour(0);
				}
			}
		}
		/*else if (m_iFileType == ftBinary)
		{
			sPuzName += ".bin";
			//cout << "sPuzName: " << sPuzName << endl;
			m_BF.LoadFile(&m_sGrid, sPuzNum);
			m_BF.LoadFile(&m_ResultGrid, sPuzName);
		}
		else if (m_iFileType == ftDataBase)
		{
			m_ADO.SetupPuzzle(&m_sGrid, "Puzzle", sPuzNum);
			m_ADO.SetupPuzzle(&m_ResultGrid, "CurrentPuzzle", sPuzNum);
		}*/
		//cout << "Unsolved: " << endl;
		//m_Display.DrawSudoku(m_sGrid);
		//cout << "Solved: " << endl;
		//m_Display.DrawSudoku(m_ResultGrid);
	}
}

bool Manager::RunGame()
{
	bool bExit = false;
	/*int iRow = 0, iCol = 0;
	Square* pSquare;
	int iPlayOrSolve = 0, iEnterSquareOrBack = 0, iEnterNumOrHelpOrBack = 0;
	bool bSquareSelected = false;
	string sInput = "";
	string msg = "Incorrect Option";

	do
	{
		try
		{
			m_Display.DrawSudoku(m_PlayGrid);
			if (iPlayOrSolve == 0) //Option 1
			{
				cout << "Do you want to:\n 1. Play Sudoku\n 2. Have Puzzle Solved\n 3. Save And Exit\nPlease enter number of option: ";
				getline(cin, sInput);
				iPlayOrSolve = atoi(sInput.c_str());
				if (iPlayOrSolve < 1 || iPlayOrSolve > 3)
				{
					iPlayOrSolve = 0;
					throw msg;
				}
			}
			if (iPlayOrSolve == 1) //Play
			{
				if (iEnterSquareOrBack == 0) //Option 2
				{
					cout << "Do you want to:\n 1. Enter Square\n 2. Back\nPlease enter number of option: ";
					getline(cin, sInput);
					iEnterSquareOrBack = atoi(sInput.c_str());
					if (iEnterSquareOrBack < 1 || iEnterSquareOrBack > 2)
					{
						iEnterSquareOrBack = 0;
						throw msg;
					}
				}

				if (iEnterSquareOrBack == 1) //Enter Square
				{
					if (bSquareSelected == false)
					{
						GridLocInput(iRow, iCol);
						pSquare = m_PlayGrid(iRow, iCol);
						if (pSquare->GetIsEmpty() == false && pSquare->GetIsUserNum() == false)
						{
							cout << "This square cannot be selected as it has a Default number." << endl;
							iRow = 0; iCol = 0;
							bExit = false;
							bSquareSelected = false;
						}
						else
						{
							cout << "Square selected." << endl;
							bSquareSelected = true;
							pSquare->SetBackColour(ccSilver);
						}
					}
					else if (bSquareSelected == true)
					{
						if (iEnterNumOrHelpOrBack == 0)
						{
							cout << "Do you want to:\n 1. Enter Number\n 2. Help\n 3. Back\nPlease enter number of option: ";
							getline(cin, sInput);
							iEnterNumOrHelpOrBack = atoi(sInput.c_str());
							if (iEnterNumOrHelpOrBack < 1 || iEnterNumOrHelpOrBack > 3)
							{
								iEnterNumOrHelpOrBack = 0;
								throw msg;
							}
						}

						if (iEnterNumOrHelpOrBack == 1) //Enter Num
						{
							pSquare->SetNum(NumberInput());
							pSquare->SetIsUserNum(true);
							pSquare->SetForeColour(ccRed);
						}
						else if (iEnterNumOrHelpOrBack == 2) //Help
						{
							SolveSquare(iRow, iCol);
						}
						else if (iEnterNumOrHelpOrBack == 3) //Back
						{
							iRow = 0; iCol = 0;
							iEnterSquareOrBack = 0;
							bSquareSelected = false;
							pSquare->SetBackColour(ccBlack);
						}
						iEnterNumOrHelpOrBack = 0;
					}
				}
				else if (iEnterSquareOrBack == 2) //Back
				{
					iPlayOrSolve = 0;
					iEnterSquareOrBack = 0;
				}
			}
			else if (iPlayOrSolve == 2) //Solve
			{
				SolveSudoku();
				m_Display.DrawSudoku(m_PlayGrid);
				bExit = true;
			}
			else if (iPlayOrSolve == 3) //Exit
			{
				bExit = true;
			}
		}
		catch (bool exit)
		{
			bExit = exit;
		}
		catch (string msg)
		{
			cout << msg << endl;
			bExit = false;
		}
	}while (bExit == false);*/
	return bExit;
}

void Manager::GridLocInput(int& iRow, int& iCol)
{
	/*string sInput = "";
	try
	{
		cout << "Which square do you wish to input [Row, Col] eg. '3,6': ";
		getline(cin, sInput);
		GetGridPosFromInput(sInput, iRow, iCol);
		//cout << "Row: " << iRow << " Col: " << iCol << endl;
	}
	catch (string msg)
	{
		cout << msg << endl;
		cout << "Please enter as the format shown [Row,Column]: 1,2\n";
		throw false;
	}
	catch (int over)
	{
		cout << "Incorrect Row or Column, the incorrect number was: " << over << endl;
		throw false;
	}*/
}

void Manager::GetGridPosFromInput(string sInput, int& iRow, int& iCol)
{
	/*const string msg = "Incorrect format.";
	int tempRow = 0, tempCol = 0;

	if (sInput[1] != ',')
	{
		throw msg;
	}

	sscanf(sInput.c_str(), "%d,%d", &iRow, &iCol);

	if (iRow < 1 || iRow > 9)
		{throw iRow;}
	if(iCol < 1 || iCol > 9)
		{throw iCol;}*/
}


int Manager::NumberInput()
{
	int iInput = 0;
	/*string sInput = "";
	
	cout << "Enter number: ";
	getline(cin, sInput);

	iInput = atoi(sInput.c_str());
	if (iInput < 1 || iInput > 9)
	{
		string msg = "Number not within bounds.";
		throw msg;
		//iInput = 0;	
	}*/

	return iInput;
}

void Manager::SolveSudoku()
{
	for (int i = 0; i < 81; i++)
	{
		if (m_PlayGrid(i)->GetNum() != m_sGrid(i)->GetNum())
		{
			if (m_PlayGrid(i)->GetNum() != 0) //Means it's incorrect
			{
				m_PlayGrid(i)->SetForeColour(ccRed);
			}
			else //Means it hasn't been entered
			{
				m_PlayGrid(i)->SetNum(m_sGrid(i)->GetNum());
				m_PlayGrid(i)->SetIsUserNum(true);
				m_PlayGrid(i)->SetForeColour(ccBlue);
			}
		}
		else
		{
			if (m_PlayGrid(i)->GetIsUserNum() == true && m_PlayGrid(i)->GetNum() > 0) //Means number entered by player is correct
			{
				m_PlayGrid(i)->SetForeColour(ccGreen);
			}
		}
	}
}

void Manager::SolveSquare(int row, int col)
{
	if (m_PlayGrid(row, col)->GetNum() == 0)
	{
		//cout << "Entering number: " << m_sGrid(row, col)->GetNum() << endl;
		m_PlayGrid(row, col)->SetNum(m_sGrid(row, col)->GetNum());
		m_PlayGrid(row, col)->SetIsUserNum(true);
		m_PlayGrid(row, col)->SetForeColour(ccBlue);
	}
	else
	{
		if (m_PlayGrid(row, col)->GetNum() == m_sGrid(row, col)->GetNum())
		{
			//cout << "Number is correct." << endl;
			m_PlayGrid(row, col)->SetForeColour(ccGreen);
		}
		else
		{
			//cout << "Number is incorrect." << endl;
			m_PlayGrid(row, col)->SetForeColour(ccRed);
		}
	}
}

void Manager::SolveSquare(int index)
{
	if (m_PlayGrid(index)->GetNum() == 0)
	{
		//cout << "Entering number: " << m_sGrid(index)->GetNum() << endl;
		m_PlayGrid(index)->SetNum(m_sGrid(index)->GetNum());
		m_PlayGrid(index)->SetIsUserNum(true);
		m_PlayGrid(index)->SetForeColour(ccBlue);
	}
	else
	{
		if (m_PlayGrid(index)->GetNum() == m_sGrid(index)->GetNum())
		{
			//cout << "Number is correct." << endl;
			m_PlayGrid(index)->SetForeColour(ccGreen);
		}
		else
		{
			//cout << "Number is incorrect." << endl;
			m_PlayGrid(index)->SetForeColour(ccRed);
		}
	}
}

void Manager::SetComboNum(int n)
{
	m_iComboNum = n;
}
int Manager::GetComboNum()
{
	return m_iComboNum;
}
void Manager::SetGridNum(int index, int num)
{
	m_PlayGrid.SetSquare(index, num, true);
}
int Manager::GetGridNum(int index)
{
	return m_PlayGrid(index)->GetNum();
}

void Manager::SetCurrTB(int num)
{
	m_iCurrTB = num;
}
int Manager::GetCurrTB()
{
	return m_iCurrTB;
}

void Manager::WriteToFile()
{
	m_TF.WriteFile(&m_PlayGrid);
}

Square* Manager::GetSquare(int index)
{
	return m_PlayGrid(index);
}