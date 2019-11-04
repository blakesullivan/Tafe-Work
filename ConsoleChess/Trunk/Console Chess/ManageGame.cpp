//Blake Sullivan - Manage.cpp
#include "ManageGame.h"

ManageGame::ManageGame()
{
	ManageSetup();
}

void ManageGame::ManageSetup()
{
	bIsCheckMate = false;
	sMoveFile = "Move.txt";
	sSquareFile = "Square.txt";
	sPieceFile = "Piece.txt";
	sSetupFile = "Setup.txt";

	SetupPieces();
	SetupSquares();
	SetupBoard();
	LoadMenu();
}

void ManageGame::LoadMenu()
{
	int iOption = 0;
	bool bExit = false;
	cout << "Welcome to Blakes Chess" << endl << endl;
	do
	{
		iOption = InputOptionInt(" 1. Play New Game\n 2. Resume Game\n 3. Setup Board\n 4. Exit\n\nPlease enter the number of the option you want: ", 1, 4);
		switch (iOption)
		{
		case 1:
			bExit = false;
			ResetFiles();
			SetupPieces();
			SetupSquares();
			SetupBoard();
			ManagePlay(false);
		break;
		case 2:
			bExit = false;
			ManageResume();
		break;
		case 3:
			bExit = false;
			setup.Manage();
			//SetupBoard();
		break;
		default:
			bExit = true;
		}
	}while (false == bExit);
}

void ManageGame::SetupBoard()
{
	board.Init(setup.GetForeWhiteCol(), setup.GetForeBlackCol(), setup.GetBackWhiteCol(), setup.GetBackBlackCol(), setup.GetGridSizeX(), setup.GetGridSizeY(), setup.GetBordTopL(), setup.GetBordTopR(), setup.GetBordBotL(), setup.GetBordBotR(), setup.GetBordHor(), setup.GetBordVert(), setup.GetForeBorderCol(), setup.GetBackBorderCol());
}

void ManageGame::SetupPieces()
{
	bool bBlack = false, bKSide = false;
	char cID = ' ';
	int iLoc = 0, iVal = 0, iR1 = 0, iR2 = 0, iL1 = 0, iL2 = 0; 
	//cout << "Setting up Pieces" << endl;
	for (int i=0; i< board.CIMAXPIECES; i++)
	{
		iLoc=i;
		if (i < 16)
		{bBlack=true;}
		else
		{bBlack=false;
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
			bKSide = false; bBlack = false;
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

		board.SetupPiece(i, cID, bKSide, bBlack, iLoc, iVal, iR1, iR2, iL1, iL2);
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
	int iTemp = 0, iGridChange = 0, iIncr = 0, iGridPos = 0;

	if (true == bFlipWhite)
	{
		iTemp = board.CIMAXSQUARES-1;
		iGridChange = -board.CIBOARDSIZE;
		iIncr = -1;
		iGridPos = 1;
	}
	else
	{
		iTemp = 0;
		iGridChange = board.CIBOARDSIZE;
		iIncr = 1;
		iGridPos = 8;
	}

	board.DrawBoard(iTemp, iGridChange, iIncr, iGridPos, bFlipWhite);
}

void ManageGame::ManageResume()
{
	cout << "Resuming Game." << endl;
	board.ReadSetupFile(sSetupFile);
	ManagePlay(true);
}

void ManageGame::ManagePlay(bool bResumeGame)
{
	int i = 0;
	bool bExit=false;
	string sInput;
	WriteStartupFiles();
	fstream moveFile(sMoveFile.c_str());
	//if (true == bResumeGame) {moveFile.open(sMoveFile.c_str());}
	do
	{
		if (true == bResumeGame)
		{
			sInput = board.ReadMoveFile(moveFile);
			
			if (true == board.CheckEOFMove(moveFile) || sInput == "" || sInput == " ")
				{bResumeGame = false;}
		}

		DrawBoard(i);
		if (true == CheckForCheckMate(i, bResumeGame))
		{
			CheckMate(i);
			bExit = true;
		}
		else
		{
			if (false == bResumeGame) 
			{sInput = Input(i);} 
			else 
			{
				cout << sInput << endl;
				CheckSymbol(sInput[2]);
			}

			if (true == Move(sInput, i))
			{
				if (i == 1) {i = 0;} else {i = 1;}
				if (false == bResumeGame) {WriteMoveFile(sInput);}
			}
			else
				{cout<<"Ivalid Move."<<endl;}
		}
	} while (bExit == false);
}

string ManageGame::Input(bool bBlack)
{
	bool bExit = false;
	string sInput = " ", sColour = " ";
	if (bBlack == true) {sColour = "Black";} else {sColour = "White";}

	do
	{
		cout << "a-h, 1-8, - to move, x to take. [eg: d2-d4]" << endl; 
		cout << "It is " << sColour << "'s move, what do you want to move and to where: ";
		getline(cin, sInput);
		bExit = CheckInput(sInput);
	} while (bExit == false);
	return sInput;
}

bool ManageGame::CheckInput(string sInput)
{
	bool bPass = false;
	char cInput = ' ';
	if (sInput.length() < 5)
		{bPass = false;}
	else
	{
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
	}
	if (true == bPass)
		{cout << "Valid Input" << endl;}
	else
		{cout << "Invalid Input" << endl;}

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
	if (cTest == '-')
	{
		board.SetIsTake(false);
		return true;
	}
	else if (cTest == 'x' || cTest == 'X')
	{
		board.SetIsTake(true);
		return true;
	}
	else
	{
		board.SetIsTake(false);
		return false;
	}
}

bool ManageGame::Move(string sInput, bool bBlackTurn)
{
	int iFromCol = 0, iFromRow = 0, iToCol = 0, iToRow = 0;
	bool bMoved = false;

	iFromCol = ConvertX(sInput[0]);
	iFromRow = ConvertY(sInput[1]);
	iToCol = ConvertX(sInput[3]);
	iToRow = ConvertY(sInput[4]);

	bMoved = board.CheckEverythingValidForMove(iFromCol, iFromRow, iToCol, iToRow, bBlackTurn);
	if (true == bMoved) {bIsCheckMate = false;}

	return bMoved;
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

void ManageGame::CheckMate(bool bIsBlack)
{
	string sLoseColour = " ", sWinColour = " ";
	if (false == bIsBlack) 
	{
		sLoseColour = "White";
		sWinColour = "Black";
	}
	else 
	{
		sLoseColour = "Black";
		sWinColour = "White";
	}
	cout << endl << sLoseColour << " is in CheckMate, making " << sWinColour << " the winner!" << endl << endl;
}

bool ManageGame::CheckForCheckMate(bool bIsBlack, bool bResumeGame)
{
	bool bInCheck = false, bInCheckMate = false;
	if (false == bResumeGame)
	{		
		bInCheck = board.CheckKingInCheckPreMove(bIsBlack);
		if (bInCheck == true)
		{
			cout << "\nKing is in Check Before Move.\n\n";
			bInCheckMate = InputCheckMate(bIsBlack);
		}
		else
			{bInCheckMate = false;}
	}

	return bInCheckMate;
}

bool ManageGame::InputCheckMate(bool bBlack)
{
	bool bExit = false;
	string sColour = " ", sInput = " ";
	if (bBlack == true) {sColour = "Black";} else {sColour = "White";}
	do
	{
		cout << "Is " << sColour << " in Checkmate? [y/n] ";
		getline(cin, sInput);
		bExit = CheckValidCheckMateInput(sInput);
	} while (bExit == false);
	return ReturnCheckMateInput(sInput);
}

bool ManageGame::CheckValidCheckMateInput(string sInput)
{
	if (sInput == "y" || sInput == "Y")
		{return true;}
	else if (sInput == "n" || sInput == "N")
		{return true;}
	else
	{
		cout << "Invalid Input\n";
		return false;
	}
}

bool ManageGame::ReturnCheckMateInput(string sInput)
{
	if (sInput == "y" || sInput == "Y")
		{return true;}
	else
		{return false;}
}

void ManageGame::WriteStartupFiles()
{
	board.OutputSquares(sSquareFile);
	board.OutputPieces(sPieceFile);
	board.OutputSetup(sSetupFile);
}

void ManageGame::WriteMoveFile(string sInput)
{
	board.OutputMove(sMoveFile, sInput);
}

void ManageGame::ResetFiles()
{
	ofstream moveFile(sMoveFile.c_str());
	//moveFile << eof();
	ofstream squareFile(sSquareFile.c_str());
	//squareFile << eof();
	ofstream pieceFile(sPieceFile.c_str());
	//pieceFile << eof();
	ofstream setupFile(sSetupFile.c_str());
	//setupFile << eof();

}