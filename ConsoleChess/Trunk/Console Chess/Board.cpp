//Blake Sullivan - Board.cpp
#include "Board.h"

ostream& operator<<(ostream& out, Piece p)
{
	out << p.GetID() << ",";
	out << p.GetSide() << ",";
	out << p.GetIsBlack() << ",";
	out << p.GetLocation() << ",";
	out << p.GetValue() << ",";
	out << p.GetMoved() << ",";
	out << p.GetAlive() << ",";
	out << p.GetR1() << ",";
	out << p.GetR2() << ",";
	out << p.GetL1() << ",";
	out << p.GetL2() << endl;
	return out;
}

ostream& operator<<(ostream& out, Square s)
{
	out << s.GetIsWhite() << ",";
	out << s.GetLocRow() << ",";
	out << s.GetLocCol() << ",";
	out << s.GetGridRef() << ",";
	out << s.GetPiece() << endl;
	return out;
}

Board::Board()
{
	//Init("white", "black", "silver", "grey", 3, 2, 201, 187, 200, 188, 205, 186, "green", "red");
	SetIsTake(false);
	SetIsCastling(false); 
	SetCanEnPassent(false);
	SetEnPassentTake(false);
}

void Board::Init(string fw, string fb, string bw, string bb, int gh, int gv, char tl, char tr, char bl, char br, char h, char v, string bordf, string bordb)
{
	SetColour(fw, fb, bw, bb);
	SetGridSize(gh, gv);
	SetBorders(tl, tr, bl, br, h, v);
	SetBorderCol(bordf, bordb);
	//Display();
}

void Board::SetupPiece(int p, char id, bool ks, bool iw, int loc, int val, int r1, int r2, int l1, int l2)
{
	pieces[p].Init(id, ks, iw, loc, val, r1, r2, l1, l2);
}
void Board::SetupSquare(int s, bool iw, int locR, int locC, int gr, int pn)
{
	squares[s].Init(iw, locR, locC, gr, pn);
}

void Board::Display()
{
	cout << "BOARD VARIABLES" << endl;
	cout << "GetForeWhite: " << GetForeWhite() << endl;
	cout << "GetBackWhite: " << GetBackWhite() << endl;
	cout << "GetForeBlack: " << GetForeBlack() << endl;
	cout << "GetBackBlack: " << GetBackBlack() << endl;
	cout << "GetGridSizeH: " << GetGridSizeH() << endl;
	cout << "GetGridSizeV: " << GetGridSizeV() << endl;
	cout << "GetTopLeft: " << GetTopLeft() << endl; 
	cout << "GetTopRight: " << GetTopRight() << endl; 
	cout << "GetBotLeft: " << GetBotLeft() << endl; 
	cout << "GetBotRight: " << GetBotRight() << endl; 
	cout << "GetHorizontal: " << GetHorizontal() << endl; 
	cout << "GetVertical: " << GetVertical() << endl;
	cout << "GetBorderFore: " << GetBorderFore() << endl;
	cout << "GetBorderBack: " << GetBorderBack() << endl;
}
void Board::DrawBoard(int iRowStart, int iGridChange, int iIncr, int iGridPos, bool bFlipWhite)
{
	DrawBorderLine(false, bFlipWhite);
	for (int i = 0; i < CIBOARDSIZE; i++)
	{
		for (int j = 0; j < GetGridSizeV(); j++)
		{
			DrawBorderVert(true, j, iGridPos);
			SetupSquareColours(pieces[squares[j].GetPiece()].GetIsBlack(), squares[j].GetIsWhite());
			DrawLine(iRowStart, j, iIncr);
			DrawBorderVert(false, j, iGridPos);
		}
		iRowStart += iGridChange;
		iGridPos += (iIncr * -1);
	}
	DrawBorderLine(true, bFlipWhite);
}
void Board::DrawLine(int iCount, int iLinePos, int iIncr)
{
	bool bMid=false;
	for (int i = 0; i < CIBOARDSIZE; i++)
	{
		if (iLinePos == ((GetGridSizeV() / 2)))
		{bMid=true;}
		else
		{bMid=false;}

		SetupSquareColours(pieces[squares[iCount].GetPiece()].GetIsBlack(), squares[iCount].GetIsWhite());
		DrawSquare(bMid, pieces[squares[iCount].GetPiece()].GetID());
		iCount += iIncr;
	}
}

bool Board::CheckEverythingValidForMove(int iFromCol, int iFromRow, int iToCol, int iToRow, bool bBlackTurn)
{
	int iFromPos = -1, iToPos = -1, iCastleFromPos = -1, iCastleToPos = -1;

	iFromPos = GetSquarePosFromSquareCoOrd(iFromCol, iFromRow);
	iToPos = GetSquarePosFromSquareCoOrd(iToCol, iToRow);

	if (true == CheckPieceIsSameCol(iFromPos, bBlackTurn)) 
	{
		if (true == ValidMove(iFromPos, iToPos))
		{
			if (false == CheckKingInCheck(bBlackTurn, iFromPos, iToPos))
			{
				if (true == GetIsCastling())
				{
					if (true == CheckCastlingMove(iFromPos, iToPos, iCastleFromPos, iCastleToPos, bBlackTurn))
					{
						MovePiece(iFromPos, iToPos, true);
						MovePiece(iCastleFromPos, iCastleToPos, true); //Moves the Rook
						cout << "Valid Castling Move.\n";
						return true;
					}
					else
					{
						cout << "Castling Move Invalid.\n";
						return false;
					}
				}
				else
				{
					if (GetEnPassentTake() == true)
					{
						int iMidPos = GetSquarePosFromSquareCoOrd(squares[iToPos].GetLocCol(), squares[iFromPos].GetLocRow());
						MovePiece(iFromPos, iMidPos, true);
						iFromPos = iMidPos;
					}

					MovePiece(iFromPos, iToPos, true);
					cout << "Valid Move.\n";
					return true;
				}
			}
			else
				{return false;}
		}
		else
			{return false;}
	}
	else
	{
		cout << "Piece is not your colour, please select a piece in your colour.\n";
		return false;
	}
}
bool Board::ValidMove(int iFromSquare, int iToSquare)
{
	bool bValid = false;
	//cout << "In ManageGame::ValidMove" << endl;
	bValid = CheckValidMove(iFromSquare, iToSquare, GetIsTake());
	if (bValid == false)
		{cout << "Piece cannot move that way.\n";}
	else
	{
		SetEnPassentTake(false);
		if (GetIsTake() == true)
		{
			//cout << "pieces[GetPieceLocFromSquare(iFromSquare)].GetID() == " << pieces[GetPieceLocFromSquare(iFromSquare)].GetID() << " && GetCanEnPassent() == " << GetCanEnPassent() << endl;
			if (pieces[GetPieceLocFromSquare(iFromSquare)].GetID() == 'P' && GetCanEnPassent() == true)
				{bValid = CheckEnPassentTake(iFromSquare, iToSquare);}
			else
				{bValid = CheckLegalTake(iFromSquare, iToSquare);}
		}
		else
			{bValid = CheckLegalMove(iFromSquare, iToSquare);}
	}
	return bValid;
}
void Board::MovePiece(int iFromSquare, int iToSquare, bool bMovePiece)
{
	int iFromPiece = 0, iToPiece = 0;

	iFromPiece = GetPieceLocFromSquare(iFromSquare);
	iToPiece = GetPieceLocFromSquare(iToSquare);

	SetPieceLocInSquare(iToSquare, iFromPiece);
	SetPieceLocInSquare(iFromSquare, CIDUMMYPIECE);

	SetSquareLocInPiece(iFromPiece, iToSquare);
	//SetSquareLocInPiece(iToPiece, iToSquare);

	if (pieces[iToPiece].GetID() != ' ')
		{pieces[iToPiece].SetAlive(false);}

	if (bMovePiece == true) {pieces[iFromPiece].SetMoved(true);}
	//cout << "Before CheckEnPassent: " << GetCanEnPassent() << endl;
	if (true == bMovePiece) {SetCanEnPassent(CheckEnPassent(iFromSquare, iToSquare));}
	//cout << "After CheckEnPassent: " << GetCanEnPassent() << endl;
}

bool Board::CheckCoOrds(int iSN, int iCol, int iRow)
{
	if (squares[iSN].GetLocRow()==iRow && squares[iSN].GetLocCol()==iCol)
	{return true;}
	else
	{return false;}
}
bool Board::CheckPieceIsSameCol(int iFS, bool bBlackTurn)
{
	int iP = GetPieceLocFromSquare(iFS);
	if (bBlackTurn == pieces[iP].GetIsBlack())
		{return true;}
	else
		{return false;}
}
bool Board::CheckValidMove(int iFS, int iTS, bool bIsTaking)
{
	int iFP = 0;
	//cout << "In Board::CheckValidMove" << endl;
	iFP = GetPieceLocFromSquare(iFS);
	if (true == pieces[iFP].CheckMove(pieces[iFP].GetID(), squares[iFS].GetLocRow(), squares[iFS].GetLocCol(), squares[iTS].GetLocRow(), squares[iTS].GetLocCol(), bIsTaking, pieces[iFP].GetIsBlack(), pieces[iFP].GetMoved(), bIsCastling))
		{return true;}
	else
		{return false;}
}
bool Board::CheckLegalMove(int iFS, int iTS, bool bShowOutput)
{
	bool bPath = false;
	int iFP = 0, iFromCol = 0, iFromRow = 0, iToCol = 0, iToRow = 0;
	iFP = GetPieceLocFromSquare(iFS);

	iFromCol = squares[iFS].GetLocCol();
	iFromRow = squares[iFS].GetLocRow();

	iToCol = squares[iTS].GetLocCol();
	iToRow = squares[iTS].GetLocRow();

	if (pieces[iFP].GetID() == 'N')
		{bPath = true;}
	else
		{bPath = CheckPath(iFromCol, iFromRow, iToCol, iToRow, true);}

	if (bPath == true)
	{
		if (false == CheckLandingHasPiece(iTS))
			{return true;}
		else
		{
			if (bShowOutput == true) {cout << "Destination square has a piece located there.\n";}
			return false;
		}
	}
	else
	{
		if (bShowOutput == true) {cout << "Path of movement not clear.\n";}
		return false;
	}
}
bool Board::CheckLegalTake(int iFS, int iTS, bool bShowOutput)
{
	bool bPath = false, bValid = false;

	if (pieces[GetPieceLocFromSquare(iFS)].GetID() == 'N')
		{bPath = true;}
	else
		{bPath = CheckPath(squares[iFS].GetLocCol(), squares[iFS].GetLocRow(), squares[iTS].GetLocCol(), squares[iTS].GetLocRow(), false);}

	if (bPath == true)
	{
		if (true == CheckLandingHasPiece(iTS))
		{
			if (true==CheckTakePieceColToDestPieceCol(GetPieceLocFromSquare(iFS), GetPieceLocFromSquare(iTS)))
				{bValid = true;}
			else
			{
				if (bShowOutput == true) {cout << "Piece cannot take a Piece of it's own colour.\n";}
				bValid = false;
			}
		}
		else
		{
			if (bShowOutput == true) {cout << "Destination square doesnot have a piece located there.\n";}
			bValid = false;
		}
	}
	else
	{
		if (bShowOutput == true) {cout << "Path of movement not clear.\n";}
		bValid = false;
	}

	return bValid;
}
bool Board::CheckLandingHasPiece(int iTS)
{
	int iP = GetPieceLocFromSquare(iTS);
	if (pieces[iP].GetID() == ' ')
		{return false;}
	else
		{return true;}
}
bool Board::CheckPath(int iFromCol, int iFromRow, int iToCol, int iToRow, bool bCheckDestSquare)
{
	int iAbsR = 0, iAbsC = 0, iRealR = 0, iRealC = 0;
	int iRIncr = 0, iCIncr = 0, iCurR = 0, iCurC = 0;
	int iS = 0;

	iCurR = iFromRow;
	iRealR = iToRow - iFromRow;
	if (iRealR < 0) 
		{iAbsR = iRealR * -1; iRIncr = -1;} 
	else 
		{iAbsR = iRealR; iRIncr = 1;}

	iCurC = iFromCol;
	iRealC = iToCol - iFromCol;
	if (iRealC < 0) 
		{iAbsC = iRealC * -1; iCIncr = -1;} 
	else 
		{iAbsC = iRealC; iCIncr = 1;}
	
	for (int i = 0; i < (iAbsR + iAbsC); i++)
	{
		if ((iAbsR - i) > 0) {iCurR += iRIncr;}
		if ((iAbsC - i) > 0) {iCurC += iCIncr;}

		if (iCurR == iToRow && iCurC == iToCol && bCheckDestSquare == false)
			{break;}
		//cout << "iCurC: " << iCurC << " iCurR: " << iCurR << endl;
		for (int j = 0; j < CIMAXSQUARES; j++)
		{
			iS = j;
			if (CheckCoOrds(iS, iCurC, iCurR) == true)
				{break;}
		}
		//cout << "iS: " << iS << endl;
		if (pieces[GetPieceLocFromSquare(iS)].GetID() != ' ')
			{return false;}

	}
	return true;
}
bool Board::CheckTakePieceColToDestPieceCol(int iFP, int iTP)
{
	if (pieces[iFP].GetIsBlack() != pieces[iTP].GetIsBlack())
		{return true;}
	else
		{return false;}
}

bool Board::CheckKingInCheck(bool bIsBlackTurn, int iFromPos, int iToPos)
{
	bool bTempCastling = GetIsCastling();
	bool bCheckPre = false, bCheckAft = false;
	bCheckPre = CheckKingInCheckPreMove(bIsBlackTurn);
	//if (bCheckPre == true) {cout << "King In Check Before Moving.\n";}
	bCheckAft = CheckKingInCheckAfterMove(bIsBlackTurn, iFromPos, iToPos);
	if (bCheckAft == true) {cout << "King In Check After Moving. \n";}
	
	SetIsCastling(bTempCastling);
	return bCheckAft;
}
bool Board::CheckKingInCheckPreMove(bool bIsBlackTurn)
{
	int iKingPiece = 0, iKingLoc = 0, iPos = 0;
	iKingPiece = GetKingPiece(bIsBlackTurn);
	iKingLoc = pieces[iKingPiece].GetLocation();

	for (int i = 0; i < (CIMAXPIECES - 1); i++)
	{
		if (pieces[i].GetIsBlack() != bIsBlackTurn && pieces[i].GetAlive() == true)
		{
			iPos = pieces[i].GetLocation();
			if (true == CheckValidMove(iPos, iKingLoc, true))
			{
				if (true == CheckLegalTake(iPos, iKingLoc, false))
					{return true;}
			}
		}
	}
	return false;
}
bool Board::CheckKingInCheckAfterMove(bool bIsBlackTurn, int iFromPos, int iToPos)
{
	int iKingPiece = 0, iKingLoc = 0, iPos = 0, iToPiece = 0;
	bool bInCheck = false;
	bInCheck = false;

	iToPiece = GetPieceLocFromSquare(iToPos);
	MovePiece(iFromPos, iToPos, false);

	iKingPiece = GetKingPiece(bIsBlackTurn);
	iKingLoc = pieces[iKingPiece].GetLocation();

	//cout << "iKingPiece: " << iKingPiece << " iKingLoc: " << iKingLoc << endl;
	//cout << "iFromPos: " << iFromPos << " iToPos: " << iToPos << endl;

	for (int i = 0; i < (CIMAXPIECES - 1); i++)
	{
		if (pieces[i].GetIsBlack() != bIsBlackTurn && pieces[i].GetAlive() == true)
		{
			iPos = pieces[i].GetLocation();

			//cout << "iPos: " << iPos << " cID: " << pieces[i].GetID() << endl;
			if (true == CheckValidMove(iPos, iKingLoc, true))
			{
				if (true == CheckLegalTake(iPos, iKingLoc, false))
				{
					bInCheck = true;
					break;
				}
			}
		}
	}
	MovePiece(iToPos, iFromPos, false);
	SetPieceLocInSquare(iToPos, iToPiece);

	return bInCheck;
}
bool Board::CheckCastlingMove(int iFS, int iTS, int& iCFS, int& iCTS, bool bBlackTurn)
{
	//cout << "In CheckCastlingMove.\n";
	int iMP = -1, iCPiece = -1;
	bool bShortCastle = false;
	if (CheckKingInCheckPreMove(bBlackTurn) == false)
	{
		if (squares[iFS].GetLocCol() > squares[iTS].GetLocCol())
		{
			iMP = iFS - 1;
			bShortCastle = false;
		}
		else
		{
			iMP = iFS + 1;
			bShortCastle = true;
		}
		if (false == CheckKingInCheckAfterMove(bBlackTurn, iFS, iMP))
		{
			iCPiece = GetRookForCastling(bBlackTurn, iTS, bShortCastle);
			if (iCPiece == -1) {return false;}
			if (pieces[iCPiece].GetMoved() == false)
			{
				iCFS = GetSquareLocFromPiece(iCPiece);
				iCTS = iMP;
				if (true == ValidMove(iCFS, iCTS))
					{return true;}
				else
					{return false;}
			}
			else
			{
				cout << "Rook Has moved, Therefore Unable To Castle.\n";
				return false;
			}
		}
		else
		{
			cout << "King Cannot Castle Through Check.\n";
			return false;
		}
	}
	else
	{
		cout << "King Cannot Castle Out Of Check.\n";
		return false;
	}
}
bool Board::CheckEnPassent(int iFromSquare, int iToSquare)
{
	int iToPiece = -1, iCheckPiece = -1;
	int iAbRowChange = 0;
	iToPiece = GetPieceLocFromSquare(iToSquare);
	if (pieces[iToPiece].GetID() == 'P')
	{
		iAbRowChange = squares[iToSquare].GetLocRow() - squares[iFromSquare].GetLocRow();
		if (iAbRowChange < 0) {iAbRowChange *= -1;}

		if (iAbRowChange == 2)
		{
			if ((squares[iToSquare].GetLocRow() == 3 && pieces[iToPiece].GetIsBlack() == false) || (squares[iToSquare].GetLocRow() == 4 && pieces[iToPiece].GetIsBlack() == true))
			{
				if (squares[iToSquare].GetLocRow() == squares[iToSquare-1].GetLocRow())
				{
					iCheckPiece = GetPieceLocFromSquare(iToSquare-1);
					if (pieces[iCheckPiece].GetID() == 'P')
					{
						if (pieces[iCheckPiece].GetIsBlack() != pieces[iToPiece].GetIsBlack())
						{
							return true;						
						}
					}
				}

				if (squares[iToSquare].GetLocRow() == squares[iToSquare+1].GetLocRow())
				{
					iCheckPiece = GetPieceLocFromSquare(iToSquare+1);
					if (pieces[iCheckPiece].GetID() == 'P')
					{
						if (pieces[iCheckPiece].GetIsBlack() != pieces[iToPiece].GetIsBlack())
						{
							return true;
						}
					}
				}
			}
		}
	}
	
	return false;
}
bool Board::CheckEnPassentTake(int iFS, int iTS)
{
	bool bValid = false;
	int iEnPassSquare = -1;
	if (false == CheckLandingHasPiece(iTS))
	{
		//cout << "squares[iFS].GetLocRow() = " << squares[iFS].GetLocRow() << " squares[iTS].GetLocCol() = " << squares[iTS].GetLocCol() << endl;
		iEnPassSquare = GetSquarePosFromSquareCoOrd(squares[iTS].GetLocCol(), squares[iFS].GetLocRow());
		//cout << "iEnPassSquare = " << iEnPassSquare << endl;
		//cout << "GetPieceLocFromSquare(iEnPassSquare) = " << GetPieceLocFromSquare(iEnPassSquare) << endl;
		if (pieces[GetPieceLocFromSquare(iEnPassSquare)].GetID() == 'P')
		{
			SetEnPassentTake(true);
			return true;
		}
		else
		{cout << "En Passent must take a Pawn.\n";}
	}
	return false;
}

void Board::SetIsTake(bool bTemp)
{
	bIsTake = bTemp;
}
void Board::SetIsCastling(bool bTemp)
{
	bIsCastling = bTemp;
}
void Board::SetCanEnPassent(bool bTemp)
{
	bCanEnPassent = bTemp;
	if (bCanEnPassent == true) {cout << "En Passent Possible.\n";}
}
void Board::SetEnPassentTake(bool bTemp)
{
	bEnPassentTake = bTemp;
}

bool Board::GetIsTake()
{
	return bIsTake;
}
bool Board::GetIsCastling()
{
	return bIsCastling;
}
bool Board::GetCanEnPassent()
{
	return bCanEnPassent;
}
bool Board::GetEnPassentTake()
{
	return bEnPassentTake;
}

int Board::GetSquareLocFromPiece(int iPN)
{
	return pieces[iPN].GetLocation();
}
int Board::GetPieceLocFromSquare(int iSN)
{
	return squares[iSN].GetPiece();
}
int Board::GetSquarePosFromSquareCoOrd(int iCol, int iRow)
{
	for (int i = 0; i < CIMAXSQUARES; i++)
	{
		if (true == CheckCoOrds(i, iCol, iRow))
			{return i;}
	}
	return -1;
}
int Board::GetOppKingPiece(bool bIsBlack)
{
	for (int i = 0; i < CIMAXPIECES; i++)
	{
		if (pieces[i].GetIsBlack() != bIsBlack)
		{
			if (pieces[i].GetID() == 'K')
			{
				return i;
			}
		}
	}
}
int Board::GetKingPiece(bool bIsBlack)
{
	for (int i = 0; i < CIMAXPIECES; i++)
	{
		if (pieces[i].GetIsBlack() == bIsBlack)
		{
			if (pieces[i].GetID() == 'K')
			{
				return i;
			}
		}
	}
	return -1;
}
int Board::GetRookForCastling(bool bBlackTurn, int iTP, bool bSC)
{
	int iCastlePos = -1, iCastleDistance = 0;
	if (bSC == true) {iCastleDistance = 1;} else {iCastleDistance = 2;}
	for (int i = 0; i < CIMAXPIECES; i++)
	{
		if (pieces[i].GetIsBlack() == bBlackTurn && pieces[i].GetID() == 'R')
		{
			iCastlePos = GetSquareLocFromPiece(i);
			if (squares[iCastlePos].GetLocCol() == (squares[iTP].GetLocCol() + iCastleDistance))
			{return i;}
			else if (squares[iCastlePos].GetLocCol() == (squares[iTP].GetLocCol() - iCastleDistance))
			{return i;}
		}
	}
	cout << "Cannot Find Rook to Castle.\n"; 
	return -1;
}

void Board::SetPieceLocInSquare(int iSN, int iPieceLoc)
{
	squares[iSN].SetPiece(iPieceLoc);
}
void Board::SetSquareLocInPiece(int iPN, int iSquareLoc)
{
	pieces[iPN].SetLocation(iSquareLoc);
}

void Board::OutputMove(string sMoveFile, string sMove)
{
	fstream moveFile;
	moveFile.open(sMoveFile.c_str(), ios::app);
	if (moveFile.good())
		{moveFile << sMove << endl;}
	else
		{cout << "Move file failed to open." << endl;}
}
void Board::OutputSquares(string sSquareFile)
{
	ofstream squareFile(sSquareFile.c_str());
	if (squareFile.good())
	{
		for (int i = 0; i < CIMAXSQUARES; i++)
			{squareFile << i << ":" << squares[i];}
	}
	else
		{cout << "Square file failed to open." << endl;}
}
void Board::OutputPieces(string sPieceFile)
{
	ofstream pieceFile(sPieceFile.c_str());
	if (pieceFile.good())
	{
		for (int i = 0; i < CIMAXPIECES; i++)
			{pieceFile << i << ":" << pieces[i];}
	}
	else
		{cout << "Piece file failed to open." << endl;}
}

void Board::OutputSetup(string sSetupFile)
{
	ofstream setupFile(sSetupFile.c_str());
	if (setupFile.good())
	{
		setupFile << GetForeWhite() << endl;
		setupFile << GetForeBlack() << endl;
		setupFile << GetBackWhite() << endl;
		setupFile << GetBackBlack() << endl;
		setupFile << GetGridSizeH() << endl;
		setupFile << GetGridSizeV() << endl;
		setupFile << (int) GetTopLeft() << endl; 
		setupFile << (int) GetTopRight() << endl; 
		setupFile << (int) GetBotLeft() << endl; 
		setupFile << (int) GetBotRight() << endl; 
		setupFile << (int) GetHorizontal() << endl; 
		setupFile << (int) GetVertical() << endl;
		setupFile << GetBorderFore() << endl;
		setupFile << GetBorderBack() << endl;
	}
	else
		{cout << "Setup file failed to open." << endl;}
}

void Board::ReadSetupFile(string sSetupFile)
{
	int iTemp[6];
	ifstream setupFile(sSetupFile.c_str());
	if (setupFile.good())
	{
		setupFile >> iTemp[0];
		setupFile >> iTemp[1];
		setupFile >> iTemp[2];
		setupFile >> iTemp[3];
		SetColour(iTemp[0], iTemp[1], iTemp[2], iTemp[3]);
		
		setupFile >> iTemp[0];
		setupFile >> iTemp[1];
		SetGridSize(iTemp[0], iTemp[1]);

		setupFile >> iTemp[0];
		setupFile >> iTemp[1];
		setupFile >> iTemp[2];
		setupFile >> iTemp[3];
		setupFile >> iTemp[4];
		setupFile >> iTemp[5];
		SetBorders(iTemp[0], iTemp[1], iTemp[2], iTemp[3], iTemp[4], iTemp[5]);

		setupFile >> iTemp[0];
		setupFile >> iTemp[1];
		SetBorderCol(iTemp[0], iTemp[1]);
	}
	else
		{cout << "Setup file failed to open for input" << endl;}
}

string Board::ReadMoveFile(fstream& move)
{
	string sInput = " ";
	move >> sInput;
	return sInput;
}
bool Board::CheckEOFMove(fstream& move)
{
	return move.eof();
}