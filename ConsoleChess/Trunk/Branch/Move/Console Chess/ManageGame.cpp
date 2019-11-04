//Blake Sullivan - Manage.cpp
#include "ManageGame.h"

ManageGame::ManageGame()
{
	SetupPieces();
	SetupSquares();
	Manage();
	//DrawBoard(false);
	//DrawBoard(true);
}

void ManageGame::SetupPieces()
{
	bool bWhite = false, bKSide = false;
	char cID = ' ';
	int iLoc = 0, iVal = 0, iR1 = 0, iR2 = 0, iL1 = 0, iL2 = 0; 
	//cout << "Setting up Pieces" << endl;
	for (int i=0; i< board.CIMAXPIECES; i++)
	{
		iLoc=i;
		if (i < 16)
		{bWhite=false;}
		else
		{bWhite=true;
		iLoc+=32;}

		if (i < 4) 
		{bKSide=false;}
		else if (i>7 && i<12)
		{bKSide=false;} 
		else if (i>15 && i<20)
		{bKSide=false;}
		else if (i>23 && i<28)
		{bKSide=false;}
		else
		{bKSide=true;}

		if (i==0 || i==7 || i==24 || i==31)
		{
			//cout << i << ": ROOK" << endl;
			cID = 'R';
			iVal = 5;
			iR1 = 1; iR2 = 0; iL1 = 0; iL2 = 0;
		}
		else if (i==1 || i==6 || i==25 || i==30)
		{
			//cout << i << ": NIGHT" << endl;
			cID = 'N';
			iVal = 3;
			iR1 = 1; iR2 = 2; iL1 = 1; iL2 = 2;
		}
		else if (i==2 || i==5 || i==26 || i==29)
		{
			//cout << i << ": BISHOP" << endl;
			cID = 'B';
			iVal = 3;
			iR1 = 1; iR2 = 1; iL1 = 0; iL2 = 0;
		}
		else if (i==3 || i==27)
		{
			//cout << i << ": QUEEN" << endl;
			cID = 'Q';
			iVal = 9;
			iR1 = 0; iR2 = 0; iL1 = 0; iL2 = 0;
		}
		else if (i==4 || i==28)
		{
			//cout << i << ": KING" << endl;
			cID = 'K';
			iVal = 0;
			iR1 = 0; iR2 = 0; iL1 = 1; iL2 = 2;
		}
		else if (i==32)
		{
			//cout << i << ": OTHER" << endl;
			cID = ' ';
			bKSide = false; bWhite = false;
			iVal = 0; iLoc = 64;
			iR1 = 0; iR2 = 0; iL1 = 0; iL2 = 0;
		}
		else
		{
			//cout << i << ": PAWN" << endl;
			cID = 'P';
			iVal = 1;
			iR1 = 1; iR2 = 0; iL1 = 1; iL2 = 2;
		}

		board.SetupPiece(i, cID, bKSide, bWhite, iLoc, iVal, iR1, iR2, iL1, iL2);
	}
}

void ManageGame::SetupSquares()
{
	//cout << "Setting up Square" << endl;
	bool bWhite=true;
	int iGrRef=0, iPNum=0, iX = 8, iY = 0, iCount = -1;
	for (int i = 0; i < board.CIMAXSQUARES; i++)
	{

		for (int j=0; j < board.CIMAXPIECES; j++)
		{
			if (i==board.GetSquareLocFromPiece(j))
			{
				iPNum=j;
				break;
			}
			else
			{iPNum=32;}
		}
		
		if (i%8==0)
		{iX--; iY=0; iCount++;}
		else
		{iY++;}

		if (iCount%2==0)
		{bWhite=true;}
		else
		{bWhite=false;}
		iCount++;

		board.SetupSquare(i, bWhite, iX, iY, i, iPNum);
	}
}

void ManageGame::DrawBoard(bool bFlipWhite)
{
	//cout << "Drawing board" << endl;
	int iTemp=0, iGridChange = 0, iIncr = 0;

	if (true==bFlipWhite)
	{
		iTemp=board.CIMAXSQUARES-1;
		iGridChange = -board.CIBOARDSIZE;
		iIncr = -1;
	}
	else
	{
		iTemp=0;
		iGridChange = board.CIBOARDSIZE;
		iIncr = 1;
	}

	for (int i = 0; i < board.CIBOARDSIZE; i++)
	{
		for (int j = 0; j < board.GetGridSizeV(); j++)
		{
			board.DrawLine(iTemp, j, iIncr);
		}
		iTemp+=iGridChange;
	}
}

void ManageGame::Manage()
{
	int i = 0;
	bool bExit=false;
	string sInput;
	do
	{
		DrawBoard(i);
		sInput = Input(i);
		if (CheckInput(sInput)==true)
		{
			cout << "Valid Move." << endl;
			Move(sInput, i);

			i++;
			if (i > 1)
			{i=0;}
		}
		else
		{
			cout << "Invalid Move." << endl;
			//bExit=true;
		}
	} while (bExit==false);
}

string ManageGame::Input(bool bWhite)
{
	string sInput;
	cout << "a-h, 1-8, - to move, x to take. (d2-d4)\nWhat do you want to move and to where: ";
	getline(cin, sInput);
	return sInput;
}

bool ManageGame::CheckInput(string sInput)
{
	bool bPass = false;
	char cInput = ' ';
	for (int i = 0; i < sInput.length(); i++)
	{
		cInput = sInput[i];
		if (i == 0 || i == 3)
		{bPass = CheckLetter(cInput);}
		else if (i == 1 || i == 4)
		{bPass = CheckNumber(cInput);}
		else
		{bPass = CheckSymbol(cInput);}

		if (bPass==false)
		{break;}
	}
	return bPass;
}

bool ManageGame::CheckLetter(char cTest)
{
	if (cTest < '0' || cTest > '9')
	{
		if (cTest >= 'a' && cTest <= 'h')
		{return true;}
		else if (cTest >= 'A' && cTest <= 'H')
		{return true;}
		else
		{return false;}
	}
	else 
	{return false;}

}

bool ManageGame::CheckNumber(char cTest)
{
	if (cTest > '0' && cTest < '9')
	{return true;}
	else
	{return false;}
}
bool ManageGame::CheckSymbol(char cTest)
{
	if (cTest == '-' || cTest == 'x' || cTest == 'X')
	{return true;}
	else
	{return false;}
}


void ManageGame::Move(string sInput, bool bWhiteTurn)
{
	int iFromCol = 0, iFromRow = 0, iFromPos = -1, iToCol = 0, iToRow = 0, iToPos = -1;

	iFromCol = ConvertX(sInput[0]);
	iFromRow = ConvertY(sInput[1]);
	cout << "iFromCol: " << iFromCol << endl << "iFromRow: " << iFromRow << endl;
	iToCol = ConvertX(sInput[3]);
	iToRow = ConvertY(sInput[4]);
	cout << "iToCol: " << iToRow << endl << "iToRow: " << iToCol << endl;

	for (int i = 0; i < board.CIMAXSQUARES; i++)
	{
		if (board.CheckCoOrds(i, iFromCol, iFromRow)==true)
		{
			iFromPos = i;
		}

		if (board.CheckCoOrds(i, iToCol, iToRow)==true)
		{
			iToPos = i;
		}

		if (iFromPos >= 0 && iToPos >= 0)
		{break;}
	}
	cout << "iFromPos: " << iFromPos << endl << "iToPos: " << iToPos << endl;
	SwapPiece(iFromPos, iToPos);
}

void ManageGame::SwapPiece(int iFromSquare, int iToSquare)
{
	int iFromPiece = 0, iToPiece = 0;
	iFromPiece = board.GetPieceLocFromSquare(iFromSquare);
	iToPiece = board.GetPieceLocFromSquare(iToSquare);

	board.SetPieceLocInSquare(iToSquare, iFromPiece);
	board.SetPieceLocInSquare(iFromSquare, iToPiece);

	board.SetSquareLocInPiece(iFromPiece, iFromSquare);
	board.SetSquareLocInPiece(iToPiece, iToSquare);
}

int ManageGame::ConvertX(char cInput)
{
	int iPos = 0;
	if (cInput == 'a' || cInput == 'A')
	{iPos = 0;}
	else if (cInput == 'b' || cInput == 'B')
	{iPos = 1;}
	else if (cInput == 'c' || cInput == 'C')
	{iPos = 2;}
	else if (cInput == 'd' || cInput == 'D')
	{iPos = 3;}
	else if (cInput == 'e' || cInput == 'E')
	{iPos = 4;}
	else if (cInput == 'f' || cInput == 'F')
	{iPos = 5;}
	else if (cInput == 'g' || cInput == 'G')
	{iPos = 6;}
	else if (cInput == 'h' || cInput == 'H')
	{iPos = 7;}

	return iPos;
}

int ManageGame::ConvertY(char cInput)
{
	int iPos = 0;
	if (cInput == '1')
	{iPos = 0;}
	else if (cInput == '2')
	{iPos = 1;}
	else if (cInput == '3')
	{iPos = 2;}
	else if (cInput == '4')
	{iPos = 3;}
	else if (cInput == '5')
	{iPos = 4;}
	else if (cInput == '6')
	{iPos = 5;}
	else if (cInput == '7')
	{iPos = 6;}
	else if (cInput == '8')
	{iPos = 7;}

	return iPos;
}