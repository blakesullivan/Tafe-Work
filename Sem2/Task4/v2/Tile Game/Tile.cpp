//Blake Sullivan - Tile.cpp
#include "Tile.h"

vector<int> Tile::m_viPass;

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

	SetPassable(GetPass(pp));
	
	//if (iTemp == 0)
	//{SetPassable(true);}
	//else
	//{SetPassable(false);}
}
void Tile::SetPassable(int p)
{
	m_iPassable = p;
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
int Tile::GetPassable()
{
	return m_iPassable;
}

unsigned int Tile::GetSize()
{
	return MCS_UISIZE;
}

void Tile::SetTilePass()
{
	ifstream PicFile("tileset.txt");
	int iTemp = 0;
	m_viPass.clear();
	while (!PicFile.eof())
	{
		cout << "in loop: ";
		PicFile >> iTemp;
		cout << "iTemp = " << iTemp << endl;
		m_viPass.push_back(iTemp);
	}
}

int Tile::GetPass(int pos)
{
	vector<int>::iterator viPassIT;
	int iCount = 0;
	for (viPassIT = m_viPass.begin(); viPassIT != m_viPass.end(); viPassIT++)
	{
		if (iCount == pos) 
		{
			//cout << "GX: " << GetGridX() << " GY: " << GetGridY() << " Pos: " << pos << " Pass: " << (*viPassIT) << endl;
			return (*viPassIT);
		}
		iCount++;
	}
	
}