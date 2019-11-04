//Blake Sullivan - Player
#include "Player.h"
// iMov(5), fRad(10)
Player::Player(): iMov(5), dx(0), dy(0), fXNew(0), fYNew(0), Deg(90)//, i2Mov(5), d2x(0), d2y(0), f2XNew(0), f2YNew(0)
{
	fXo=400;
	fYo=300;
	fX1=fXo;
	fY1=fYo-10;
	fX2=fXo-10;
	fY2=fYo+10;
	fX3=fXo+10;
	fY3=fYo+10;

	/*f2Xo=300;
	f2Yo=400;
	f2X1=f2Xo;
	f2Y1=f2Yo-10;
	f2X2=f2Xo-10;
	f2Y2=f2Yo+10;
	f2X3=f2Xo+10;
	f2Y3=f2Yo+10;*/
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

//void Player::R2otate()
//{
//	//Sets variables around the points
//	f2Deg = D2eg;
//	f2Deg = (90*M_PI/180)-f2Deg;
//	f2X1=f2Xo;
//	f2Y1=f2Yo-10;
//	f2X2=f2Xo-10;
//	f2Y2=f2Yo+10;
//	f2X3=f2Xo+10;
//	f2Y3=f2Yo+10;
//
//	//Roatates here using a formula
//	f2XNew = f2Xo + ((f2X1 - f2Xo) * cos(f2Deg)) - ((f2Y1 - f2Yo) * sin(f2Deg));
//	f2YNew = f2Yo + ((f2Y1 - f2Yo) * cos(f2Deg)) + ((f2X1 - f2Xo) * sin(f2Deg));
//	f2X1 = f2XNew;
//	f2Y1 = f2YNew;
//
//	f2XNew = f2Xo + ((f2X2 - f2Xo) * cos(f2Deg)) - ((f2Y2 - f2Yo) * sin(f2Deg));
//	f2YNew = f2Yo + ((f2Y2 - f2Yo) * cos(f2Deg)) + ((f2X2 - f2Xo) * sin(f2Deg));
//	f2X2 = f2XNew;
//	f2Y2 = f2YNew;
//
//	f2XNew = f2Xo + ((f2X3 - f2Xo) * cos(f2Deg)) - ((f2Y3 - f2Yo) * sin(f2Deg));
//	f2YNew = f2Yo + ((f2Y3 - f2Yo) * cos(f2Deg)) + ((f2X3 - f2Xo) * sin(f2Deg));
//	f2X3 = f2XNew;
//	f2Y3 = f2YNew;
//}

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

	//case 'w':
	//	//fYo-=iMov;
	//	d2x=5*sin(f2Deg);
	//	d2y=5*cos(f2Deg);
	//	f2Xo+=d2x;
	//	f2Yo-=d2y;
	//	f2X1+=d2x;
	//	f2Y1-=d2y;
	//	f2X2+=d2x;
	//	f2Y2-=d2y;
	//	f2X3+=d2x;
	//	f2Y3-=d2y;
	//break;
	//case 's':
	//	//fYo+=iMov;
	//	d2x=5*sin(f2Deg);
	//	d2y=5*cos(f2Deg);
	//	f2Xo-=d2x;
	//	f2Yo+=d2y;
	//	f2X1-=d2x;
	//	f2Y1+=d2y;
	//	f2X2-=d2x;
	//	f2Y2+=d2y;
	//	f2X3-=d2x;
	//	f2Y3+=d2y;
	//break;
	//case 'a':
	//	D2eg+=0.05;
	//	R2otate();
	//	//fXo-=iMov;
	//break;
	//case 'd':
	//	D2eg-=0.05;
	//	R2otate();
	//	//fXo+=iMov;
	//break;
	default:
	break;
	}
}

void Player::Draw()
{
	filledEllipseRGBA(screen, fX1, fY1, 5, 5, 255, 223, 0, 255);
	filledTrigonRGBA(screen, fX1, fY1, fX2, fY2, fX3, fY3, 255, 0, 0, 255);

	/*filledEllipseRGBA(screen, f2X1, f2Y1, 5, 5, 150, 223, 0, 255);
	filledTrigonRGBA(screen, f2X1, f2Y1, f2X2, f2Y2, f2X3, f2Y3, 0, 0, 255, 255);*/
}