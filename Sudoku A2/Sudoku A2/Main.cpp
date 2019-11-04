//Blake Sullivan - Main.cpp

#include <windows.h>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

enum Colours
{
	cBlue = 11,
	cRed = 12,
	cWhite = 15
};

//Paul Turners' Pseudo Code Methods
struct cell
{
	bool abPossibile[9];
	int iDisplayNum;
	bool bChangeOccurred;
	unsigned short usColour;
};
cell aSquare[9][9];

void ExclusionMethod(int iRowNum, int iColumnNum);
void InclusionMethod(int iRowNum, int iColumnNum);
void PairMethodPart1(int iRowNum, int iColumnNum);
void PairMethodPart2(int iRowNum, int iColumnNum);

bool CheckExistRow(int iRowNum, int iCheckNumber);
bool CheckNotExistRow(int iRowNum, int iColumnNum, int iCheckNum);
bool CheckExistCol(int iColumnNum, int iCheckNumber);
bool CheckNotExistCol(int iRowNum, int iColumnNum, int iCheckNum);
bool CheckExistBox(int iRowNum, int iColumnNum, int iCheckNumber);
bool CheckNotExistBox(int iRowNum, int iColumnNum, int iCheckNum);

void RowPairsPart1(int iRowNum, int iColumnNum);
void RowPairsPart2(int iRowNum, int iColumnNum);
void ColumnPairsPart1(int iRowNum, int iColumnNum);
void ColumnPairsPart2(int iRowNum, int iColumnNum);
void BoxPairsPart1(int iRowNum, int iColumnNum);
void BoxPairsPart2(int iRowNum, int iColumnNum);

void SetOnlyDoubles(int iRowA, int iColA, int iRowB, int iColB, int iFirstNum, int iSecondNum);
//End Paul Turners' Pseudo Code Methods
int FindRemainingPossibilities(int iRowNum, int iColumnNum);
void DrawSudoku();
void PrintHeader();
void PrintMidNumberLine(int&);
void PrintMid();
void PrintMidJoinLine();
void PrintFooter();
int RunSolver();
void SetupSquares();
void ReadInPuzzle(int iPuzNum);
string GetNumFromFull(string& sFull);
void SetSquareFromFile(int iRow, int iCol, string sNum);
void ChangeColours();
void PrintFinalPuzzle();

int main()
{
	int iExit = -1;
	bool bEndProg = false; string sAgain = "";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15 + 0 * 16);
	do
	{
		SetupSquares();
		do
		{
			DrawSudoku();
			ChangeColours();
			cin.get();
			cin.clear();
			iExit = RunSolver();
		} while (iExit != 0);
		PrintFinalPuzzle();
		cout << "Play Again? (y/n)\n";
		getline(cin, sAgain);
		if (sAgain[0] == 'y' || sAgain[0] == 'Y')
			{bEndProg = false;}
		else
			{bEndProg = true;}
	} while (bEndProg == false);
	system("PAUSE");
	return 0;
}

void SetupSquares()
{
	for (int r = 0; r < 9; r++)
	{
		for (int c = 0; c < 9; c++)
		{
			aSquare[r][c].bChangeOccurred = false;
			aSquare[r][c].iDisplayNum = 0;
			aSquare[r][c].usColour = cWhite;
			for (int i = 0; i < 9; i++)
				{aSquare[r][c].abPossibile[i] = true;}
		}
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

void ReadInPuzzle(int iPuzNum)
{
	string sPuzName = "Puzzle#.txt";
	char buffer[3] = {' ', ' ', ' '};
	sPuzName.replace(sPuzName.find("#"), 1, itoa(iPuzNum, buffer, 10));
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
				SetSquareFromFile(i, j, GetNumFromFull(sFullRow));
			}
		}
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
	
	return sReturn;
}

void SetSquareFromFile(int iRow, int iCol, string sNum)
{
	aSquare[iRow][iCol].iDisplayNum = atoi(sNum.c_str());
	if (aSquare[iRow][iCol].iDisplayNum > 0 ) 
	{
		for (int j = 0; j < 9; j++)
			{if (j != (aSquare[iRow][iCol].iDisplayNum - 1)) {aSquare[iRow][iCol].abPossibile[j] = false;}}
	}
}

void DrawSudoku()
{
	int iCurrentNum = 0;
	
	PrintHeader();
	for (int j = 0; j < 3; j++)
	{
		
		for (int i = 0; i < 2; i++)
		{
			PrintMidNumberLine(iCurrentNum);
			PrintMid();
		}
		PrintMidNumberLine(iCurrentNum);
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

void PrintMidNumberLine(int& iCNum)
{
	char cMidOut = 186, cMid = 179;
	int iCol = 0, iRow = 0;

	
	for (int i = 0; i < 3; i++)
	{
		cout << cMidOut;
		for (int j = 0; j < 3; j++) 
		{
			iRow = iCNum / 9;
			iCol = iCNum % 9;
			if (aSquare[iRow][iCol].iDisplayNum > 0)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), aSquare[iRow][iCol].usColour + 0 * 16);
				cout << aSquare[iRow][iCol].iDisplayNum;
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

void ChangeColours()
{
	for (int r = 0; r < 9; r++)
	{
		for (int c = 0; c < 9; c++)
		{
			if (aSquare[r][c].bChangeOccurred == true)
			{
				aSquare[r][c].bChangeOccurred = false;
				aSquare[r][c].usColour = cBlue;
			}
		}
	}
}

int RunSolver()
{
	int iCount = 0;
	for (int iRow = 0; iRow < 9; iRow++)
	{
		for (int iCol = 0; iCol < 9; iCol++)
		{
			if (aSquare[iRow][iCol].iDisplayNum == 0)
			{
				//cout << "Testing Row: " << iRow << " Col: " << iCol << " Num: " << aSquare[iRow][iCol].iDisplayNum << endl;
				ExclusionMethod(iRow, iCol);
				//cout << "After Exclusion: Row: " << iRow << " Col: " << iCol << " Num: " << aSquare[iRow][iCol].iDisplayNum << endl;
				InclusionMethod(iRow, iCol);
				//cout << "After Inclusion: Row: " << iRow << " Col: " << iCol << " Num: " << aSquare[iRow][iCol].iDisplayNum << endl;
				PairMethodPart1(iRow, iCol);
				//cout << "After Pair Method Part 1: Row: " << iRow << " Col: " << iCol << " Num: " << aSquare[iRow][iCol].iDisplayNum << endl;
				PairMethodPart2(iRow, iCol);
				//cout << "After Pair Method Part 2: Row: " << iRow << " Col: " << iCol << " Num: " << aSquare[iRow][iCol].iDisplayNum << endl;
				iCount++;
			}
		}
	}
	return iCount;
}

void ExclusionMethod(int iRowNum, int iColumnNum)
{
	for (int iNumber = 1; iNumber < 10; iNumber++)
	{
		if ((CheckExistRow(iRowNum, iNumber) || CheckExistCol(iColumnNum, iNumber) || CheckExistBox(iRowNum, iColumnNum, iNumber)) && aSquare[iRowNum][iColumnNum].abPossibile[iNumber - 1] == true)
		{
			aSquare[iRowNum][iColumnNum].abPossibile[iNumber-1] = false;
			aSquare[iRowNum][iColumnNum].bChangeOccurred = true;
		}
	}

	int iCount = 0, iOnlyNum = 0;
	for (int i = 0; i < 9; i++)
	{
		if (aSquare[iRowNum][iColumnNum].abPossibile[i] == true)
		{
			iCount++;
			iOnlyNum = i;
		}
	}
	if (iCount == 1)
	{
		cout << "Exlusion Solved!\n";
		aSquare[iRowNum][iColumnNum].iDisplayNum = iOnlyNum + 1;
		aSquare[iRowNum][iColumnNum].usColour = cRed;
	}
}

void InclusionMethod(int iRowNum, int iColumnNum)
{
	for (int iNumber = 1; iNumber < 10; iNumber++)
	{
		if (CheckNotExistRow(iRowNum, iColumnNum, iNumber) || CheckNotExistCol(iRowNum, iColumnNum, iNumber) || CheckNotExistBox(iRowNum, iColumnNum, iNumber))// && aSquare[iRowNum][iColumnNum].abPossibile[iNumber - 1] == true)
		{
			aSquare[iRowNum][iColumnNum].iDisplayNum = iNumber;
			for (int i = 0; i < 9; i++)
			{
				if (i != (iNumber - 1))
					{aSquare[iRowNum][iColumnNum].abPossibile[i] = false;}
			}
			aSquare[iRowNum][iColumnNum].bChangeOccurred = true;
			aSquare[iRowNum][iColumnNum].usColour = cRed;
			cout << "Inclusion Solved: " << iNumber << endl;
			break;
		}
	}
}

void PairMethodPart1(int iRowNum, int iColumnNum)
{
	if (FindRemainingPossibilities(iRowNum, iColumnNum) == 2)
	{
		RowPairsPart1(iRowNum, iColumnNum);
		ColumnPairsPart1(iRowNum, iColumnNum);
		BoxPairsPart1(iRowNum, iColumnNum);
	}
}

void PairMethodPart2(int iRowNum, int iColumnNum)
{
	RowPairsPart2(iRowNum, iColumnNum);
	ColumnPairsPart2(iRowNum, iColumnNum);
	BoxPairsPart2(iRowNum, iColumnNum);
}

bool CheckExistRow(int iRowNum, int iCheckNumber)
{
	bool bFlag = false;
	for (int iCol = 0; iCol < 9; iCol++)
	{
		if (aSquare[iRowNum][iCol].iDisplayNum == iCheckNumber)
		{
			bFlag = true;
		}
	}
	return bFlag;
}

bool CheckExistCol(int iColumnNum, int iCheckNumber)
{
	bool bFlag = false;
	for (int iRow = 0; iRow < 9; iRow++)
	{
		if (aSquare[iRow][iColumnNum].iDisplayNum == iCheckNumber)
		{
			bFlag = true;
		}
	}
	return bFlag;
}

bool CheckExistBox(int iRowNum, int iColumnNum, int iCheckNumber)
{
	int iBoxRow = iRowNum / 3;
	int iBoxCol = iColumnNum / 3;
	iBoxRow *= 3;
	iBoxCol *= 3;
	bool bFlag = false;

	for (int x = 0; x < 3; x++)
	{
		for (int y = 0; y < 3; y++)
		{
			if (aSquare[x+iBoxRow][y+iBoxCol].iDisplayNum == iCheckNumber)
			{
				bFlag = true;
			}
		}
	}
	return bFlag;
}

bool CheckNotExistRow(int iRowNum, int iColumnNum, int iCheckNum)
{
	bool bFlag = false;
	for (int x = 0; x < 9; x++)
	{
		if (x != iColumnNum && aSquare[iRowNum][x].abPossibile[iCheckNum -1] == true)
		{
			bFlag = true;
		}
	}
	return !bFlag;
}

bool CheckNotExistCol(int iRowNum, int iColumnNum, int iCheckNum)
{
	bool bFlag = false;
	for (int x = 0; x < 9; x++)
	{
		if (x != iRowNum && aSquare[x][iColumnNum].abPossibile[iCheckNum -1] == true)
		{
			bFlag = true;
		}
	}
	return !bFlag;
}

bool CheckNotExistBox(int iRowNum, int iColumnNum, int iCheckNum)
{
	int iBoxRow = iRowNum / 3;
	int iBoxCol = iColumnNum / 3;
	iBoxRow *= 3;
	iBoxCol *= 3;
	bool bFlag = false;
	
	for (int x = 0; x < 3; x++)
	{
		for (int y = 0; y < 3; y++)
		{
			if ((!((x+iBoxRow) == iRowNum && (y+iBoxCol) == iColumnNum)) && aSquare[x+iBoxRow][y+iBoxCol].abPossibile[iCheckNum-1] == true)
			{
				bFlag = true;
			}
		}
	}

	return !bFlag;
}

void RowPairsPart1(int iRowNum, int iColumnNum)
{
	for (int x = 0; x < 9; x++)
	{
		if (x != iColumnNum && FindRemainingPossibilities(iRowNum, x) == 2)
		{
			bool bFlag = true;
			for (int y = 0; y < 9; y++)
			{
				if (aSquare[iRowNum][iColumnNum].abPossibile[y] != aSquare[iRowNum][x].abPossibile[y])
				{
					bFlag = false;
				}
			}
			if (bFlag == true)
			{
				cout << "Removing Pairs from Row: " << iRowNum << " Col: " << iColumnNum << " MatchedCol: " << x << endl;
				//Go through all the other squares in the Row and remove these 2 numbers from their list of possibilities
				for (int a = 0; a < 9; a++)
				{
					if (a != iColumnNum && a != x && aSquare[iRowNum][a].iDisplayNum == 0)
					{
						for (int n = 0; n < 9; n++)
						{
							if (aSquare[iRowNum][iColumnNum].abPossibile[n] == true)
							{
								aSquare[iRowNum][a].abPossibile[n] = false;
							}
						}
					}
				}
			}
		}
	}
}

void RowPairsPart2(int iRowNum, int iColumnNum)
{
	for (int x = 0; x < 9; x++)
	{
		if (x != iColumnNum && aSquare[iRowNum][x].iDisplayNum == 0)
		{
			for (int a = 0; a < 8; a++)
			{
				for (int b = a+1; b < 9; b++)
				{
					if(aSquare[iRowNum][iColumnNum].abPossibile[a] == true && aSquare[iRowNum][iColumnNum].abPossibile[b] == true 
						&& aSquare[iRowNum][x].abPossibile[a] == true && aSquare[iRowNum][x].abPossibile[b] == true)
					{
						bool bFlag = true;
						for (int y = 0; y < 9; y++)
						{
							if (y != iColumnNum && y != x && aSquare[iRowNum][y].iDisplayNum == 0)
							{
								if (aSquare[iRowNum][y].abPossibile[a] == true || aSquare[iRowNum][y].abPossibile[b] == true)
								{
									bFlag = false;
								}
							}
						}
						if (bFlag == true)
						{
							//Remove all possibilities from these squares, except whatever a and b are
							SetOnlyDoubles(iRowNum, iColumnNum, iRowNum, x, a, b);
						}
					}
				}
			}
		}
	}
}

void ColumnPairsPart1(int iRowNum, int iColumnNum)
{
	for (int x = 0; x < 9; x++)
	{
		if (x != iRowNum && FindRemainingPossibilities(x, iColumnNum) == 2)
		{
			bool bFlag = true;
			for (int y = 0; y < 9; y++)
			{
				if (aSquare[iRowNum][iColumnNum].abPossibile[y] != aSquare[x][iColumnNum].abPossibile[y])
				{
					bFlag = false;
				}
			}
			if (bFlag == true)
			{
				cout << "Removing Pairs from Col: " << iColumnNum << " Row: " << iRowNum << " MatchedRow: " << x << endl;
				//Go through all the other squares in the Column and remove these 2 numbers from their list of possibilities
				for (int a = 0; a < 9; a++)
				{
					if (a != iRowNum && a != x && aSquare[a][iColumnNum].iDisplayNum == 0)
					{
						for (int n = 0; n < 9; n++)
						{
							if (aSquare[iRowNum][iColumnNum].abPossibile[n] == true)
							{
								aSquare[a][iColumnNum].abPossibile[n] = false;
							}
						}
					}
				}
			}
		}
	}
}

void ColumnPairsPart2(int iRowNum, int iColumnNum)
{
	for (int x = 0; x < 9; x++)
	{
		if (x != iRowNum && aSquare[x][iColumnNum].iDisplayNum == 0)
		{
			for (int a = 0; a < 8; a++)
			{
				for (int b = a+1; b < 9; b++)
				{
					if(aSquare[iRowNum][iColumnNum].abPossibile[a] == true && aSquare[iRowNum][iColumnNum].abPossibile[b] == true 
						&& aSquare[x][iColumnNum].abPossibile[a] == true && aSquare[x][iColumnNum].abPossibile[b] == true)
					{
						bool bFlag = true;
						for (int y = 0; y < 9; y++)
						{
							if (y != iRowNum && y != x && aSquare[y][iColumnNum].iDisplayNum == 0)
							{
								if (aSquare[y][iColumnNum].abPossibile[a] == true || aSquare[y][iColumnNum].abPossibile[b] == true)
								{
									bFlag = false;
								}
							}
						}
						if (bFlag == true)
						{
							//Remove all possibilities from these squares, except whatever a and b are
							SetOnlyDoubles(iRowNum, iColumnNum, x, iColumnNum, a, b);
						}
					}
				}
			}
		}
	}
}

void BoxPairsPart1(int iRowNum, int iColumnNum)
{
	int iBoxRow = iRowNum / 3;
	int iBoxCol = iColumnNum / 3;
	iBoxRow *= 3;
	iBoxCol *= 3;
	for (int x = 0; x < 3; x++)
	{
		for (int y = 0; y < 3; y++)
		{
			if(!(iBoxRow + x == iRowNum && iBoxCol + y == iColumnNum) && FindRemainingPossibilities(iBoxRow + x, iBoxCol + y) == 2)
			{
				bool bFlag = true;
				for (int a = 0; a < 9; a++)
				{
					if (aSquare[iRowNum][iColumnNum].abPossibile[a] != aSquare[iBoxRow+x][iBoxCol+y].abPossibile[a])
					{
						bFlag = false;
					}
				}
				if (bFlag == true)
				{
					cout << "Removing Pairs from GridRow: " << iBoxRow/3 << " GridCol: " << iBoxCol/3 << endl;
					cout << "Squares Row: " << iRowNum << " Col: " << iColumnNum << " MatchedRow: " << iBoxRow+x << " MatchedCol: " << iBoxCol+y << endl;
					//Go through all the other squares in the box and remove these 2 numbers from their list of possibilities
					for (int a = 0; a < 3; a++)
					{
						for (int b = 0; b < 3; b++)
						{
							if ((!(iBoxRow+a == iRowNum && iBoxCol+b == iColumnNum)) 
								&& (!(iBoxRow+a == iBoxRow+x && iBoxCol+b == iBoxCol+y))
								&& aSquare[iBoxRow+a][iBoxCol+b].iDisplayNum == 0)
							{
								for (int n = 0; n < 9; n++)
								{
									if (aSquare[iRowNum][iColumnNum].abPossibile[n] == true)
									{
										aSquare[iBoxRow+a][iBoxCol+b].abPossibile[n] = false;
									}
								}
							}
						}
					}
				}
			}
		}
	}
}

void BoxPairsPart2(int iRowNum, int iColumnNum)
{
	int iBoxRow = iRowNum / 3;
	int iBoxCol = iColumnNum / 3;
	iBoxRow *= 3;
	iBoxCol *= 3;
	for (int x = 0; x < 3; x++)
	{
		for (int y = 0; y < 3; y++)
		{
			if ((!(iBoxRow+x == iRowNum && iBoxCol+y == iColumnNum)) && aSquare[iBoxRow+x][iBoxCol+y].iDisplayNum == 0)
			{
				for (int a = 0; a < 8; a++)
				{
					for (int b = a+1; b < 9; b++)
					{
						if (aSquare[iRowNum][iColumnNum].abPossibile[a] == true && aSquare[iRowNum][iColumnNum].abPossibile[b] == true 
							&& aSquare[iBoxRow+x][iBoxCol+y].abPossibile[a] == true && aSquare[iBoxRow+x][iBoxCol+y].abPossibile[b] == true)
						{
							bool bFlag = true;
							for (int i = 0; i < 3; i++)
							{
								for (int n = 0; n < 3; n++)
								{
									if (!(iBoxRow+x == iRowNum && iBoxCol+y == iColumnNum) && !(i == x && n == y)
										&& aSquare[iBoxRow+i][iBoxCol+n].iDisplayNum == 0)
									{
										if (aSquare[iBoxRow+i][iBoxCol+n].abPossibile[a] == true || aSquare[iBoxRow+i][iBoxCol+n].abPossibile[b] == true)
										{
											bFlag = false;
										}
									}
								}
							}
							if (bFlag == true)
							{
								//Remove all possibilities from these squares, except whatever a and b are
								SetOnlyDoubles(iRowNum, iColumnNum, iBoxRow+x, iBoxRow+y, a, b);
							}
						}
					}
				}
			}
		}
	}
}

int FindRemainingPossibilities(int iRowNum, int iColumnNum)
{
	int iCount = 0;
	for (int i = 0; i < 9; i++)
	{
		if (aSquare[iRowNum][iColumnNum].abPossibile[i] == true)
		{
			iCount++;
		}
	}
	return iCount;
}

void SetOnlyDoubles(int iRowA, int iColA, int iRowB, int iColB, int iFirstNum, int iSecondNum)
{
	for (int x = 0; x < 9; x++)
	{
		aSquare[iRowA][iColA].abPossibile[x] = false;
		aSquare[iRowB][iColB].abPossibile[x] = false;
	}
	aSquare[iRowA][iColA].abPossibile[iFirstNum] = true;
	aSquare[iRowA][iColA].abPossibile[iSecondNum] = true;
	aSquare[iRowB][iColB].abPossibile[iFirstNum] = true;
	aSquare[iRowB][iColB].abPossibile[iSecondNum] = true;
	cout << "Setting Doubles For: First: " << iFirstNum + 1 << " Second: " << iSecondNum + 1 << endl;
	cout << "Row: " << iRowA << " Col: " << iColA << endl;
	cout << "Row: " << iRowB << " Col: " << iColB << endl;
}

void PrintFinalPuzzle()
{
	cout << "Printing Result.\n";
	int r = 0, c = 0;
	ofstream resultFile("Result.txt");
	for (int r = 0; r < 9; r++)
	{
		for (int c = 0; c < 9; c++)
		{
			resultFile << aSquare[r][c].iDisplayNum;
			if (c < 8) {resultFile << ",";} 
		}
		resultFile << endl;
	}
}