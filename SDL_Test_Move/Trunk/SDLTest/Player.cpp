//Player.cpp
#include "Player.h"
Player::Player(): iMov(5),fRad(10)
{
	iXo=400;
	iYo=300;

	pos.x=iXo;
	pos.y=iYo;
	pos.size=9;
}

void Player::Init(float sx, float sy, int myR, int myG, int myB, int Mov)
{
	fXo=sx;
	fYo=sy;
	fX1=fXo;
	fY1=fYo-10;
	fX2=fXo-10;
	fY2=fYo+10;
	fX3=fXo+10;
	fY3=fYo+10;
	iMov=Mov;
	dx=0;
	dy=0;
	fXNew=0;
	fYNew=0;
	Deg=90;
	fDeg=0;
	mR=myR;
	mG=myG;
	mB=myB;
	bAlive=true;
}

void Player::Move(char cMove)
{
	switch (cMove)
	{
	case 'u':
		//fYo-=iMov;
		dx=iMov*sin(fDeg);
		dy=iMov*cos(fDeg);
		fXo+=dx;
		fYo-=dy;
		fX1+=dx;
		fY1-=dy;
		fX2+=dx;
		fY2-=dy;
		fX3+=dx;
		fY3-=dy;
	break;
	case 'd':
		//fYo+=iMov;
		dx=iMov*sin(fDeg);
		dy=iMov*cos(fDeg);
		fXo-=dx;
		fYo+=dy;
		fX1-=dx;
		fY1+=dy;
		fX2-=dx;
		fY2+=dy;
		fX3-=dx;
		fY3+=dy;
	break;
	case 'l':
		//Deg+=0.05;
		Rotate(0.05);
		//fXo-=iMov;
	break;
	case 'r':
		//Deg-=0.05;
		Rotate(-0.05);
		//fXo+=iMov;
	break;
	default:
	break;
	}

	pos.x=fXo;
	pos.y=fYo;
}

void Player::Rotate(float fTemp)
{
	//Sets variables around the points
	Deg += fTemp;
	fDeg = Deg;
	fDeg = (90*M_PI/180)-fDeg;
	fX1=fXo;
	fY1=fYo-10;
	fX2=fXo-10;
	fY2=fYo+10;
	fX3=fXo+10;
	fY3=fYo+10;

	//Roatates here using a formula
	fXNew = fXo + ((fX1 - fXo) * cos(fDeg)) - ((fY1 - fYo) * sin(fDeg));
	fYNew = fYo + ((fY1 - fYo) * cos(fDeg)) + ((fX1 - fXo) * sin(fDeg));
	fX1 = fXNew;
	fY1 = fYNew;

	fXNew = fXo + ((fX2 - fXo) * cos(fDeg)) - ((fY2 - fYo) * sin(fDeg));
	fYNew = fYo + ((fY2 - fYo) * cos(fDeg)) + ((fX2 - fXo) * sin(fDeg));
	fX2 = fXNew;
	fY2 = fYNew;

	fXNew = fXo + ((fX3 - fXo) * cos(fDeg)) - ((fY3 - fYo) * sin(fDeg));
	fYNew = fYo + ((fY3 - fYo) * cos(fDeg)) + ((fX3 - fXo) * sin(fDeg));
	fX3 = fXNew;
	fY3 = fYNew;
}

void Player::Draw()
{
	filledTrigonRGBA(screen, fX1, fY1, fX2, fY2, fX3, fY3, mR, mG, mB, 255);
	ellipseRGBA(screen, pos.x, pos.y, pos.size, pos.size, 0, 0, 0, 255);
}

//void Player::Draw()
//{
//	//rectangleRGBA(screen, pos.x, pos.y, pos.x + pos.size, pos.y + pos.size, 0, 0, 255, 255);
//	filledEllipseRGBA(screen, iXo, iYo, fRad, fRad, 255, 0, 0, 255);
//}

float Player::GetIXo()
{
	return pos.x;
}
float Player::GetIYo()
{
	return pos.y;
}
float Player::GetIX1()
{
	return fX1;
}
float Player::GetIY1()
{
	return fY1;
}
float Player::GetDeg()
{
	return fDeg;
}
bool Player::GetAlive()
{
	return bAlive;
}

int Player::GetSize()
{
	return pos.size;
}
//square
//bool Player::CollisionCheck(float pX, float pY, float pS)
//{
//	if (pos.x > pX + pS)
//		return false;
//
//	if (pos.x + pos.size < pX)
//		return false;
//
//	if (pos.y > pY + pS)
//		return false;
//
//	if (pos.y + pos.size < pY)
//		return false;
//
//	return true;
//}

//circle
bool Player::CollisionCheck(float pX, float pY, float pS)
{
	if (sqrt(pow((pX-pos.x),2)+pow((pY-pos.y),2)) <= pos.size + pS)
	{
		return true;
	}
	else
		return false;
}