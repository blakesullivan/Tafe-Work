//Baddy.h
#ifndef BADDY_H
#define BADDY_H
#include "SDL.h"
#include "SDL_gfxPrimitives.h" 
extern SDL_Surface *screen;

class Baddy
{
private:
	float fXo,fYo,fX1,fY1,fX2,fY2,fX3,fY3;
	bool live;
public:
	Baddy();
	void setStartPos(float, float);
	void Draw();
	float getSquareX();
	float getSquareY();
	float getSize();
	float getLife();
	void setLife(bool);
	
};

#endif