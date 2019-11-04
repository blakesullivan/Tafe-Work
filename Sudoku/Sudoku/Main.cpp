//Blake Sullivan - Main.cpp

#include <windows.h>
#include <iostream>
//using std::cout;
//using std::cin;
//using std::endl;
#include <fstream>
//using std::fstream;
//using std::ifstream;
//using std::ofstream;
#include <string>
//using std::string;
using namespace std;

struct sudokuSquare
{
	int iNum;
	bool bIsUserNum;
	bool bIsEmpty;
	bool bIsPreviousUserNum;
	int iPossibleNumsRemaining;
	int iRow;
	int iCol;
	int iSubGridNum;
	bool abNumbersLeft[10];
};
sudokuSquare aSquare[81];

void DrawSudoku(bool = false);
void PrintHeader();
void PrintMidNumberLine(int&, bool = false);
void PrintMid();
void PrintMidJoinLine();
void PrintFooter();
sudokuSquare GetSquare(int);
void SetupSquares();
void ReadInPuzzle(int);
string GetNumFromFull(string&);
void SetSquareFromFile(int, string);
bool StartSolver();
int FigureOutG(int);
bool CheckExplicit();
void PrintFinalPuzzle();
bool CheckImplicit();
bool CheckExplicitPairs();
void RemovePairs(char cType, int iFirst, int iSecond);
bool CompareThePair(int iFS, int iSS);
void UpdatePossibleNums(int i);

int main()
{
	bool bExit = false, bEndProg = false; string sAgain = "";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15 + 0 * 16);
	cout << "Blakes' Sudoku" << endl;
	do
	{
		SetupSquares();
		do
		{
			DrawSudoku();
			bExit = StartSolver();
		} while (bExit == false);
		PrintFinalPuzzle();
		cout << "Play Again? (y/n)\n";
		getline(cin, sAgain);
		if (sAgain[0] == 'y' || sAgain[0] == 'Y')
			{bEndProg = false;}
		else
			{bEndProg = true;}
	} while (bEndProg == false);

	return 0;
}

void SetupSquares()
{
	int c = 0, r = 0, g = 0;
	for (int i = 0; i < 81; i++)
	{
		
		aSquare[i].bIsEmpty = true;
		aSquare[i].bIsUserNum = false;
		aSquare[i].bIsPreviousUserNum = false;
		aSquare[i].iCol = c;
		aSquare[i].iNum = 0;
		aSquare[i].iPossibleNumsRemaining = 9;
		aSquare[i].iRow = r;
		aSquare[i].iSubGridNum = FigureOutG(i);
		
		for (int j = 0; j < 10; j++)
			{aSquare[i].abNumbersLeft[j] = true;}

		if (c < 8) {c++;} else {c = 0; r++;} 	
	}

	int iPuzNum = 0; string sPuzNum = ""; bool bExit = false;
	do
	{
		cout << "Which puzzle do you want to do?\n 1. Rons 1\n 2. Rons 2\n 3. Rons 3\n 4. Rons 4\n 5. Rons 5\n\nPlease enter the number of the option: ";
		getline(cin, sPuzNum);
		iPuzNum = atoi(sPuzNum.c_str());
		if (iPuzNum < 0 || iPuzNum > 5)
		{
			cout << "\nInvalid puzle, please try again.\n\n";
			bExit = false;
		}
		else
			{bExit = true;}
	}while (bExit == false);
	ReadInPuzzle(iPuzNum);
}

int FigureOutG(int i)
{
	int g;
	if (i == 0 || i == 1 || i == 2 || i == 9 || i == 10 || i == 11 || i == 18 || i == 19 || i == 20)
	{g = 0;}
	else if (i == 3 || i == 4 || i == 5 || i == 12 || i == 13 || i == 14 || i == 21 || i == 22 || i == 23)
	{g = 1;}
	else if (i == 6 || i == 7 || i == 8 || i == 15 || i == 16 || i == 17 || i == 24 || i == 25 || i == 26)
	{g = 2;}
	else if (i == 27 || i == 28 || i == 29 || i == 36 || i == 37 || i == 38 || i == 45 || i == 46 || i == 47)
	{g = 3;}
	else if (i == 30 || i == 31 || i == 32 || i == 39 || i == 40 || i == 41 || i == 48 || i == 49 || i == 50)
	{g = 4;}
	else if (i == 33 || i == 34 || i == 35 || i == 42 || i == 43 || i == 44 || i == 51 || i == 52 || i == 53)
	{g = 5;}
	else if (i == 54 || i == 55 || i == 56 || i == 63 || i == 64 || i == 65 || i == 72 || i == 73 || i == 74)
	{g = 6;}
	else if (i == 57 || i == 58 || i == 59 || i == 66 || i == 67 || i == 68 || i == 75 || i == 76 || i == 77)
	{g = 7;}
	else if (i == 60 || i == 61 || i == 62 || i == 69 || i == 70 || i == 71 || i == 78 || i == 79 || i == 80)
	{g = 8;}
	return g;
}

void DrawSudoku(bool bShowPosLeft)
{
	int iCurrentNum = 0;
	
	PrintHeader();
	for (int j = 0; j < 3; j++)
	{
		
		for (int i = 0; i < 2; i++)
		{
			PrintMidNumberLine(iCurrentNum, bShowPosLeft);
			PrintMid();
		}
		PrintMidNumberLine(iCurrentNum, bShowPosLeft);
		if (j < 2) {PrintMidJoinLine();}
	}
	PrintFooter();
}

void PrintHeader()
{
	char cTopLeft = 201, cTop = 205, cTopMidSng = 209, cTopMidDbl = 203, cTopRight = 187;
	cout << cTopLeft;
	for (int i = 0; i < 3; i++)
	{
		cout << cTop << cTopMidSng << cTop << cTopMidSng << cTop;
		if (i < 2) {cout << cTopMidDbl;}
	}
	cout << cTopRight << endl;
}

void PrintMidNumberLine(int& iCNum, bool bDrawPosLeft)
{
	char cMidOut = 186, cMid = 179;
	int iFore = 0;
	for (int i = 0; i < 3; i++)
	{
		cout << cMidOut;
		for (int j = 0; j < 3; j++) 
		{
			
			if (GetSquare(iCNum).iNum > 0 || bDrawPosLeft == true)
			{
				if (GetSquare(iCNum).bIsUserNum == false) 
					{iFore = 15;} //white
				else
				{
					if (GetSquare(iCNum).bIsPreviousUserNum == true)
					{iFore = 11;} //blue
					else
					{iFore = 12;} //red
				}
				if (GetSquare(iCNum).iNum == 0 && bDrawPosLeft == true)
				{
					if (GetSquare(iCNum).iPossibleNumsRemaining == 2)
						{iFore = 13;}
					else
						{iFore = 14;}
				}
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), iFore + 0 * 16);
				if (bDrawPosLeft == false)
					{cout << GetSquare(iCNum).iNum;}
				else
					{cout << GetSquare(iCNum).iPossibleNumsRemaining;}
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15 + 0 * 16);
			}
			else
				{cout << " ";}
			if (j < 2) {cout << cMid;}
			iCNum++;
		}
		//cout << cMid;
	}
	cout << cMidOut << endl;
}

void PrintMid()
{
	char cMidLeft = 199, cMidSng = 197, cMidDbl = 215, cMidRight = 182, cTop = 196;
	cout << cMidLeft;
	for (int i = 0; i < 3; i++)
	{
		cout << cTop << cMidSng << cTop << cMidSng << cTop;
		if (i < 2) {cout << cMidDbl;}
	}
	cout << cMidRight << endl;
}

void PrintMidJoinLine()
{
	char cMidLeft = 204, cMidSng = 216, cMidDbl = 206, cMidRight = 185, cTop = 205;
	cout << cMidLeft;
	for (int i = 0; i < 3; i++)
	{
		cout << cTop << cMidSng << cTop << cMidSng << cTop;
		if (i < 2) {cout << cMidDbl;}
	}
	cout << cMidRight << endl;
}

void PrintFooter()
{
	char cBotLeft = 200, cBot = 205, cBotMidSng = 207, cBotMidDbl = 202, cBotRight = 188;
	cout << cBotLeft;
	for (int i = 0; i < 3; i++)
	{
		cout << cBot << cBotMidSng << cBot << cBotMidSng << cBot;
		if (i < 2) {cout << cBotMidDbl;}
	}
	cout << cBotRight << endl;
}

sudokuSquare GetSquare(int iNum)
{
	return aSquare[iNum];
}

void ReadInPuzzle(int iPuzNum)
{
	string sPuzName = "Puzzle#.txt";
	char buffer[1] = {' '};
	sPuzName.replace(sPuzName.find("#"), 1, itoa(iPuzNum, buffer, 10));
	ifstream puzzFile(sPuzName.c_str());
	string sFullRow = "";
	if (puzzFile.good())
	{
		//cout << "File is Good!" << endl;
		int k = 0;
		for (int i = 0; i < 9; i++)
		{
			puzzFile >> sFullRow;
			for (int j = 0; j < 9; j++)
			{
				SetSquareFromFile(k, GetNumFromFull(sFullRow));
				//cout << "GetSquare(i).iNum = " << GetSquare(k).iNum << endl;
				k++;
			}
		}
		//cout << sFullRow << endl;
		//cout << GetNumFromFull(sFullRow) << endl;
		//cout << sFullRow << endl;
	}
}

string GetNumFromFull(string& sFull)
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

void SetSquareFromFile(int i, string sNum)
{
	aSquare[i].iNum = atoi(sNum.c_str());
	if (aSquare[i].iNum > 0 ) 
	{
		aSquare[i].bIsEmpty = false; 
		aSquare[i].bIsUserNum = false;
		for (int j = 0; j < 10; j++)
			{if (j != aSquare[i].iNum) {aSquare[i].abNumbersLeft[j] = false;}}
		aSquare[i].iPossibleNumsRemaining = 1;
	}
}

bool StartSolver()
{
	cout << "Press [Enter] key to start Solver.";
	cin.get();
	bool bKeepTesting = true;

	for (int i = 0; i < 81; i++)
	{
		if (aSquare[i].bIsUserNum == true)
			{aSquare[i].bIsPreviousUserNum = true;}
	}

	bKeepTesting = CheckExplicit();
	if (bKeepTesting == true) {bKeepTesting = CheckImplicit();}
	if (bKeepTesting == true) {bKeepTesting = CheckExplicitPairs();} //bKeepTesting = CheckImplicitPairs();}
	
	for (int i = 0; i < 81; i++)
	{
		if (aSquare[i].bIsEmpty == true)
		{
			/*if (aSquare[i].iPossibleNumsRemaining == 0)
			{
				bKeepTesting = false;
				for (int j = 0; j < 10; j++)
					{aSquare[i].abNumbersLeft[j] = true;}
			}*/
			aSquare[i].iPossibleNumsRemaining = 9;
		}
	}

	if (bKeepTesting == true)
	{
		int iCount = 0;
		for (int i = 0; i < 81; i++)
		{
			if (aSquare[i].bIsEmpty == true)
			{iCount++;}
		}
		if (iCount > 0)
			{cout << "No new square found, unsolvable!\n";}
		else
			{cout << "Puzzle solved!\n";}
	}

	return bKeepTesting;
	//return false;
}

bool CheckExplicit()
{
	//Check Explicit works by finding an empty square and checking the row, column, and sub grid it's in for numbers.
	//Any number it finds is then ruled out as a possible number for this square. If, at the end of checking the square, there
	//is only 1 possibility left, that square is set to that number.
	bool bKeepTesting = true;
	for (int i = 0; i < 81; i++)
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
				} //end if i not j
			} //end for j

			int iOnlyNum = 0;
			for (int j = 1; j < 10; j++)
			{
				if (aSquare[i].abNumbersLeft[j] == true)
				/*{
					aSquare[i].iPossibleNumsRemaining--;
				}
				else*/
					{iOnlyNum = j;}
			}

			UpdatePossibleNums(i);

			if (aSquare[i].iPossibleNumsRemaining == 1)
			{
				aSquare[i].iNum = iOnlyNum;
				aSquare[i].bIsEmpty = false;
				aSquare[i].bIsUserNum = true;
				bKeepTesting = false;
				cout << "Explicitly solved.\n";
			}
		} //end if i empty
		if (bKeepTesting == false) {break;}
	} // end for i
	return bKeepTesting;
}

bool CheckImplicit()
{
	//Check Implicit works by finding an empty square and then checking all of the squares in it's row, column, and sub grid.
	//It checks one number at a time, from all of the numbers still available to the square. It checks if all the other squares
	//Have removed that number as a possibility. If the 8 squares in the columns, rows, or sub grid around the test square have
	//Removed that number as a possibility, it adds that number to the square, as it is the only number that can possibily go there.

	//Attempt 6
	bool bKeepTesting = true;
	int iCheckCol = 0, iCheckRow = 0, iCheckGrid = 0;

	for (int i = 0; i < 81; i++)
	{
		if (aSquare[i].bIsEmpty == true && bKeepTesting == true)
		{
			for (int iNum = 1; iNum < 10; iNum++)
			{
				if (aSquare[i].abNumbersLeft[iNum] == true)
				{
					iCheckRow = 0; iCheckCol = 0; iCheckGrid = 0;
					for (int j = 0; j < 81; j++)
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
							{if (j != iNum) {aSquare[i].abNumbersLeft[j] = false;}}
						aSquare[i].iNum = iNum;
						//aSquare[i].iPossibleNumsRemaining = 1;
						UpdatePossibleNums(i);
						aSquare[i].bIsEmpty = false;
						aSquare[i].bIsUserNum = true;
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

void PrintFinalPuzzle()
{
	cout << "Printing Result.\n";
	int r = 0, c = 0;
	ofstream resultFile("Result.txt");
	for (int i = 0; i < 81; i++)
	{
		resultFile << aSquare[i].iNum;
		if ((c+1) < 9) 
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
						//cout << "Explicit Pairs found, exiting function.\n";
						//return bKeepTesting;
					}
				}
			}
		}
	}
	//cout << "After Explicit Pairs\n";
	//DrawSudoku(true);
	return bReturnKeepTesting;
}

bool CompareThePair(int iFS, int iSS)
{
	bool bMatch = false;
	int iFN = 0, iSN = 0;
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
	//cout << "Removing Pairs from: " << cType << endl;
	//cout << "First Square Row: " << aSquare[iFirst].iRow << " Col: " << aSquare[iFirst].iCol << " Grid: " << aSquare[iFirst].iSubGridNum << endl;
	//cout << "Second Square Row: " << aSquare[iSecond].iRow << " Col: " << aSquare[iSecond].iCol << " Grid: " << aSquare[iSecond].iSubGridNum << endl;
	for (int i = 0; i < 81; i++)
	{
		if (i != iFirst && i != iSecond)
		{
			if (cType == 'r')
			{
				if (aSquare[i].iRow == aSquare[iFirst].iRow)
				{
					for (int j = 1; j < 10; j++)
					{
						if(aSquare[iFirst].abNumbersLeft[j] == true)
						{
							aSquare[i].abNumbersLeft[j] = false;
						}
					}
				}
			}
			else if (cType == 'c')
			{
				if (aSquare[i].iCol == aSquare[iFirst].iCol)
				{
					for (int j = 1; j < 10; j++)
					{
						if(aSquare[iFirst].abNumbersLeft[j] == true)
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
						if(aSquare[iFirst].abNumbersLeft[j] == true)
						{
							aSquare[i].abNumbersLeft[j] = false;
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
		{
			aSquare[i].iPossibleNumsRemaining--;
		}
	}
}

//bool CheckImplicitPairs()
//{
//	bool bKeepTesting = true;
//	for (int i = 0; i < 81; i++)
//	{
//		if (aSquare[i].bIsEmpty == true && aSquare[i].iPossibleNumsRemaining > 2)
//		{
//			for (int iFN = 1; iFN < 9; iFN++)
//			{
//				if (aSquare[i].abNumbersLeft[iFN] == true)
//				{
//					for (int iSN = iFN + 1; iSN < 10; iSN++)
//					{
//						if (aSquare[i].abNumbersLeft[iSN] == true)
//						{
//							if (true == FindMatchedRowPair(i, iFN, iSN))
//								{bKeepTesting = false;}
//							if (true == FindMatchedColPair(i, iFN, iSN))
//								{bKeepTesting = false;}
//							if (true == FindMatchedGridPair(i, iFN, iSN))
//								{bKeepTesting = false;}
//						}
//						if (bKeepTesting = false){break;}
//					}
//				}
//				if (bKeepTesting == false){break;}
//			}
//		}
//		if (bKeepTesting == false){break;}
//	}
//	if (bKeepTesting == false)
//	{
//		cout << "Implicit Pairs found!\n";
//	}
//	return bKeepTesting;
//}
//
//bool FindMatchedRowPair(int iCSquare, int iFN, int iSN)
//{
//	bool bFound = false;
//	int iCount = 0;
//	int iFoundSquare = 0;
//
//	for (int i = 0; i < 81; i++)
//	{
//		if (i != iCSquare && aSquare[i].iRow == aSquare[iCSquare].iRow)
//		{
//			if (aSquare[i].abNumbersLeft[iFN] == true && aSquare[i].abNumbersLeft[iSN] == true)
//			{
//				iCount++;
//				iFoundSquare = i;
//			}
//		}
//	}
//	if (iCount == 1)
//	{
//		bFound = true;
//		SetOnlyTwo(iCSquare, iFoundSquare, iFN, iSN);
//	}
//
//	return bFound;
//}
//
//bool FindMatchedColPair(int iCSquare, int iFN, int iSN)
//{
//	bool bFound = false;
//	int iCount = 0;
//	int iFoundSquare = 0;
//
//	for (int i = 0; i < 81; i++)
//	{
//		if (i != iCSquare && aSquare[i].iCol == aSquare[iCSquare].iCol)
//		{
//			if (aSquare[i].abNumbersLeft[iFN] == true && aSquare[i].abNumbersLeft[iSN] == true)
//			{
//				iCount++;
//				iFoundSquare = i;
//			}
//		}
//	}
//	if (iCount == 1)
//	{
//		bFound = true;
//		SetOnlyTwo(iCSquare, iFoundSquare, iFN, iSN);
//	}
//
//	return bFound;
//}
//
//bool FindMatchedGridPair(int iCSquare, int iFN, int iSN)
//{
//	bool bFound = false;
//	int iCount = 0;
//	int iFoundSquare = 0;
//
//	for (int i = 0; i < 81; i++)
//	{
//		if (i != iCSquare && aSquare[i].iSubGridNum == aSquare[iCSquare].iSubGridNum)
//		{
//			if (aSquare[i].abNumbersLeft[iFN] == true && aSquare[i].abNumbersLeft[iSN] == true)
//			{
//				iCount++;
//				iFoundSquare = i;
//			}
//		}
//	}
//	if (iCount == 1)
//	{
//		bFound = true;
//		SetOnlyTwo(iCSquare, iFoundSquare, iFN, iSN);
//	}
//	return bFound;
//}
//
//void SetOnlyTwo(int sFirst, int sSecond, int iFirst, int iSecond)
//{
//	for (int i = 0; i < 10; i++)
//	{
//		aSquare[sFirst].abNumbersLeft[i] = false;
//		aSquare[sSecond].abNumbersLeft[i] = false;
//	}
//	aSquare[sFirst].abNumbersLeft[iFirst] = true;
//	aSquare[sFirst].abNumbersLeft[iSecond] = true;
//	aSquare[sSecond].abNumbersLeft[iFirst] = true;
//	aSquare[sSecond].abNumbersLeft[iSecond] = true;
//
//	cout << "Setting Only Two. Matching Numbers: First: " << iFirst << " Second: " << iSecond << endl;
//	cout << "Search Square: Row: " << aSquare[sFirst].iRow << " Col: " << aSquare[sFirst].iCol << endl;
//	cout << "Search Square: Row: " << aSquare[sSecond].iRow << " Col: " << aSquare[sSecond].iCol << endl;
//}