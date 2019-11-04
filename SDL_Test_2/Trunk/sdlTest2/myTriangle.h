//Blake Sullivan - myTriangle.h
#ifndef MYTRIANGLE_H
#define MYTRIANGLE_H
#include "SDL.h"   /* All SDL App's need this */
#include "SDL_gfxPrimitives.h" 
//Makes the header know that the variable screen will be declared later in the compile, but we want to use it now.
extern SDL_Surface *screen;

class myTriangle
{
private:
	float fX1, fY1, fX2, fY2, fX3, fY3;

public:
	myTriangle();
	~myTriangle(); //deconstructor
	void setParam(float, float, float, float, float, float);
	void Draw();
};

#endif