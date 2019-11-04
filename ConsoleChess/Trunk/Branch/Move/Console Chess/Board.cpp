//Blake Sullivan - Board.cpp
#include "Board.h"

Board::Board()
{
	Init();
}

void Board::Init()
{
	SetColour("white", "black", "silver", "grey");
	SetGridSize(5, 3);
	SetBorders(201, 187, 200, 188, 205, 186);
	SetBorderCol("green", "red");
	//Display();
}

void Board::SetupPiece(int p, char id, bool ks, bool iw, int loc, int val, int r1, int r2, int l1, int l2)
{
	//cout <<"id:"<<id<<" ks:"<<ks<<" iw:"<<iw<<" loc:"<<loc<<" val:"<<val<<" r1:"<<r1<<" r2:"<<r2<<" l1:"<<l1<<" l2:"<<l2<<endl;
	pieces[p].Init(id, ks, iw, loc, val, r1, r2, l1, l2);
}
void Board::SetupSquare(int s, bool iw, int locR, int locC, int gr, int pn)
{
	//cout<<"s:"<<s<<" iw:"<<iw<<" locR:"<<locR<<" locC:"<<locC<<" gr:"<<gr<<" pn:"<<pn<<endl;
	squares[s].Init(iw, locR, locC, gr, pn);
}

bool Board::CheckCoOrds(int iSN, int iCol, int iRow)
{
	if (squares[iSN].GetLocRow()==iRow && squares[iSN].GetLocCol()==iCol)
	{return true;}
	else
	{return false;}
}

int Board::GetSquareLocFromPiece(int iPN)
{
	return pieces[iPN].GetLocation();
}

int Board::GetPieceLocFromSquare(int iSN)
{
	return squares[iSN].GetPiece();
}

void Board::SetPieceLocInSquare(int iSN, int iPieceLoc)
{
	squares[iSN].SetPiece(iPieceLoc);
}

void Board::SetSquareLocInPiece(int iPN, int iSquareLoc)
{
	pieces[iPN].SetLocation(iSquareLoc);
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

void Board::SetColour(string fw, string fb, string bw, string bb)
{
	iForeWhiteCol = objCC.ColourStringToColourInt(fw);
	iForeBlackCol = objCC.ColourStringToColourInt(fb);
	iBackWhiteCol = objCC.ColourStringToColourInt(bw);
	iBackBlackCol = objCC.ColourStringToColourInt(bb);
}
void Board::SetGridSize(int iH, int iV)
{
	iGridSizeH = iH;
	iGridSizeV = iV;
}
void Board::SetBorders(char tl, char tr, char bl, char br, char h, char v)
{
	cTopLeftCorner=tl;
	cTopRightCorner=tr;
	cBotLeftCorner=bl;
	cBotRightCorner=br;
	cHorizontal=h;
	cVertical=v;
}

void Board::SetBorderCol(string bf, string bb)
{
	iBorderForeCol = objCC.ColourStringToColourInt(bf);
	iBorderBackCol = objCC.ColourStringToColourInt(bb);
}

int Board::GetForeWhite()
{
	return iForeWhiteCol;
}
int Board::GetBackWhite()
{
	return iBackWhiteCol;
}
int Board::GetForeBlack()
{
	return iForeBlackCol;
}
int Board::GetBackBlack()
{
	return iBackBlackCol;
}
int Board::GetGridSizeH()
{
	return iGridSizeH;
}
int Board::GetGridSizeV()
{
	return iGridSizeV;
}
char Board::GetTopLeft()
{
	return cTopLeftCorner;
} 
char Board::GetTopRight()
{
	return cTopRightCorner;
} 
char Board::GetBotLeft()
{
	return cBotLeftCorner;
} 
char Board::GetBotRight()
{
	return cBotRightCorner;
} 
char Board::GetHorizontal()
{
	return cHorizontal;
} 
char Board::GetVertical()
{
	return cVertical;
}
int Board::GetBorderFore()
{
	return iBorderForeCol;
}
int Board::GetBorderBack()
{
	return iBorderBackCol;
}

void Board::DrawLine(int iCount, int iLinePos, int iIncr)
{
	bool bMid=false;
	for (int i = 0; i < CIBOARDSIZE; i++)
	{
		if (iLinePos == ((GetGridSizeV()/2)))
		{bMid=true;}
		else
		{bMid=false;}

		SetupSquareColours(iCount);
		DrawSquare(iCount, bMid);
		iCount+=iIncr;
	}
	DrawSquare();
}

void Board::DrawSquare(int loc, bool bMid)
{
	for (int i = 0; i < iGridSizeH; i++)
	{
		if (true==bMid&&(i == ((iGridSizeH/2))))
		{
			cout << pieces[squares[loc].GetPiece()].GetID();
		}
		else
		{
			cout << " ";
		}
	}
	objCC.Manage();
}

void Board::DrawSquare()
{
	cout << endl;
}

void Board::SetupSquareColours(int loc)
{
	int iForeCol = 0, iBackCol = 0;

	if (pieces[squares[loc].GetPiece()].GetIsWhite()==true)
	{iForeCol=iForeWhiteCol;}
	else
	{iForeCol=iForeBlackCol;}

	if (squares[loc].GetIsWhite()==true)
	{iBackCol=iBackWhiteCol;}
	else
	{iBackCol=iBackBlackCol;}

	objCC.SetTextColours(iForeCol, iBackCol);
}