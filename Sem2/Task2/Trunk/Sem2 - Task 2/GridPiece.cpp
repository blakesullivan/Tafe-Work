//Blake Sullivan - GridPiece.cpp
#include "GridPiece.h"

GridPiece::GridPiece()
{
	Init(0, 0, 0, false, 0, 0);
}

GridPiece::~GridPiece()
{
	//something should go in here
}

void GridPiece::Draw(SDL_Surface s, SDL_Surface g)
{
	SDL_Rect sclip, dclip;
	sclip.x = m_iPicPos; sclip.y = 0; sclip.w = scm_iGridSize; sclip.h = scm_iGridSize;
	dclip.x = m_iX; dclip.y = m_iY; dclip.w = scm_iGridSize; dclip.h = scm_iGridSize;
	SDL_BlitSurface(&g, &sclip, &s, &dclip);
}

void GridPiece::SwapCell()
{
	if (m_bAlive == true)
		{SetAlive(false);}
	else
		{SetAlive(true);}
	SetChange(false);
}

void GridPiece::Init(const int x, const int y, const int p, const bool a, const int xp, const int yp)
{
	SetX(x);
	SetY(y);
	SetPicPos(p);
	SetAlive(a);
	SetXPos(xp);
	SetYPos(yp);
	SetChange(false);
}
void GridPiece::SetX(const int x)
{
	m_iX = x;
}
void GridPiece::SetY(const int y)
{
	m_iY = y;
}
void GridPiece::SetXPos(const int xp)
{
	m_iXPos = xp;
}
void GridPiece::SetYPos(const int yp)
{
	m_iYPos = yp;
}
void GridPiece::SetPicPos(const int p)
{
	m_iPicPos = p;
}
void GridPiece::SetAlive(const bool a)
{
	m_bAlive = a;
	if (m_bAlive == true)
		{SetPicPos(scm_iGridSize);}	
	else
		{SetPicPos(0);}
}
void GridPiece::SetChange(const bool c)
{
	m_bChange = c;
}
int GridPiece::GetX() const
{
	return m_iX;
}
int GridPiece::GetY() const
{
	return m_iY;
}
int GridPiece::GetPicPos() const
{
	return m_iPicPos;
}
bool GridPiece::GetAlive() const
{
	return m_bAlive;
}
bool GridPiece::GetChange() const
{
	return m_bChange;
}
int GridPiece::GetXPos() const
{
	return m_iXPos;
}
int GridPiece::GetYPos() const
{
	return m_iYPos;
}