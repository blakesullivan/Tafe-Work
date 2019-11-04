//Bad Guy
#include "BadGuy.h"
BadGuy::BadGuy(): iMov(1),fRad(10)
{
	iXo=0;
	iYo=0;
	iX1=0;
	iY1=0;
	iX2=0;
	iY2=0;
	iX3=0;
	iY3=0;
	pos.x=0;
	pos.y=0;
	pos.size=0;
	alive=true;
	Deg=90;
	fDeg=0;
	dx=0;
	dy=0;
}

void BadGuy::init(float iXs, float iYs)
{
	iXo=iXs;
	iYo=iYs;
	iX1=iXo;
	iY1=iYo-10;
	iX2=iXo-10;
	iY2=iYo+10;
	iX3=iXo+10;
	iY3=iYo+10;
	alive=true;

	//square
	/*pos.x=iXo-10;
	pos.y=iYo-10;
	pos.size=20;*/

	//circle
	pos.x=iXo;
	pos.y=iYo+1;
	pos.size=9;	
}

void BadGuy::Draw()
{
	filledTrigonRGBA(screen, iX1, iY1, iX2, iY2, iX3, iY3, 0, 255, 0, 255);
	//rectangleRGBA(screen, pos.x, pos.y, pos.x+pos.size, pos.y+pos.size, 0, 0, 255, 255);
	ellipseRGBA(screen, pos.x, pos.y, pos.size, pos.size, 0, 0, 255, 255);
}

void BadGuy::Face(float px, float py)
{
	//Sets variables around the points
	Deg = atan((px-iXo)/(iYo-py))*180/M_PI;
	//Deg = atan2((px-iXo),(py-iYo))*180/M_PI;
	
	if (py > iYo)
	{
		Deg+=180;
	}
	fDeg = Deg;
	fDeg = (fDeg*M_PI/180);

	iX1=iXo;
	iY1=iYo-10;
	iX2=iXo-10;
	iY2=iYo+10;
	iX3=iXo+10;
	iY3=iYo+10;

	//Roatates here using a formula
	iXNew = iXo + ((iX1 - iXo) * cos(fDeg)) - ((iY1 - iYo) * sin(fDeg));
	iYNew = iYo + ((iY1 - iYo) * cos(fDeg)) + ((iX1 - iXo) * sin(fDeg));
	iX1 = iXNew;
	iY1 = iYNew;

	iXNew = iXo + ((iX2 - iXo) * cos(fDeg)) - ((iY2 - iYo) * sin(fDeg));
	iYNew = iYo + ((iY2 - iYo) * cos(fDeg)) + ((iX2 - iXo) * sin(fDeg));
	iX2 = iXNew;
	iY2 = iYNew;

	iXNew = iXo + ((iX3 - iXo) * cos(fDeg)) - ((iY3 - iYo) * sin(fDeg));
	iYNew = iYo + ((iY3 - iYo) * cos(fDeg)) + ((iX3 - iXo) * sin(fDeg));
	iX3 = iXNew;
	iY3 = iYNew;
}
void BadGuy::Move()
{
	dx=iMov*sin(fDeg);
	dy=iMov*cos(fDeg);
	iXo+=dx;
	iYo-=dy;
	iX1+=dx;
	iY1-=dy;
	iX2+=dx;
	iY2-=dy;
	iX3+=dx;
	iY3-=dy;

	pos.x=iXo;
	pos.y=iYo+1;
	pos.size=9;	
}

void BadGuy::SetLife(bool live)
{
	alive=live;
}

bool BadGuy::GetLife()
{
	return alive;
}

//boxXy BadGuy::GetBPos()
//{
//	return pos;
//}

float BadGuy::GetPosX()
{
	return pos.x;
}
float BadGuy::GetPosY()
{
	return pos.y;
}
float BadGuy::GetPosSize()
{
	return pos.size;
}