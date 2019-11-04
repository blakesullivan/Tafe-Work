//Blake Sullivan - BoardDisplay.cpp
#include "BoardDisplay.h"

BoardDisplay::BoardDisplay()
{
	SetColour(" ", " ", " ", " ");
	SetGridSize(0, 0);
	SetBorders(' ', ' ', ' ', ' ', ' ', ' ');
	SetBorderCol(" ", " ");
}

void BoardDisplay::DrawSquare(bool bMid, char cPieceID)
{
	for (int i = 0; i < iGridSizeH; i++)
	{
		if (true==bMid && (i == (iGridSizeH/2)))
			{cout << cPieceID;}
		else
			{cout << " ";}
	}
	objCC.Reset();
}

void BoardDisplay::DrawSquare()
{
	objCC.Reset();
	cout << endl;
	//objCC.Manage();
}

void BoardDisplay::DrawBorderVert(bool bIsLeft, int iLinePos, int iGridPos)
{
	objCC.SetTextColours(iBorderForeCol, iBorderBackCol);
	for (int i = 0; i < iGridSizeH; i++)
	{
		if (iLinePos == (iGridSizeV/2) && i == (iGridSizeH/2))
			{cout << iGridPos;}
		else if (i == (iGridSizeH - 1) && bIsLeft == true)
			{cout << cVertical;}
		else if (i == 0 && bIsLeft == false)
			{cout << cVertical;}
		else
			{cout << " ";}
	}
	if (bIsLeft == false) {DrawSquare();}
	objCC.Reset();
}

void BoardDisplay::DrawBorderLine(bool bIsBottom, bool bFlipWhite)
{
	//objCC.SetTextColours(iBorderForeCol, iBorderBackCol);
	int iPosChar = 0, iIncr = 0;
	if (bFlipWhite==false)
	{
		iPosChar = 97;
		iIncr = 1;
	}
	else
	{
		iPosChar = 104;
		iIncr = -1;
	}
	for (int i = 0; i < iGridSizeV; i++)
	{
		for (int j = 0; j < CIBORDERSIZE; j++)
		{
			DrawBorder(i, j, bIsBottom, iPosChar);
			if (j > 0 && i == (iGridSizeV/2))
				{iPosChar += iIncr;}
		}
		DrawSquare();
	}
	objCC.Reset();
}

void BoardDisplay::DrawBorder(int iLocRow, int iLocCol, bool bIsBot, int iPosChar)
{
	objCC.SetTextColours(iBorderForeCol, iBorderBackCol);
	for (int i = 0; i < iGridSizeH; i++)
	{
		if (iLocCol != 0 && iLocCol != (CIBORDERSIZE - 1))
		{
			if (iLocRow == (iGridSizeV/2) && i == (iGridSizeH/2))
			{
				cout << (char) iPosChar;
			}
			else if (iLocRow == (iGridSizeV-1) && bIsBot == false)
				{cout << cHorizontal;}
			else if (iLocRow == 0 && bIsBot == true)
				{cout << cHorizontal;}
			else
				{cout << " ";}
		}
		else
		{
			if (iLocCol == 0)
			{
				//This is the very left square
				if (iLocRow == (iGridSizeV-1) && bIsBot == false && i == (iGridSizeH - 1))//Finds the right most square at top
					{cout << cTopLeftCorner;}
				else if (iLocRow == 0 && bIsBot == true && i == (iGridSizeH - 1))//find the right most square at bottom
					{cout << cBotLeftCorner;}
				else
					{cout << " ";}
			}
			else
			{
				//This is the very right square
				if (iLocRow == (iGridSizeV-1) && bIsBot == false && i == 0) //Finds the left most square at top
					{cout << cTopRightCorner;}
				else if (iLocRow == 0 && bIsBot == true && i == 0) //finds the left most square at bottom
					{cout << cBotRightCorner;}
				else
					{cout << " ";}
			}
		}
	}
}

void BoardDisplay::SetupSquareColours(bool bIsPieceBlack, bool bIsSquareWhite)
{
	int iForeCol = 0, iBackCol = 0;

	if (bIsPieceBlack == true)
		{iForeCol=iForeBlackCol;}
	else
		{iForeCol=iForeWhiteCol;}

	if (bIsSquareWhite == true)
		{iBackCol=iBackWhiteCol;}
	else
		{iBackCol=iBackBlackCol;}

	objCC.SetTextColours(iForeCol, iBackCol);
}

void BoardDisplay::SetColour(string fw, string fb, string bw, string bb)
{
	iForeWhiteCol = objCC.ColourStringToColourInt(fw);
	iForeBlackCol = objCC.ColourStringToColourInt(fb);
	iBackWhiteCol = objCC.ColourStringToColourInt(bw);
	iBackBlackCol = objCC.ColourStringToColourInt(bb);
}
void BoardDisplay::SetColour(int fw, int fb, int bw, int bb)
{
	iForeWhiteCol = fw;
	iForeBlackCol = fb;
	iBackWhiteCol = bw;
	iBackBlackCol = bb;
}
void BoardDisplay::SetGridSize(int iH, int iV)
{
	iGridSizeH = iH;
	iGridSizeV = iV;
}
void BoardDisplay::SetBorders(char tl, char tr, char bl, char br, char h, char v)
{
	cTopLeftCorner=tl;
	cTopRightCorner=tr;
	cBotLeftCorner=bl;
	cBotRightCorner=br;
	cHorizontal=h;
	cVertical=v;
}

void BoardDisplay::SetBorderCol(string bf, string bb)
{
	iBorderForeCol = objCC.ColourStringToColourInt(bf);
	iBorderBackCol = objCC.ColourStringToColourInt(bb);
}
void BoardDisplay::SetBorderCol(int bf, int bb)
{
	iBorderForeCol = bf;
	iBorderBackCol = bb;
}

int BoardDisplay::GetForeWhite()
{
	return iForeWhiteCol;
}
int BoardDisplay::GetBackWhite()
{
	return iBackWhiteCol;
}
int BoardDisplay::GetForeBlack()
{
	return iForeBlackCol;
}
int BoardDisplay::GetBackBlack()
{
	return iBackBlackCol;
}
int BoardDisplay::GetGridSizeH()
{
	return iGridSizeH;
}
int BoardDisplay::GetGridSizeV()
{
	return iGridSizeV;
}
char BoardDisplay::GetTopLeft()
{
	return cTopLeftCorner;
} 
char BoardDisplay::GetTopRight()
{
	return cTopRightCorner;
} 
char BoardDisplay::GetBotLeft()
{
	return cBotLeftCorner;
} 
char BoardDisplay::GetBotRight()
{
	return cBotRightCorner;
} 
char BoardDisplay::GetHorizontal()
{
	return cHorizontal;
} 
char BoardDisplay::GetVertical()
{
	return cVertical;
}
int BoardDisplay::GetBorderFore()
{
	return iBorderForeCol;
}
int BoardDisplay::GetBorderBack()
{
	return iBorderBackCol;
}