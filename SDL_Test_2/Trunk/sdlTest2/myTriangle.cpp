//Blake Sullivan - myTriangle
#include "myTriangle.h"
#include <iostream>

myTriangle::myTriangle(): fX1(0), fX2(0), fX3(0), fY1(0), fY2(0), fY3(0)
{
}

//Deconstructor
myTriangle::~myTriangle()
{
	//Do Stuff
	std::cout<<"Bye\n";
}

void myTriangle::setParam(float x1, float y1, float x2, float y2, float x3, float y3)
{
	fX1=x1;
	fY1=y1;
	fX2=x2;
	fY2=y2;
	fX3=x3;
	fY3=y3;
}

void myTriangle::Draw()
{
	filledTrigonRGBA(screen, fX1, fY1, fX2, fY2, fX3, fY3, 255, 223, 0, 255);
}