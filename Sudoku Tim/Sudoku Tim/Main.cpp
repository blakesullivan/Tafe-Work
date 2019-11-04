#include <iostream>
#include <fstream>
#include <windows.h>

using namespace std;

struct sudokuSquare
{
	int iNum;
	bool bIsUserNum;
	bool bIsEmpty;
	bool bPreviousUserNum;
	int iPossibleNumsRemaining;
	int iRow;
	int iCol;
	int iSubGridNum;
	bool abNumbersLeft[10];
};

sudokuSquare aSquare[81];

void SetupSquares();
void DrawSudoku(bool bDrawPos = false);
bool StartSolver();
bool CheckExplicit();
bool CheckImplicit();
int FigureOutG(int);
bool CheckExplicitPairs();
bool CompareThePair(int iFS, int iSS);
void RemovePairs(char cType, int iFirst, int iSecond);
void UpdatePossibleNums(int i);


int main()
{
	bool bExit = true;
	char cStop;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15 + 0 * 16);
	SetupSquares(); // Load Data and Setup data;

	do
	{
		

		DrawSudoku();
		cin.get();
		//cin >> cStop;
		bExit = StartSolver();
		//DrawSudoku(true);



		//bExit = false;
	}
	while (bExit == false);
}
bool CheckImplicit()
{
	//Check Implicit works by finding an empty square and then checking all of the squares around it in it's sub grid.
	//It checks one number at a time, from all of the numbers still available to the square. It checks if all the other squares
	//Have removed that number as a possibility. If the 3 squares in the columns and rows around the test square have
	//Removed that number as a possibility, it adds that number to the square, as it is the only number that can possibily go there.

	bool bKeepTesting = true;
    int iCheckCol = 0;
    int iCheckRow = 0;
    int iCheckGrid = 0;

    for (int i = 0; i < 81; i++) //FOR i (0 TO 80) 
	{   
		if (aSquare[i].bIsEmpty == true && bKeepTesting == true)
		{
			for (int iNum = 1; iNum < 10; iNum++)
			{
				if (aSquare[i].abNumbersLeft[iNum] == true)
				{
					iCheckRow = 0;
					iCheckCol = 0;
					iCheckGrid = 0;

					for (int j = 0; j < 81;	j++) 
					{	
						if (j != i)
						{	
							if (aSquare[j].iRow == aSquare[i].iRow && aSquare[j].abNumbersLeft[iNum] == false)
							{		
								iCheckRow++;
							}
							if (aSquare[j].iCol == aSquare[i].iCol && aSquare[j].abNumbersLeft[iNum] == false)
							{
								iCheckCol++;
							}
							if (aSquare[j].iSubGridNum == aSquare[i].iSubGridNum && aSquare[j].abNumbersLeft[iNum] == false)
							{
								iCheckGrid++;
							}
						}
					}

					if (iCheckRow == 8 || iCheckCol == 8 || iCheckGrid == 8)
					{
						for (int j = 1; j < 10; j++)
						{
							if (j != iNum) {aSquare[i].abNumbersLeft[j] = false;}
						}

						aSquare[i].iNum = iNum;
						//aSquare[i].iPossibleNumsRemaining = 1;
						UpdatePossibleNums(i);
						aSquare[i].bIsEmpty = false;
						aSquare[i].bIsUserNum = true;
						bKeepTesting = false;
						cout <<  "Implicitly solved.";
						break;
					}
				}
			}
		}
	}
    return bKeepTesting;
}



bool CheckExplicit()
{
	//Check Explicit works by finding an empty square and checking the row, column
	// and sub grid it's in for numbers. Any number it finds is then ruled out as a possible
	//number for this square. If, at the end of checking the square, there is only 1
	// possibility left, that square is set to that number.
	
	bool bKeepTesting = true;
	
	for (int i = 0; i < 81; i++) //FOR i (0 TO 80)
	{	
		if (aSquare[i].bIsEmpty == true && bKeepTesting == true)
		{	
			for (int j = 0; j < 81; j++) 
			{	
				if (i != j)
				{
					if (aSquare[i].iCol == aSquare[j].iCol)
					{
						if (aSquare[j].bIsEmpty == false)
						{
							aSquare[i].abNumbersLeft[aSquare[j].iNum] = false;
						}
					}

					if (aSquare[i].iRow == aSquare[j].iRow)
					{
						if (aSquare[j].bIsEmpty == false)
						{
							aSquare[i].abNumbersLeft[aSquare[j].iNum] = false;
						}
					}

					if (aSquare[i].iSubGridNum == aSquare[j].iSubGridNum)
					{
						if (aSquare[j].bIsEmpty == false)
						{
							aSquare[i].abNumbersLeft[aSquare[j].iNum] = false;
						}
					}
				}
			}

			int iOnlyNum = 0;

			for (int j = 1; j < 10; j++)
			{
				if (aSquare[i].abNumbersLeft[j] == true)
					iOnlyNum = j;	
			}
			
			UpdatePossibleNums(i);

			if (aSquare[i].iPossibleNumsRemaining == 1)
			{
				aSquare[i].iNum = iOnlyNum;
				aSquare[i].bIsEmpty = false;
				aSquare[i].bIsUserNum = true;
				bKeepTesting = false;
				cout << "Explicitly solved";
			}
		}
		if (bKeepTesting == false)
		{
			break;
		}	
	}
	return bKeepTesting;
}



bool StartSolver()
{
	bool bKeepTesting = true;

	for (int i = 0; i < 81; i++)
	{
		if (aSquare[i].bIsUserNum == true)
			{aSquare[i].bPreviousUserNum = true;}
	}

	bKeepTesting = CheckExplicit();

	if (bKeepTesting == true)
	{bKeepTesting = CheckImplicit();}

	if (bKeepTesting == true)
	{bKeepTesting = CheckExplicitPairs();}

	DrawSudoku(true);

	//CheckExplicitPairs()

	for (int i = 0; i < 81; i++)
	{
		if (aSquare[i].bIsEmpty == true)
			aSquare[i].iPossibleNumsRemaining = 9;
	}

	if (bKeepTesting == true)
	{
		int iCount = 0;
		for (int i = 0; i < 81; i++)
		{
			if (aSquare[i].bIsEmpty == true)
				iCount = iCount + 1;
		}
		
		if (iCount > 0)
			cout << "No new square found, unsolvable!";
		else
			cout << "Puzzle solved!";
	}

	return bKeepTesting;
}


void DrawSudoku(bool bDrawPos)
{
	int iFore = 0;
	int i = 80;
	cout << endl;
	for (int y = 0;  y < 9; y++)
	{
		for (int x = 0; x < 9; x++)
		{
			if (aSquare[i].bIsUserNum == false) 
				{iFore = 15;} //white
			else
			{
				if (aSquare[i].bPreviousUserNum == true)
				{iFore = 11;} //blue
				else
				{iFore = 12;} //red
			}
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), iFore + 0 * 16);
			if (bDrawPos == true)
			{cout << aSquare[i].iPossibleNumsRemaining;}
			else
			{cout << aSquare[i].iNum;}
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15 + 0 * 16);
			cout << " ";
			i--;
		}
		cout << endl;
	}
}

void SetupSquares()
{
	int c = 0;
    int r = 0;
    int g = 0;

    for (int i = 0; i < 81; i++)
    {
        aSquare[i].bIsEmpty = true;
        aSquare[i].bIsUserNum = false;
        aSquare[i].bPreviousUserNum = false;
        aSquare[i].iCol = c;
        aSquare[i].iNum = 0;
        aSquare[i].iPossibleNumsRemaining = 9;
        aSquare[i].iRow = r;
        aSquare[i].iSubGridNum = FigureOutG(i);
        
        for (int j = 0; j < 10; j++)
        {
            aSquare[i].abNumbersLeft[j] = true;
        }

        if (c < 8)
        {
            c = c + 1; 
        }
        else 
        {
            c = 0; 
            r = r + 1;
		}
    }

    int i = 80;

    ifstream sudokugame("sudoku.txt");

    for (int y = 8; y > -1; y--) // Start on top row
    {
        for (int x = 0; x < 9; x++) // Start First Coloum
        {
            sudokugame >> aSquare[i].iNum;

			if (aSquare[i].iNum > 0)
			{
				aSquare[i].bIsEmpty = false;
				aSquare[i].iPossibleNumsRemaining = 1;
				
				for (int j = 0; j < 10; j++)
				{
					if (j != aSquare[i].iNum)
					{
						aSquare[i].abNumbersLeft[j] = false;
					}
				}
			}
			i--;
		}
	}
}

bool CheckExplicitPairs()
{
	bool bKeepTesting = true;
	bool bReturnKeepTesting = true;
	
	for (int i = 0; i < 81; i++)
	{
		if (aSquare[i].bIsEmpty == true)
		{
			if (aSquare[i].iPossibleNumsRemaining == 2)
			{
				for (int j = 0; j < 81; j++)
				{
					if (j != i)
					{
						if (aSquare[j].iRow == aSquare[i].iRow)
						{
							if (aSquare[j].iPossibleNumsRemaining == 2)
							{
								bKeepTesting = !CompareThePair(i, j);
							}
						}
						if (aSquare[j].iCol == aSquare[i].iCol)
						{
							if (aSquare[j].iPossibleNumsRemaining == 2)
							{	
								bKeepTesting = !CompareThePair(i, j);
							}
						}
						if (aSquare[j].iSubGridNum == aSquare[i].iSubGridNum)
						{
							if (aSquare[j].iPossibleNumsRemaining == 2)
							{
								bKeepTesting = !CompareThePair(i, j);
							}
						}
					}

					if (bKeepTesting == false && bReturnKeepTesting == true)
					{
						bReturnKeepTesting = false;
						cout << "Explicit Pairs found Updating Grid.";
					}	
				}
			}
		}
	}
	return bReturnKeepTesting;
}


int FigureOutG(int i)
{
	int g;

	if (i == 0 || i == 1 || i == 2 || i == 9 || i == 10 || i == 11 || i == 18 || i == 19 || i == 20)
		g = 0;
	else if (i == 3 || i == 4 || i == 5 || i == 12 || i == 13 || i == 14 || i == 21 || i == 22 || i == 23) 
		g = 1;
	else if (i == 6 || i == 7 || i == 8 || i == 15 || i == 16 || i == 17 || i == 24 || i == 25 || i == 26) 
		g = 2;
	else if (i == 27 || i == 28 || i == 29 || i == 36 || i == 37 || i == 38 || i == 45 || i == 46 || i == 47) 
		g = 3;
	else if (i == 30 || i == 31 || i == 32 || i == 39 || i == 40 || i == 41 || i == 48 || i == 49 || i == 50) 
		g = 4;
	else if (i == 33 || i == 34 || i == 35 || i == 42 || i == 43 || i == 44 || i == 51 || i == 52 || i == 53) 
		g = 5;
	else if (i == 54 || i == 55 || i == 56 || i == 63 || i == 64 || i == 65 || i == 72 || i == 73 || i == 74)
		g = 6;
	else if (i == 57 || i == 58 || i == 59 || i == 66 || i == 67 || i == 68 || i == 75 || i == 76 || i == 77)
		g = 7;
	else if (i == 60 || i == 61 || i == 62 || i == 69 || i == 70 || i == 71 || i == 78 || i == 79 || i == 80)
		g = 8;
	return  g;
}


bool CompareThePair(int iFS, int iSS)
{
	bool bMatch = false;
	
	int iFN = 0;
	int iSN = 0;

	for (int i = 1; i < 10; i++)
	{
		if (aSquare[iFS].abNumbersLeft[i] == true)
		{	
			if (iFN == 0)
			{iFN = i;}
			else
			{iSN = i;}
		}
	}
	if (aSquare[iSS].abNumbersLeft[iFN] == true && aSquare[iSS].abNumbersLeft[iSN] == true)
	{
		if (aSquare[iFS].iRow == aSquare[iSS].iRow)
		{RemovePairs('r', iFS, iSS);}
		if (aSquare[iFS].iCol == aSquare[iSS].iCol)
		{RemovePairs('c', iFS, iSS);}
		if (aSquare[iFS].iSubGridNum == aSquare[iSS].iSubGridNum) 
		{RemovePairs('g', iFS, iSS);}
		bMatch = true;
	}
	return bMatch;
}


void RemovePairs(char cType, int iFirst, int iSecond)
{
	for (int i = 0; i < 81; i++)
	{
		if (i != iFirst && i != iSecond)
		{		
			if (cType == 'r')
			{	
				if (aSquare[i].iRow == aSquare[iFirst].iRow)
				{
					for (int j = 1; j < 10; j++) // (1 TO 10)
					{
						if (aSquare[iFirst].abNumbersLeft[j] == true)
						{
							aSquare[i].abNumbersLeft[j] = false;
						}
					}
				}
				else if (cType == 'c')
				{
					if (aSquare[i].iCol == aSquare[iFirst].iCol)
					{
						for (int j = 1; j < 10; j++)
						{
							if (aSquare[iFirst].abNumbersLeft[j] == true)
							{
								aSquare[i].abNumbersLeft[j] = false;
							}
						}
					}
				}
				else if (cType == 'g')
				{
					if (aSquare[i].iSubGridNum == aSquare[iFirst].iSubGridNum)
					{
						for (int j = 1; j < 10; j++) 
						{
							if (aSquare[iFirst].abNumbersLeft[j] == true)
							{
								aSquare[i].abNumbersLeft[j] = false;
							}
						}
					}
				}
			}
		}
		UpdatePossibleNums(i);
	}
}

void UpdatePossibleNums(int i)
{	
	aSquare[i].iPossibleNumsRemaining = 9;

	for (int j = 1; j < 10; j++)
	{
		if (aSquare[i].abNumbersLeft[j] == false)
			aSquare[i].iPossibleNumsRemaining--;	
	}
}

