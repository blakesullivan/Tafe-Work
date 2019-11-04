//Blake Sullivan - Shapes.cpp
#include "Shapes.h"
extern SDL_Surface *screen;

Shapes::Shapes()
{
}

void Shapes::Init()
{
	switch (GenerateRandomNum(3, 0))
	{
	case 0:
		SetupRectangle();
	break;
	case 1:
		SetupCircle();
	break;
	case 2:
		SetupTriangle();
	break;
	default:
		cout<<"Shouldn't be in here.\n";
	}
}

int Shapes::GenerateRandomNum(int iMaxNum, int iMinNum)
{
	//This function is used to generate a random number between the iMinNum and the iMaxNum
	int iTemp;
	iTemp = (rand() % iMaxNum) + iMinNum;
	//cout<<iTemp<<endl;
	return iTemp;
}

void Shapes::SetupRectangle()
{
	int iX1, iX2, iY1, iY2, iRed, iGreen, iBlue, iAlpha;
	iX1 = GenerateRandomNum(750, 25); //750 because screen 800 width and 25 so it's not ever on the very edges
	iY1 = GenerateRandomNum(550, 25); //550 because screen 600 high and 25 so it's not ever on the very edges
	iX2 = GenerateRandomNum(200, 1) + iX1; //200 so the max size of the rectangle is 200, and 1 so it's always bigger than the first point then + iX1 so it's past the first point
	iY2 = GenerateRandomNum(200, 1) + iY1;
	iRed = GenerateRandomNum(256, 0); //256 because that's how many colours there are
	iGreen = GenerateRandomNum(256, 0);
	iBlue = GenerateRandomNum(256, 0);
	iAlpha = GenerateRandomNum(256, 0);

	//Makes it choose a number between 0 and 1 to do a filled rectangle or a open rectangle
	if (0==GenerateRandomNum(2, 0))
	{DrawFRectangle(iX1, iY1, iX2, iY2, iRed, iGreen, iBlue, iAlpha);}
	else
	{DrawORectangle(iX1, iY1, iX2, iY2, iRed, iGreen, iBlue, iAlpha);}
}
void Shapes::DrawFRectangle(int iX1, int iY1, int iX2, int iY2, int iRed, int iGreen, int iBlue, int iAlpha)
{
	//Uses all of the variables passed to it to draw the filled in box.
	boxRGBA(screen, iX1, iY1, iX2, iY2, iRed, iGreen, iBlue, iAlpha);
}
void Shapes::DrawORectangle(int iX1, int iY1, int iX2, int iY2, int iRed, int iGreen, int iBlue, int iAlpha)
{
	rectangleRGBA(screen, iX1, iY1, iX2, iY2, iRed, iGreen, iBlue, iAlpha);
}

void Shapes::SetupCircle()
{
	int iXo, iYo, iRadX, iRadY, iRed, iGreen, iBlue, iAlpha;
	iXo = GenerateRandomNum(750, 25); //750 because screen 800 width and 25 so it's not ever on the very edges
	iYo = GenerateRandomNum(550, 25); //550 because screen 600 high and 25 so it's not ever on the very edges
	iRadX = GenerateRandomNum(100, 1); //200 so the max size is 200, and 1 so it's always bigger than the first point
	iRadY = GenerateRandomNum(100, 1);
	iRed = GenerateRandomNum(256, 0); //256 because that's how many colours there are
	iGreen = GenerateRandomNum(256, 0);
	iBlue = GenerateRandomNum(256, 0);
	iAlpha = GenerateRandomNum(256, 0);

	//Makes it choose a number between 0 and 1 to do a filled ellipse or a open ellipse
	if (0==GenerateRandomNum(2, 0))
	{DrawFCircle(iXo, iYo, iRadX, iRadY, iRed, iGreen, iBlue, iAlpha);}
	else
	{DrawOCircle(iXo, iYo, iRadX, iRadY, iRed, iGreen, iBlue, iAlpha);}
}
void Shapes::DrawFCircle(int iXo, int iYo, int iRadX, int iRadY, int iRed, int iGreen, int iBlue, int iAlpha)
{
	filledEllipseRGBA(screen, iXo, iYo, iRadX, iRadY, iRed, iGreen, iBlue, iAlpha);
}
void Shapes::DrawOCircle(int iXo, int iYo, int iRadX, int iRadY, int iRed, int iGreen, int iBlue, int iAlpha)
{
	ellipseRGBA(screen, iXo, iYo, iRadX, iRadY, iRed, iGreen, iBlue, iAlpha);
}

void Shapes::SetupTriangle()
{
	int iXo, iYo, iChange1, iChange2, iChange3, iRed, iGreen, iBlue, iAlpha;
	iXo = GenerateRandomNum(750, 25); //750 because screen 800 width and 25 so it's not ever on the very edges
	iYo = GenerateRandomNum(550, 25); //550 because screen 600 high and 25 so it's not ever on the very edges
	iChange1 = GenerateRandomNum(100, 1); //200 so the max size is 200, and 1 so it's always bigger than the first point
	iChange2 = GenerateRandomNum(100, 1);
	iChange3 = GenerateRandomNum(100, 1);
	iRed = GenerateRandomNum(256, 0); //256 because that's how many colours there are
	iGreen = GenerateRandomNum(256, 0);
	iBlue = GenerateRandomNum(256, 0);
	iAlpha = GenerateRandomNum(256, 0);

	//Makes it choose a number between 0 and 1 to do a filled triangle or a open triangle
	if (0==GenerateRandomNum(2, 0))
	{DrawFTriangle(iXo, iYo, iChange1, iChange2, iChange3, iRed, iGreen, iBlue, iAlpha);}
	else
	{DrawOTriangle(iXo, iYo, iChange1, iChange2, iChange3, iRed, iGreen, iBlue, iAlpha);}
}
void Shapes::DrawFTriangle(int iXo, int iYo, int iChange1, int iChange2, int iChange3, int iRed, int iGreen, int iBlue, int iAlpha)
{
	filledTrigonRGBA(screen, iXo, iYo - iChange1, iXo - iChange2, iYo + iChange2, iXo + iChange3, iYo + iChange3, iRed, iGreen, iBlue, iAlpha);
}
void Shapes::DrawOTriangle(int iXo, int iYo, int iChange1, int iChange2, int iChange3, int iRed, int iGreen, int iBlue, int iAlpha)
{
	trigonRGBA(screen, iXo, iYo - iChange1, iXo - iChange2, iYo + iChange2, iXo + iChange3, iYo + iChange3, iRed, iGreen, iBlue, iAlpha);
}