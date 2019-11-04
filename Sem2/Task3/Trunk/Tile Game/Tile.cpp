//Blake Sullivan - Tile.cpp
#include "Tile.h"

Tile::Tile()
{
	SetX(0);
	SetY(0);
	SetGridX(0);
	SetGridY(0);
	SetPicPos(0);
	SetPassable(false);
}

void Tile::Init(unsigned int x, unsigned int y, unsigned int pp, unsigned int gx, unsigned int gy)
{
	SetX(x);
	SetY(y);
	SetGridX(gx);
	SetGridY(gy);
	SetPicPos(pp);
}

void Tile::SetX(unsigned int x)
{
	m_uiX = x;
}
void Tile::SetY(unsigned int y)
{
	m_uiY = y;
}
void Tile::SetGridX(unsigned int gx)
{
	m_uiGridX = gx;
}
void Tile::SetGridY(unsigned int gy)
{
	m_uiGridY = gy;
}
void Tile::SetPicPos(unsigned int pp)
{
	m_uiPicPos = pp;

	ifstream PicFile("tileset.txt");
	int iTemp;
	for (int i = 0; i <= pp; i++)
	{PicFile >> iTemp;}

	if (iTemp == 0)
	{SetPassable(false);}
	else
	{SetPassable(true);}
}
void Tile::SetPassable(bool p)
{
	m_bPassable = p;
}

unsigned int Tile::GetX()
{
	return m_uiX;
}
unsigned int Tile::GetY()
{
	return m_uiY;
}
unsigned int Tile::GetGridX()
{
	return m_uiGridX;
}
unsigned int Tile::GetGridY()
{
	return m_uiGridY;
}
unsigned int Tile::GetPicPos()
{
	return m_uiPicPos;
}
bool Tile::GetPassable()
{
	return m_bPassable;
}

unsigned int Tile::GetSize()
{
	return MCS_UISIZE;
}