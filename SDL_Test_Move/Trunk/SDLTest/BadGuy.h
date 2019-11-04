//Badguy.h
#ifndef BadGuy_H
#define BadGuy_H
#include "SDL.h"
#include "SDL_gfXPrimitives.h" 
#include <math.h>
extern SDL_Surface *screen;
class BadGuy
{
private:
	float iXo,iYo,fRad,Deg,fDeg, iXNew, iYNew;
	float iX1, iX2, iX3, iY1, iY2, iY3, dx, dy;
	int iMov;
	bool alive;

	struct boxXY
	{
		float x;
		float y;
		float size;
	};
	boxXY pos;

public:
	BadGuy();
	void init(float, float);
	//void Move(char);
	void Draw();
	void Face(float, float);
	void Move();
	void SetLife(bool);
	bool GetLife();

	//boxXY GetBPos();
	
	float GetPosX();
	float GetPosY();
	float GetPosSize();
};

#endif