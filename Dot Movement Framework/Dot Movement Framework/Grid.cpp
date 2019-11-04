//Blake Sullivan - Grid.cpp
#include "Grid.h"

Grid::Grid()
:MC_IMAP_WIDTH(0),	MC_IMAP_HEIGHT(0), MC_ITILE_WIDTH(0)
{
	
}

Grid::Grid(int w, int h)
:MC_IMAP_WIDTH(w), MC_IMAP_HEIGHT(h), MC_ITILE_WIDTH(Square::GetSize())
{
	int temp[MC_IMAP_WIDTH * MC_IMAP_HEIGHT];
	map = temp;
}
Grid::~Grid()
{
}

void Grid::SetupGrid(int iWidth, int iHeight)
{
	int iLoopNum = (iWidth / Square::GetSize()) * (iHeight / Square::GetSize());
	//cout << "iLoopNum = " << iLoopNum << " Square::GetSize(): " << Square::GetSize() << endl;
	int iRow = 0, iCol = 0, iX = 0, iY = 0;
	for (int i = 0; i < iLoopNum; i++)
	{
		iX = iCol * Square::GetSize();
		iY = iRow * Square::GetSize();
		
		//cout << "iCol: " << iCol << " iRow: " << iRow << " iX: " << iX << " iY: " << iY << endl;
		AddSquare(iRow, iCol, iX, iY);
		
		iCol++;
		if (iCol * Square::GetSize() >= iWidth) {iRow++; iCol = 0;}
	}
}

void Grid::DrawGrid(SDL_Surface* screen)
{
	for (m_vSquaresIT = m_vSquares.begin(); m_vSquaresIT != m_vSquares.end(); m_vSquaresIT++)
	{
		rectangleRGBA(screen, m_vSquaresIT->GetX(), m_vSquaresIT->GetY(), m_vSquaresIT->GetX()+Square::GetSize(), m_vSquaresIT->GetY()+Square::GetSize(), 0, 0, 0, 255);
	}
}

void Grid::AddSquare(int r, int c, int x, int y)
{
	Square tempSquare;
	tempSquare.Init(r, c, x, y);
	m_vSquares.push_back(tempSquare);
}

Square Grid::GetSquare(int x, int y)
{
}