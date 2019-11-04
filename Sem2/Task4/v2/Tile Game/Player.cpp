//Blake Sullivan - Player.cpp
#include "Player.h"

Player::Player()
{
	SetX(0);
	SetY(0);
	SetGridX(0);
	SetGridY(0);
	SetPicRow(0);
	SetPicCol(0);
}

void Player::Init(float x, float y, int r, int c,int gx, int gy)
{
	SetX(x);
	SetY(y);
	SetGridX(gx);
	SetGridY(gy);
	SetPicRow(r);
	SetPicCol(c);
}

void Player::SetX(float x)
{
	m_fX = x;
}
void Player::SetY(float y)
{
	m_fY = y;
}
void Player::SetGridX(int gx)
{
	m_iGridX = gx;
}
void Player::SetGridY(int gy)
{
	m_iGridY = gy;
}
void Player::SetPicRow(int r)
{
	m_iPicRow = r;
}
void Player::SetPicCol(int c)
{
	m_iPicCol = c;
}

float Player::GetX()
{
	return m_fX;
}
float Player::GetY()
{
	return m_fY;
}
int Player::GetGridX()
{
	return m_iGridX;
}
int Player::GetGridY()
{
	return m_iGridY;
}
int Player::GetPicRow()
{
	return m_iPicRow;
}
int Player::GetPicCol()
{
	return m_iPicCol;
}

unsigned int Player::GetSize()
{
	return CS_UISIZE;
}