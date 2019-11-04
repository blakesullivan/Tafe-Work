//Blake Sullivan - Player
#include "Player.h"

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
}

void Player::Face(float px, float py)
{
	//Sets variables around the points
	Deg = atan((px-fXo)/(fYo-py))*180/M_PI;
	//Deg = atan2((px-fXo),(py-fYo))*180/M_PI;
	
	if (py > fYo)
	{
		Deg+=180;
	}
	fDeg = Deg;
	fDeg = (fDeg*M_PI/180);

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
	case 'v':
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
}

void Player::Draw()
{
	filledEllipseRGBA(screen, fX1, fY1, 5, 5, mB, mG, mR, 255);
	filledTrigonRGBA(screen, fX1, fY1, fX2, fY2, fX3, fY3, mR, mG, mB, 255);
}

float Player::GetXo()
{
	return fXo;
}

float Player::GetYo()
{
	return fYo;
}