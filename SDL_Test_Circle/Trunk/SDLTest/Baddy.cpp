
#include "Baddy.h"
Baddy::Baddy(): live(true)
{
	fXo=0;
	fYo=0;
	fX1=fXo;
	fY1=fYo-10;
	fX2=fXo-10;
	fY2=fYo+10;
	fX3=fXo+10; 
	fY3=fYo+10;
}

void Baddy::setStartPos(float x, float y)
{
	fXo=x;
	fYo=y;
	fX1=fXo;
	fY1=fYo-10;
	fX2=fXo-10;
	fY2=fYo+10;
	fX3=fXo+10; 
	fY3=fYo+10;
}
float Baddy::getSquareX()
{
	return fXo;
}
float Baddy::getSquareY()
{
	return fYo;
}
float Baddy::getSize()
{
	return 8;
}
float Baddy::getLife()
{
	return live;
}
void Baddy::setLife(bool liv)
{
	live=liv;
}


void Baddy::Draw()
{
	if(live == true)
	{
		filledTrigonRGBA(screen,fX1, fY1,fX2,fY2,fX3,fY3,255, 223, 0, 255);
		ellipseRGBA(screen,fXo, fYo,9,9,255, 0, 0, 255);
	}
}