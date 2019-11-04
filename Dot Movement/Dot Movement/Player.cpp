//Blake Sullivan - Player.cpp
#include "Player.h"

Player::Player()
{
	SetID(-1);
	SetX(0);
	SetY(0);
	SetSpeed(0);
	SetSize(0);
	SetColour(0, 0, 0, 255);
}

void Player::Init(char id, float x, float y, float s, int size)
{
	SetID(id);
	SetX(x);
	SetY(y);
	SetSpeed(s);
	SetSize(size);
}

void Player::MovePlayer(char cDir, float fdt)
{
	//cout << "Getting into MovePlayer\n";
	float tempX = 0, tempY = 0;
	switch (cDir)
	{
	case 'u':
		tempX = GetX();
		tempY = GetY() - (GetSpeed() * fdt);
	break;
	case 'd':
		tempX = GetX();
		tempY = GetY() + (GetSpeed() * fdt);
	break;
	case 'l':
		tempX = GetX() - (GetSpeed() * fdt);
		tempY = GetY();
	break;
	case 'r':
		tempX = GetX() + (GetSpeed() * fdt);
		tempY = GetY();
	break;
	default:
		cout << "Shouldn't move this direction!\n";
	}
	SetX(tempX);
	SetY(tempY);
}

void Player::SetID(char id)
{
	mc_ID = id;
}
void Player::SetX(float x)
{
	mf_X = x;
}
void Player::SetY(float y)
{
	mf_Y = y;
}
void Player::SetSpeed(float s)
{
	mf_Speed = s;
}
void Player::SetSize(int size)
{
	mi_Size = size;
}
void Player::SetColour(int r, int g, int b, int a)
{
	mpc_Colour.iRed = r;
	mpc_Colour.iGreen = g;
	mpc_Colour.iBlue = b;
	mpc_Colour.iAlpha = a;
}

char Player::GetID()
{
	return mc_ID;
}
float Player::GetX()
{
	return mf_X;
}
float Player::GetY()
{
	return mf_Y;
}
float Player::GetSpeed()
{
	return mf_Speed;
}
int Player::GetSize()
{
	return mi_Size;
}
int Player::GetRed()
{
	return mpc_Colour.iRed;
}
int Player::GetGreen()
{
	return mpc_Colour.iGreen;
}
int Player::GetBlue()
{
	return mpc_Colour.iBlue;
}
int Player::GetAlpha()
{
	return mpc_Colour.iAlpha;
}