//Blake Sullivan - ChessBoard.cpp
#include "ChessBoard.h"

ChessBoard::ChessBoard()
{
	int iCount=0;
	for (int i=0;i<8;i++)
	{
		for (int j=0;j<8;j++)
		{
			boardPos[i][j].name=' ';
			if (iCount%2==0)
			{boardPos[i][j].backCol = "silver";}
			else
			{boardPos[i][j].backCol = "grey";}
			iCount++;
		}
		iCount++;
	}
	
	DefaultPos();

	Draw();
	system("PAUSE");
}

void ChessBoard::DefaultPos()
{
	boardPos[0][0].name='R';
	boardPos[0][1].name='N';
	boardPos[0][2].name='B';
	boardPos[0][3].name='Q';
	boardPos[0][4].name='K';
	boardPos[0][5].name='B';
	boardPos[0][6].name='N';
	boardPos[0][7].name='R';

	boardPos[1][0].name='P';
	boardPos[1][1].name='P';
	boardPos[1][2].name='P';
	boardPos[1][3].name='P';
	boardPos[1][4].name='P';
	boardPos[1][5].name='P';
	boardPos[1][6].name='P';
	boardPos[1][7].name='P';

	for (int i = 0; i<2; i++)
	{
		for (int j = 0; j<8; j++)
		{
			boardPos[i][j].foreCol = "grey";
		}
	}

	boardPos[6][0].name='P';
	boardPos[6][1].name='P';
	boardPos[6][2].name='P';
	boardPos[6][3].name='P';
	boardPos[6][4].name='P';
	boardPos[6][5].name='P';
	boardPos[6][6].name='P';
	boardPos[6][7].name='P';

	boardPos[7][0].name='R';
	boardPos[7][1].name='N';
	boardPos[7][2].name='B';
	boardPos[7][3].name='Q';
	boardPos[7][4].name='K';
	boardPos[7][5].name='B';
	boardPos[7][6].name='N';
	boardPos[7][7].name='R';

	for (int i = 6; i<8; i++)
	{
		for (int j = 0; j<8; j++)
		{
			boardPos[i][j].foreCol = "white";
		}
	}
}

void ChessBoard::Draw()
{
	TextController objTC;
	//objTC.SetTextColours("silver","black");
	int iInput, iType;
	bool bEnd=false;

	while (bEnd==false)
	{
		objTT.Manage();
		cout << "What size do you want your chess grid? ";
		cin >> iInput;

		if (iInput!=99)
		{
			cout << "What style of board?\n 1. Ascii\n 2. Colours\n";
			cin >> iType;
			if (iType==1)
			{DrawAscii(iInput);}
			else
			{DrawColour(iInput);}
		}
		else
		{bEnd=true;}
	}
}

void ChessBoard::DrawAscii(int iInput)
{
	DrawTop(iInput);
	DrawMid(iInput, 0);
	for (int i = 0; i <  (ciGridSize-1); i++)
	{
		DrawInnerBorder(iInput, i);
		DrawMid(iInput, i+1);
	}
	DrawBottom(iInput);
}

void ChessBoard::DrawTop(int iS)
{
	int iCol=0;
	//objTT.SetTextColours(boardPos[0][iCol].foreCol, boardPos[0][iCol].backCol);
	cout << ccCornerTL;

	for (int i=0; i < ciGridSize-1; i++)
	{
		DrawHBorderSegment(iS, 0, iCol);
		cout << ccBorderHBT;
		iCol++;
	}
	DrawHBorderSegment(iS, 0, iCol);
	cout << ccCornerTR << endl;
}

void ChessBoard::DrawBottom(int iS)
{
	int iCol=0;
	//objTT.SetTextColours(boardPos[ciGridSize-1][iCol].foreCol, boardPos[ciGridSize-1][iCol].backCol);
	cout << ccCornerBL;
	
	for (int i=0; i < ciGridSize-1; i++)
	{
		DrawHBorderSegment(iS, ciGridSize-1, iCol);
		cout << ccBorderHBB;
		iCol++;
	}
	DrawHBorderSegment(iS, ciGridSize-1, iCol);
	cout << ccCornerBR << endl;
}

void ChessBoard::DrawHBorderSegment(int iS)
{
	for (int j = 0; j < iS; j++)
		DrawHBorderLine();
}

void ChessBoard::DrawHBorderSegment(int iS, int iRow, int iCol)
{
	for (int j = 0; j < iS; j++)
	{
		//objTT.SetTextColours(boardPos[iRow][iCol].foreCol, boardPos[iRow][iCol].backCol);
		DrawHBorderLine();
	}
}


void ChessBoard::DrawHBorderLine()
{
	cout << ccBorderHor;
}

void ChessBoard::DrawMid(int iS, int iRow)
{
	int iCol;
	bool bPLine=false;
	for (int j=0; j < (iS-2); j++)
	{
		iCol=0;
		if (j == (((iS-2)/2))||(iS-2==1))
		{bPLine=true;}
		else
		{bPLine=false;}

		//objTT.SetTextColours(boardPos[iRow][iCol].foreCol, boardPos[iRow][iCol].backCol);
		cout << ccBorderVer;
		for (int i=0; i < ciGridSize-1; i++)
		{
			//objTT.SetTextColours(boardPos[iRow][iCol].foreCol, boardPos[iRow][iCol].backCol);
			DrawMidSegment(iS, bPLine, iRow, iCol);
			cout << ccBorderVer;
			iCol++;
		}
		//objTT.SetTextColours(boardPos[iRow][iCol].foreCol, boardPos[iRow][iCol].backCol);
		DrawMidSegment(iS, bPLine, iRow, iCol);
		cout << ccBorderVer << endl;
	}
}

void ChessBoard::DrawMidSegment(int iS, bool bPiece, int iRow, int iCol)
{
	for (int j = 0; j < iS; j++)
	{
		if (j == ((iS/2)) && bPiece==true)
		{DrawPiece(iRow, iCol);}
		else
		{DrawSpace();}
	}
}

void ChessBoard::DrawSpace()
{
	cout << " ";
}

void ChessBoard::DrawPiece(int iR, int iC)
{
	objTT.SetTextColours(boardPos[iR][iC].foreCol, "black");
	cout << boardPos[iR][iC].name;
	objTT.Manage();
}

void ChessBoard::DrawInnerBorder(int iS, int iRow)
{
	int iCol=0;
	//objTT.SetTextColours(boardPos[iRow][iCol].foreCol, boardPos[iRow][iCol].backCol);
	cout << ccBorderVBL;

	for (int i=0; i < ciGridSize-1; i++)
	{
		//objTT.SetTextColours(boardPos[iRow][iCol].foreCol, boardPos[iRow][iCol].backCol);
		DrawHBorderSegment(iS);
		cout << ccBorderCross;
		iCol++;
	}
	//objTT.SetTextColours(boardPos[iRow][iCol].foreCol, boardPos[iRow][iCol].backCol);
	DrawHBorderSegment(iS);
	cout << ccBorderVBR << endl;
}

void ChessBoard::DrawColour(int iInput)
{
	for (int i=0; i<ciGridSize; i++)
	{
		for (int l=0; l<iInput-2; l++)
		{
			for (int j=0; j<ciGridSize; j++)
			{
				objTT.SetTextColours(boardPos[i][j].foreCol, boardPos[i][j].backCol);
				for (int k=0; k<iInput; k++)
				{
					DrawSpace();
				}
			}
			cout << endl;
		}
	}
}