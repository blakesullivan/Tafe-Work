//Blake Sullivan - Grid.cpp
#include "Grid.h"

Grid::Grid()
{
}
Grid::~Grid()
{
}

void Grid::SetupGrid(int iWidth, int iHeight, string sMapName)
{
	string sInputName = "", sPicName = "", sTemp = "";
	int iTemp = 0;
	fstream fMap;
	sInputName = sMapName + ".txt";
	sPicName = sMapName + ".bmp";
	SetMap(sPicName);
	fMap.open(sInputName.c_str());
	if (fMap.good())
	{
		int iLoopNum = (iWidth / Square::GetSize()) * (iHeight / Square::GetSize());
		//cout << "iLoopNum = " << iLoopNum << " Square::GetSize(): " << Square::GetSize() << endl;
		int iRow = 0, iCol = 0, iX = 0, iY = 0;
		fMap >> sTemp;
		cout << sTemp << endl;
		for (int i = 0; i < iLoopNum; i++)
		{
			iX = iCol * Square::GetSize();
			iY = iRow * Square::GetSize();

			iTemp = atoi(sTemp.substr(0, sTemp.find(",")).c_str());
			sTemp = sTemp.substr(sTemp.find(",") + 1, sTemp.length());
			
			//cout << "iCol: " << iCol << " iRow: " << iRow << " iX: " << iX << " iY: " << iY << endl;
			AddSquare(iRow, iCol, iX, iY, iTemp);
			
			iCol++;
			if (iCol * Square::GetSize() >= iWidth)
			{
				iRow++; 
				iCol = 0;
				sTemp = "";
				fMap >> sTemp;
				cout << sTemp << endl;
			}
		}
	}
}

void Grid::DrawGrid(SDL_Surface* screen)
{
	//int r = 0, g = 0, b = 0;
	SDL_Rect sclip, dclip;
	for (m_vSquaresIT = m_vSquares.begin(); m_vSquaresIT != m_vSquares.end(); m_vSquaresIT++)
	{
		//cout << "In DrawGrid. GetWalkable: " << m_vSquaresIT->GetWalkable() << endl;
		//if (m_vSquaresIT->GetWalkable() == 9)
		//{
		//	//cout << "In DrawGrid, colour = 9" << endl;
		//	r = 200; g = 200; b = 200;
		//}
		//else
		//{
		//	//cout << "In DrawGrid, colour = 0" << endl;
		//	r = 50; g = 220; b = 50;
		//}

		//boxRGBA(screen, m_vSquaresIT->GetX(), m_vSquaresIT->GetY(), m_vSquaresIT->GetX()+Square::GetSize(), m_vSquaresIT->GetY()+Square::GetSize(), r, g, b, 255);
		//rectangleRGBA(screen, m_vSquaresIT->GetX(), m_vSquaresIT->GetY(), m_vSquaresIT->GetX()+Square::GetSize(), m_vSquaresIT->GetY()+Square::GetSize(), 0, 0, 0, 255);

		sclip.x = m_vSquaresIT->GetTilePicPos() * Square::GetSize();
		sclip.y = 0; sclip.w = Square::GetSize(); sclip.h = Square::GetSize();
		dclip.x = m_vSquaresIT->GetX(); dclip.y = m_vSquaresIT->GetY();
		dclip.w = Square::GetSize(); dclip.h = Square::GetSize();
		SDL_BlitSurface(GetMap(), &sclip, screen, &dclip);
		//rectangleRGBA(screen, m_vSquaresIT->GetX(), m_vSquaresIT->GetY(), m_vSquaresIT->GetX()+Square::GetSize(), m_vSquaresIT->GetY()+Square::GetSize(), 0, 0, 0, 255);
	}
}

void Grid::AddSquare(int r, int c, int x, int y, int tpp)
{
	Square tempSquare;
	tempSquare.Init(r, c, x, y, 32, tpp);
	m_vSquares.push_back(tempSquare);
}

Square* Grid::GetSquare(int x, int y)
{
	for (m_vSquaresIT = m_vSquares.begin(); m_vSquaresIT != m_vSquares.end(); m_vSquaresIT++)
	{
		if ((m_vSquaresIT->GetCol() == static_cast<int>(x / Square::GetSize())) && m_vSquaresIT->GetRow() == static_cast<int>((y / Square::GetSize())))
		{
			return &(*m_vSquaresIT);
		}
	}

	return &(*m_vSquares.begin());
}

Square* Grid::GetSquareFromRC(int x, int y)
{
	for (m_vSquaresIT = m_vSquares.begin(); m_vSquaresIT != m_vSquares.end(); m_vSquaresIT++)
	{
		if (m_vSquaresIT->GetCol() == x && m_vSquaresIT->GetRow() == y)
		{
			return &(*m_vSquaresIT);
		}
	}

	return &(*m_vSquares.begin());
}

void Grid::SetMap(string sMapLoc)
{
	m_pMap = SDL_LoadBMP(sMapLoc.c_str());
	SDL_SetColorKey(m_pMap, SDL_SRCCOLORKEY, SDL_MapRGB(m_pMap->format, 255, 0, 255));
}
SDL_Surface* Grid::GetMap()
{
	return m_pMap;
}